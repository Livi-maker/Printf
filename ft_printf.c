/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldei-sva <ldei-sva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 16:51:06 by ldei-sva          #+#    #+#             */
/*   Updated: 2025/01/04 14:25:41 by ldei-sva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

void	sorter(va_list *arguments, t_arg *arg, va_list *copy)
{
	char	specifier;

	specifier = *(arg -> c);
	if (specifier == 's')
		print_string(arguments, arg);
	if (specifier == 'd' || specifier == 'i')
		print_numbers(arguments, arg, copy);
	if (specifier == 'u')
		print_numbers(arguments, arg, copy);
	if (specifier == 'x' || specifier == 'X')
		print_esanum(arguments, arg, copy);
	if (specifier == 'p')
		print_esanum(arguments, arg, copy);
	if (specifier == 'c')
		print_char(arguments, arg);
	if (specifier == '%')
	{
		write(1, "%", 1);
		arg -> printed += 1;
	}
}

void	input_analizer(const char *input, va_list *arguments, t_arg *arg, va_list *copy)
{
	int		len;

	arg -> flags = strcreator(input, "-+ #0");
	len = ft_strlen(arg -> flags);
	arg -> width = strcreator(input + len, "1234567890");
	len += ft_strlen(arg -> width);
	if (*(input + len) == '.')
	{
		len++;
		arg -> precision = strcreator(input + len, "-1234567890");
		len += ft_strlen(arg -> precision);
	}
	arg -> c = strcreator(input + len, "%cspdiuxX");
	if (*(arg -> c) == '\0')
	{
		ft_putstr_fd((char *)(input - 1), 1);
		arg -> printed += ft_strlen(input - 1);
		return ;
	}
	input += len + 1;
	sorter(arguments, arg, copy);
	free_arg(arg);
	print_all(input, arguments, arg, copy);
}

void	print_all(const char *input, va_list *arguments, t_arg *arg, va_list *copy)
{
	while (*input != '%' && *input)
	{
		write(1, input, 1);
		input++;
		arg -> printed += 1;
	}
	if (*input == '%')
	{
		input++;
		input_analizer(input, arguments, arg, copy);
	}
}

int	ft_printf(const char *input, ...)
{
	va_list	arguments;
	va_list	copy;
	t_arg	*arg;
	int		printed_char;

	arg = malloc(sizeof(t_arg));
	va_start(arguments, input);
	va_copy(copy, arguments);
	createlist(arg);
	print_all(input, &arguments, arg, &copy);
	printed_char = arg -> printed;
	free (arg);
	va_end(arguments);
	va_end(copy);
	return (printed_char);
}

#include <limits.h>

int main()
{
	int	i;
	int n;

	n = printf(" %x %x %x %x %x %x %x %x\n", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, INT_MIN, 0, ULONG_MAX);
	i = ft_printf(" %x %x %x %x %x %x %x %x\n", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, INT_MIN, 0, ULONG_MAX);
	printf("toprint :%d\n", n);
	printf("printed :%d", i);
}
