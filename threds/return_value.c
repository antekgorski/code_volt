/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   return_value.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agorski <agorski@student.42warsaw.pl>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 20:19:53 by agorski           #+#    #+#             */
/*   Updated: 2024/12/26 20:46:00 by agorski          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

void	*f()
{
    int value = (rand() % 6) + 1;
    int *result = (int*)malloc(sizeof(int));
    *result = value;
    printf("thread value = %d adres = %p\n", *result, result);
    return ((void *) result);
}

int	main(void)
{
    int *res;
    srand(time(NULL));
	pthread_t	thread1;

	if (pthread_create(&thread1, NULL, (void *)f, NULL) != 0)
		return (1);
	if (pthread_join(thread1, (void **)&res) != 0)
		return (2);
    printf("main value = %d adres = %p\n", *res, res);
    
    free(res);
	return (0);
}
