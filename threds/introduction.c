/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   introduction.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agorski <agorski@student.42warsaw.pl>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 14:13:18 by agorski           #+#    #+#             */
/*   Updated: 2024/12/26 14:13:19 by agorski          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void	*t1_f(void *arg)
{
	int	*x;

	x = (int *)arg;
	// sleep(3);
	*x += 5;
	printf("x=%d\n", *x);
	return (NULL);
}

void	*t2_f(void *arg)
{
	int	*x;

	x = (int *)arg;
	*x += 10;
	printf("x=%d\n", *x);
	return (NULL);
}

int	main(void)
{
	int x = 0;
	pthread_t thread1; // declare a thread
	pthread_t thread2;
	if (pthread_create(&thread1, NULL, (void *)t1_f, &x) != 0)// create a thread
		return (1);
	if (pthread_create(&thread2, NULL, (void *)t2_f, &x) != 0)
		return (1);
	pthread_join(thread1, NULL); // wait for the thread to finish
	pthread_join(thread2, NULL);
	printf("end of fork x=%d\n", x);
	return (0);
}