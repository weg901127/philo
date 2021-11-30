#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include "srcs/stack/array_stack/stack.h"
#define TRUE 1
#define NUM_PHILS 5

typedef enum state
{
	THINKING,
	HUNGRY,
	EATING,
	DONE
} t_state;

typedef struct s_philo
{
	t_state			state[NUM_PHILS];
	t_LinkedStack	*philo;
	int				*eat_cnt;
	pthread_mutex_t	mutex_lock;
	pthread_cond_t	cond_vars[NUM_PHILS];
}	t_philo;
