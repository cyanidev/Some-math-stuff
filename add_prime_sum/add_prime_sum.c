/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_prime_sum.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afelicia <afelicia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 16:17:41 by afelicia          #+#    #+#             */
/*   Updated: 2023/02/24 17:17:12 by afelicia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	atoicito(char *str)
{
	int n = 0;
	int i = 0;

	while(str[i])
	{
		n = (str[i] - 48) + (n * 10);
		i++;
	}
	return(n);
}

void putnbr(int n)
{
	char base[10] = "0123456789";
	
	if (n > 9)
		putnbr(n / 10);
	write(1, &base[n % 10], 1);
}

int	isprime(int n)
{
	int i = 2;

	while(i * i <= n) // i < sqrt(n) 
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
	int n = 0;
	int ret = 0;

	if(argc == 2 && argv[1][0] != '-')
	{
		n = atoicito(argv[1]);
		while(n != 0)
		{
			if(isprime(n))
				ret = ret + n;
			n--;
		}
		putnbr(ret);
	}
	else
		write(1, "0", 1);
	write(1, "\n", 1);
}
