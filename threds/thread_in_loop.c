/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_in_loop.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agorski <agorski@student.42warsaw.pl>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 14:12:30 by agorski           #+#    #+#             */
/*   Updated: 2024/12/26 14:14:30 by agorski          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct s_philo
{
	int				*x;
	pthread_mutex_t	*mutex;
}					t_philo;

void	*f(void *arg)
{
	t_philo	*philo;
	int		i;

	philo = (t_philo *)arg;
	while (i < 1000000)
	{
		pthread_mutex_lock(philo->mutex);
		(*philo->x)++;
		pthread_mutex_unlock(philo->mutex);
		i++;
	}
	return (NULL);
}

int	main(void)
{
	t_philo			philo;
	pthread_mutex_t	mutex;
	int				x;
	int				i;

	x = 0;
	i = 0;
	philo.x = &x;
	philo.mutex = &mutex;
	pthread_mutex_init(philo.mutex, NULL);
	pthread_t th[8]; // declare a thread
	while (i < 8)
	{
		if (pthread_create(&th[i], NULL, (void *)f, &philo) != 0)
			return (1);
		printf("threads [%d] started\n", i);
		i++;
	}
	i = 0;
	while (i < 8)
	{
		if (pthread_join(th[i], NULL) != 0)
			return (3);
		printf("threads [%d] finished execution\n", i);
		i++;
	}
	pthread_mutex_destroy(philo.mutex);
	printf("end of threds x=%d\n", *(philo.x));
	return (0);
}
