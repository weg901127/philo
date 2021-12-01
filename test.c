/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gilee <gilee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 09:58:28 by gilee             #+#    #+#             */
/*   Updated: 2021/12/01 10:55:37 by gilee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main()
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
