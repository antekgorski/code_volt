/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pthread_is.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agorski <agorski@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 14:42:39 by agorski           #+#    #+#             */
/*   Updated: 2024/12/27 14:53:03 by agorski          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/syscall.h>

#define THREAD_NUM 2

int		primes[10] = {1, 3, 5, 7, 9, 13, 17, 20, 23, 29};

void	*rutines(void *arg)
{
    pthread_t id = pthread_self();
    printf("Thread id: %ul\n", id);
    printf("Thread id: %ul\n", (pid_t) syscall(SYS_gettid));
}

int	main(void)
{
	pthread_t th[THREAD_NUM];
	int i;
	for (i = 0; i < THREAD_NUM; i++)
	{
		if (pthread_create(&th[i], NULL, rutines, NULL) != 0)
			perror("pthread_create");
      //  printf("%ul\n", th[i]);
	}
	for (i = 0; i < THREAD_NUM; i++)
	{
		if (pthread_join(th[i], NULL) != 0)
			perror("pthread_join");
	}
	return (0);
}