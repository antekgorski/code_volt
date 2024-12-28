/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_detath.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agorski <agorski@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 15:25:48 by agorski           #+#    #+#             */
/*   Updated: 2024/12/27 15:31:37 by agorski          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/syscall.h>
#include <unistd.h>

#define THREAD_NUM 2

int		primes[10] = {1, 3, 5, 7, 9, 13, 17, 20, 23, 29};

void	*rutines(void *arg)
{
sleep(1);
printf("finished execiution\n");
}

int	main(void)
{
	pthread_t	th[THREAD_NUM];
	int			i;

	for (i = 0; i < THREAD_NUM; i++)
	{
		if (pthread_create(&th[i], NULL, rutines, NULL) != 0)
			perror("pthread_create");
		pthread_detach(th[i]);
	}
	// for (i = 0; i < THREAD_NUM; i++)
	// {
	// 	if (pthread_join(th[i], NULL) != 0)
	// 		perror("pthread_join");
	// }
	//return (0);
    pthread_exit(NULL);
}
