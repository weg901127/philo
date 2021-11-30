/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gilee <gilee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 04:54:02 by gilee             #+#    #+#             */
/*   Updated: 2021/12/01 05:35:13 by gilee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h" 
#include "srcs/stack/array_stack/stack.h"

void init(t_philo *pl)
{
	int			i;
	t_StackNode	tmp;

	pl->philo = createLinkedStack();
	pl->eat_cnt = (int *)malloc(NUM_PHILS * sizeof(int));
	for (i = 0; i < NUM_PHILS; i++)
	{
		tmp.data = NUM_PHILS - 1 - i;
		pl->state[i] = THINKING;
		(pl->eat_cnt)[i] = 3;
		pushLS(pl->philo, tmp);
		pthread_cond_init(&(pl->cond_vars[i]), NULL);
	}
	pthread_mutex_init(&(pl->mutex_lock), NULL);
	srand(time(0));
}

int	leftOf(int i)
{
	return (i + NUM_PHILS - 1) % NUM_PHILS;
}

int	rightOf(int i)
{
	return (i + 1) % NUM_PHILS;
}

void	think(int id)
{
	printf("%d: Now, I'm thinking... \n", id);
	usleep((1 + rand() % 50) * 10000);
}

void	eat(t_philo *pl, int id)
{
	pthread_mutex_lock(&(pl->mutex_lock));
	if ((pl->eat_cnt)[id] != 0)
	{
		printf("%d: Now, I'm eating...\n", id);
		((pl->eat_cnt)[id])--;
		usleep((1 + rand() % 50) * 10000);
		pl->state[id] = THINKING;
	}
	pthread_mutex_unlock(&(pl->mutex_lock));
}

void	test(t_philo *pl, int who)
{
	if ((pl->state[who] == HUNGRY ||
		pl->state[who] == DONE) &&
		pl->state[leftOf(who)] != EATING &&
		pl->state[rightOf(who)] != EATING)
	{
		if (pl->state[who] == HUNGRY)
			pl->state[who] = EATING;
		if (pl->state[who] == DONE)
			pl->state[who] = DONE;
		pthread_cond_signal(&(pl->cond_vars[who]));
	}
}

void	pickup(t_philo *pl, int id)
{
	pthread_mutex_lock(&(pl->mutex_lock));

	pl->state[id] = HUNGRY;
	test(pl, id);
	while (pl->state[id] != EATING && pl->state[id] != DONE)
		pthread_cond_wait(&(pl->cond_vars[id]), &(pl->mutex_lock));
	pthread_mutex_unlock(&(pl->mutex_lock));
}

void	putdown(t_philo *pl, int id)
{
	pthread_mutex_lock(&(pl->mutex_lock));

	pl->state[id] = THINKING;
	test(pl, leftOf(id));
	test(pl, rightOf(id));

	pthread_mutex_unlock(&(pl->mutex_lock));
}

void	done(t_philo *pl, int id)
{
	pthread_mutex_lock(&(pl->mutex_lock));

	if (pl->eat_cnt[id] == 0)
		pl->state[id] = DONE;
	else
		pl->state[id] = THINKING;
	test(pl, leftOf(id));
	test(pl, rightOf(id));

	pthread_mutex_unlock(&(pl->mutex_lock));
}

void	die(t_philo *pl, int id)
{
	pthread_mutex_lock(&(pl->mutex_lock));
	if (pl->state[id] == DONE)
	{
		printf("%d: Now, I'm died\n", id);
		test(pl, leftOf(id));
		test(pl, rightOf(id));
		pthread_exit(NULL);
	}
	pthread_mutex_unlock(&(pl->mutex_lock));
}

void	*philo(void *param)
{
	int			id;
	t_StackNode	*tmp;
	
	tmp = popLS(((t_philo *)param)->philo);
	id = tmp->data;
	free(tmp);
	printf("%d\n", id);
	while (TRUE)
	{
		think(id);
		pickup((t_philo *)param, id);
		eat((t_philo *)param, id);
		done((t_philo *)param, id);
		die((t_philo *)param, id);
		//putdown((t_philo *)param, id);
	}
}


int main()
{
	int i;
	pthread_t tid[5];
	t_philo *pl;

	pl = (t_philo *)malloc(1 * sizeof(t_philo));
	init(pl);
	for (i = 0; i < NUM_PHILS; i++)
		pthread_create(&tid[i], NULL, philo, (void *)pl);
	for (i = 0; i < NUM_PHILS; i++)
		pthread_join(tid[i], NULL);
	return 0;
}
