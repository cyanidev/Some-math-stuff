/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fprime.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afelicia <afelicia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 01:52:04 by afelicia          #+#    #+#             */
/*   Updated: 2023/02/27 02:23:38 by afelicia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	isprime(int n)
{
	int i = 2;

	while(i * i < n)
	{	
		if(n % i == 0)
			return(0);
		i++;
	}
	if(n == 1)
		return(0);
	return(1);
}


int	main(int argc, char **argv)
{
	int	n = 0;
	int 	flag = 0;
	int	start = 0;

	if(argc == 2)
	{	
		n = atoi(argv[1]);
		if(n == 1)
			printf("1");
		start = n;
		n = 2;
		while(n <= start)
		{
			if(isprime(n))	
			{
				while(start % n == 0)
				{	
					if(flag == 0)
					{
						flag = 1;
						printf("%d", n);
					}
					else
						printf("*%d", n);
					start = start / n;
				}
			}	
			n++;
		}

	}
	printf("\n");
}
