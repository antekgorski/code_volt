/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forktest.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agorski <agorski@student.42warsaw.pl>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 14:13:23 by agorski           #+#    #+#             */
/*   Updated: 2024/12/26 14:13:24 by agorski          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int	main(void)
{
	int x = 0;
	int pid;

	pid = fork();
	if (pid == 0)
	{
		x += 5;
		printf("printed by child x=%d\n", x); // printed by child
	}
	// printf("both %d\n", x);//printed by both
	// printf("printed by both after child %d\n", x);//printed by both after child
	if (pid != 0)
	{
		//sleep(3);
        x += 9;
		printf("printed by patent x=%d\n", x);//printed by parent
	}

	waitpid(pid, NULL, 0);
    printf("printed by %d\n", x);//child after child parent after parent
	x += 10;
	printf("printed by %d\n", x);//child after child parent after parent
	return (0);
}