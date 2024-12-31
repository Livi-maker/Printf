/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldei-sva <ldei-sva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 16:55:50 by ldei-sva          #+#    #+#             */
/*   Updated: 2024/12/31 16:55:53 by ldei-sva         ###   ########.fr       */
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

t_arg	*free_arg(t_arg *arg)
{
	free (arg -> c);
	free (arg -> flags);
	free (arg -> precision);
	free (arg -> width);
	free (arg);
	arg = malloc(sizeof(t_arg));
	return (arg);
}
