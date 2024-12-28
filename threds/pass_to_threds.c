/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pass_to_threds.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agorski <agorski@student.42warsaw.pl>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 21:11:54 by agorski           #+#    #+#             */
/*   Updated: 2024/12/26 22:20:34 by agorski          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct s_philo
{
	int	*i;
	int	*primes;
}		t_philo;

void	*f(void *arg)
{
	t_philo	*philo;
	int		i;

	philo = (t_philo *)arg;
	i = *philo->i;
	printf("thread value = %d adres = %p prime index= %d\n", i, philo->i,
		philo->primes[i]);
	free(philo->i);
	free(philo);
	return (NULL);
}

int	main(void)
{
	int		i;
	int		primes[8] = {2, 3, 5, 7, 11, 13, 17, 19};
	t_philo	*philo;

	pthread_t th[8]; // declare a thread
	i = 0;
	while (i < 8)
	{
		philo = (t_philo *)malloc(sizeof(t_philo));
		if (philo == NULL)
			return (1);
		philo->primes = primes;
		philo->i = (int *)malloc(sizeof(int));
		if (philo->i == NULL)
			return (2);
		*philo->i = i;
		printf("thread value = %d adres = %p\n", i, philo->i);
		if (pthread_create(&th[i], NULL, (void *)f, philo) != 0)
			{
				free(philo->i);
				free(philo);
				return (3);
			}
		i++;
	}
	i = 0;
	while (i < 8)
	{
		if (pthread_join(th[i], NULL) != 0)
			return (3);
		i++;
	}
	return (0);
}
