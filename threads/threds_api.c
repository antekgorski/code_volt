/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threds_api.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agorski <agorski@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 15:40:36 by agorski           #+#    #+#             */
/*   Updated: 2024/12/27 19:28:31 by agorski          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/syscall.h>
#include <unistd.h>

#define THREAD_NUM 8

pthread_mutex_t	mutexfuel;
int				fuel = 100;

void	*rutines(void *arg)
{
	pthread_mutex_lock(&mutexfuel);
	fuel += 100;
	printf("incremented fuel: %d\n", fuel);
	pthread_mutex_unlock(&mutexfuel);
}

int	main(void)
{
	pthread_t	th[THREAD_NUM];
	int			i;

	pthread_mutex_init(&mutexfuel, NULL);
	pthread_mutex_init(&mutexwater, NULL);
	for (i = 0; i < THREAD_NUM; i++)
	{
		if (pthread_create(&th[i], NULL, rutines, NULL) != 0)
			perror("pthread_create");
	}
	for (i = 0; i < THREAD_NUM; i++)
	{
		if (pthread_join(th[i], NULL) != 0)
			perror("pthread_join");
	}
	printf("fuel: %d\n", fuel);
	pthread_mutex_destroy(&mutexfuel);
	return (0);
}
