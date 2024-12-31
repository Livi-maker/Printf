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
	if (precision)
		len = findmaxmin((ft_atoi(precision)), ft_strlen(str), 'm');
	else 
		len = ft_strlen(str);
	i = ft_atoi(arg -> width) - len;
	arg -> printed += findmaxmin(len, i + len, 'M');
	if (isthere('-', arg -> flags) == 0)
		handle_width(i, ' ');
	while (len-- > 0)
		write(1, str++, 1);
	if (isthere('-', arg -> flags) == 1)
		handle_width(i, ' ');
}

void print_numbers(va_list *arguments, t_arg *arg)
{
	int				number;
	int				len;
	char			*precision;

	number = va_arg(*arguments, int);
	precision = arg -> precision;
	len = numlen(number, arg -> c, 10);
	if (precion)
		len = findmaxmin(ft_atoi(precision), numlen(number, arg -> c, 10), 'M');
	if ((isthere('+', arg -> flags) == 1 || isthere(' ', arg -> flags) == 1) && number > 0 && *(arg -> c) != 'u')
		len ++;
	arg -> printed += findmaxmin(len, ft_atoi(arg -> width), 'M');
	if (isthere('0', arg -> flags) == 1 && isthere('-', arg -> flags) == 0 && !(precision))
		handle_width(ft_atoi(arg -> width) - len, '0');
	else if (isthere('-', arg -> flags) == 0)
		handle_width(ft_atoi(arg -> width) - len, ' ');
	if (isthere('+', arg -> flags) == 1 && number > 0 && *(arg -> c) != 'u')
		write(1, "+", 1);
	else if (isthere(' ', arg -> flags) == 1)
		write(1, " ", 1);
	if (precision)
		handle_width(ft_atoi(precision) - numlen(number, arg -> c, 10), '0');
	if (*(arg -> c) == 'u')
		printunsigned(number);
	else
		ft_putnbr_fd(number, 1);
	if (isthere('-', arg -> flags) == 1)
		handle_width(ft_atoi(arg -> width) - len, ' ');
}

void	print_char(va_list *arguments, t_arg *arg)
{
	char	c;
	int		i;
	int		len;

	c = va_arg(*arguments, int);
	if (arg -> precision)
		len = findmaxmin(ft_atoi(arg -> precision), 1, 'm');
	else
		len = 1;
	i = ft_atoi(arg -> width) - len;
	arg -> printed += findmaxmin(len, i + len, 'M');
	if (isthere('-', arg -> flags) == 0)
		handle_width(i, ' ');
	while (len-- > 0)
		write(1, &c, 1);
	if (isthere('-', arg -> flags) == 1)
		handle_width(i, ' ');
}

void print_esanum(va_list *arguments, t_arg *arg)
{
	long unsigned 			number;
	int					len;
	char				*precision;
 
	number = va_arg(*arguments, long unsigned);
 	precision = arg -> precision;
	len = numlen(number, arg -> c, 16);
	if (precision)
 		len = findmaxmin(ft_atoi(precision), numlen(number, arg -> c , 16), 'M');
	if ((isthere('#', arg -> flags) == 1 || *(arg -> c) == 'p') && number != 0)
		len += 2;
	arg -> printed += findmaxmin(len, ft_atoi(arg -> width), 'M');
	if (isthere('0', arg -> flags) == 1 && isthere('-', arg -> flags) == 0 && !(precision))
		handle_width(ft_atoi(arg -> width) - len, '0');
	else if (isthere('-', arg -> flags) == 0)
		handle_width(ft_atoi(arg -> width) - len, ' ');
	if ((isthere('#', arg -> flags) == 1 && number != 0) || *(arg -> c) == 'p')
		write (1, "0x", 2);
	if (precision)
		handle_width(ft_atoi(precision) - numlen(number, arg -> c, 16), '0');
	if (*(arg -> c) == 'x' || *(arg -> c) == 'p')
		putnbr_base(number, "0123456789abcdef");
	else
		putnbr_base(number, "0123456789ABCDEF");
	if (isthere('-', arg -> flags) == 1)
		handle_width(ft_atoi(arg -> width) - len, ' ');
}
