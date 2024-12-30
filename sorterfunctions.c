#include "ft_printf.h"
#include "libft.h"

void	print_string(va_list *arguments, t_arg *arg)
{
	char	*str;
	int		len;
	char	*precision;
	int 	i;

	precision = arg -> precision;
	str = va_arg(*arguments, char *);
	len = findmaxmin((ft_atoi(precision)), ft_strlen(str), 'm');
	i = ft_atoi(arg -> width) - len;
	if (isthere('-', arg -> flags) == 0)
		handle_width(i, ' ');
	while (len-- > 0)
		write(1, str++, 1);
	if (isthere('-', arg -> flags) == 1)
		handle_width(i, ' ');
}

void print_numbers(va_list *arguments, t_arg *arg)
{
	int		number;
	int		len;
	char	*precision;

	number = va_arg(*arguments, int);
	precision = arg -> precision;
	len = findmaxmin(ft_atoi(precision), numlen(number), 'M');
	if ((isthere('+', arg -> flags) == 1 || isthere(' ', arg -> flags) == 1) && number > 0)
		len ++;
	if (isthere('0', arg -> flags) == 1 && isthere('-', arg -> flags) == 0 && !(*precision))
		handle_width(ft_atoi(arg -> width) - len, '0');
	else if (isthere('-', arg -> flags) == 0)
		handle_width(ft_atoi(arg -> width) - len, ' ');
	if (isthere('+', arg -> flags) == 1 && number > 0)
		write(1, "+", 1);
	else if (isthere(' ', arg -> flags) == 1)
		write(1, " ", 1);
	handle_width(ft_atoi((arg -> precision) + 1) - numlen(number), '0');
	ft_putnbr_fd(number, 1);
	if (isthere('-', arg -> flags) == 1)
		handle_width(ft_atoi(arg -> width) - len, ' ');
}

