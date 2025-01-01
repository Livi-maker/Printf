/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldei-sva <ldei-sva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 16:55:50 by ldei-sva          #+#    #+#             */
/*   Updated: 2025/01/01 18:32:04 by ldei-sva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

void	printunsigned(unsigned int c)
{
	char	n;

	n = (c % 10) + '0';
	if (c > 9)
		printunsigned(c / 10);
	ft_putchar_fd(n, 1);
}

void	putnbr_base(long unsigned number, char *base)
{
	char	c;

	c = base[number % 16];
	if (number > 15)
		putnbr_base(number / 16, base);
	ft_putchar_fd(c, 1);
}

void	free_arg(t_arg *arg)
{
	free (arg -> c);
	arg -> c = NULL;
	free (arg -> flags);
	arg -> flags = NULL;
	free (arg -> precision);
	arg -> precision = NULL;
	free (arg -> width);
	arg -> width = NULL;
}

t_arg	*createlist(t_arg *arg)
{
	arg -> c = NULL;
	arg -> flags = NULL;
	arg -> precision = NULL;
	arg -> width = NULL;
	arg -> printed = 0;
	return (arg);
}

int	numlen2(long long number, int d)
{
	unsigned long long	n;
	int 				len;

	len = 0;
	n = number;
	if (n <= 0)
	{
		len++;
		n *= -1;
	}
	while (n > 0)
	{
		len++;
		n /= d;
	}
	return (len);
}
