/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_exemple.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agorski <agorski@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 13:58:05 by agorski           #+#    #+#             */
/*   Updated: 2024/12/27 14:38:25 by agorski          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int		primes[10] = {1, 3, 5, 7, 9, 13, 17, 20, 23, 29};

void	*rutines(void *arg)
{
	int	index;
	int	sum;

	index = *(int *)arg;
	sum = 0;
	for (int j = 0; j < 5; j++)
	{
		sum += primes[index + j];
	}
    printf("local sum: %d\n", sum);
	*(int *)arg = sum;
	return (arg);
}

int	main(void)
{
	pthread_t	threads[10];
	int			i;
	int			*a;
	int			global_sum;
	int			*r;

	for (i = 0; i < 2; i++)
	{
		a = malloc(sizeof(int));
		*a = i * 5;
		if (pthread_create(&threads[i], NULL, rutines, a) != 0)
		{
			perror("pthread_create");
			exit(1);
		}
	}
	global_sum = 0;
	for (i = 0; i < 2; i++)
	{
		if (pthread_join(threads[i], (void **) &r) != 0)
		{
			perror("pthread_join");
			exit(1);
		}
		global_sum += *r;
		free(r);
	}
	printf("Suma global: %d\n", global_sum);
	return (0);
}
