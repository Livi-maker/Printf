/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_analizer.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldei-sva <ldei-sva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 16:55:06 by ldei-sva          #+#    #+#             */
/*   Updated: 2025/01/04 11:36:40 by ldei-sva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int	isthere(char input, char *set)
{
	while (*set)
	{
		if (input == *set)
			return (1);
		set++;
	}
	return (0);
}

char	*strcreator(const char *input, char *set)
{
	int		len;
	char	*str;

	len = 0;
	while (isthere(input[len], set) == 1)
	{
		len++;
	}
	if (len != 0)
		str = ft_substr(input, 0, len);
	else
	{
		str = malloc (sizeof(char));
		*str = '\0';
	}
	return (str);
}

void	handle_width(int len, char c)
{
	while (len > 0)
	{
		write (1, &c, 1);
		len--;
	}
}

void	handle_flags_num(long long number, t_arg *arg, int len, int numlen)
{
	if (isthere('-', arg -> flags) == 0 && isthere('0', arg -> flags) == 0)
		handle_width(ft_atoi(arg -> width) - len, ' ');
	if (isthere('+', arg -> flags) == 1 && (*arg -> c == 'd' || *arg -> c == 'i') && (int)number >= 0)
		write(1, "+", 1);
	else if (isthere(' ', arg -> flags) == 1 && (*arg -> c == 'i' || *arg -> c == 'd' || *arg -> c == 'u') && (int)number >= 0)
		write(1, " ", 1);
	if ((isthere('#', arg -> flags) == 1 || *arg -> c == 'p'))
	{
		if ((*arg -> c == 'x' && (unsigned int)number != 0) || *arg -> c == 'p')
			write (1, "0x", 2);
		if (*arg -> c == 'X' && (unsigned int)number != 0)
			write (1, "0X", 2);
	}
	if (isthere('-', arg -> flags) == 0 && isthere('0', arg -> flags) == 1 && !(arg -> precision))
	{
		if ((int)number < 0 && ((*arg -> c == 'd') || (*arg -> c == 'i')))
		{
			write (1, "-", 1);
			number *= -1;
		}
		handle_width(ft_atoi(arg -> width) - len, '0');
	}
	else if (isthere('-', arg -> flags) == 0)
		handle_width(ft_atoi(arg -> width) - len, ' ');
	ft_putnbr(number, arg -> c, arg, numlen);
	if (isthere('-', arg -> flags) == 1)
		handle_width(ft_atoi(arg -> width) - len, ' ');
}

void	handle_minint(t_arg *arg, int len)
{
	char	*flags;
	char	*precision;

	flags = arg -> flags;
	precision = arg -> precision;
	if (isthere('-', flags) == 0 && isthere('0', flags) == 0)
		handle_width(ft_atoi(arg -> width) - len, ' ');
	write(1, "-", 1);
	if (isthere('-', flags) == 0)
		handle_width(ft_atoi(arg -> width) - len, ' ');
	if (isthere('-', flags) == 0 && isthere('0', flags) == 1 && !(precision))
		handle_width(ft_atoi(arg -> width) - len, '0');
	if (arg -> precision)
		handle_width(ft_atoi(precision) - 11, '0');
	write(1, "2147483648", 10);
	if (isthere('-', arg -> flags) == 1)
		handle_width(ft_atoi(arg -> width) - len, ' ');
}
