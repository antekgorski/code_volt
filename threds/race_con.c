/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   race_con.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agorski <agorski@student.42warsaw.pl>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 14:13:11 by agorski           #+#    #+#             */
/*   Updated: 2024/12/26 14:13:12 by agorski          ###   ########.fr       */
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
	t_philo philo;
	pthread_mutex_t mutex;
	int x;
	x = 0;
	philo.x = &x;
	philo.mutex = &mutex;
	pthread_t thread1; // declare a thread
	pthread_t thread2;

	pthread_mutex_init(philo.mutex, NULL);
	if (pthread_create(&thread1, NULL, (void *)f, &philo) != 0)
		// create a thread
		return (1);
	if (pthread_create(&thread2, NULL, (void *)f, &philo) != 0)
		return (2);
	if (pthread_join(thread1, NULL) != 0) // wait for the thread to finish
		return (3);
	if (pthread_join(thread2, NULL) != 0)
		return (4);
	pthread_mutex_destroy(philo.mutex);
	printf("end of threds x=%d\n", *(philo.x));
	return (0);
}