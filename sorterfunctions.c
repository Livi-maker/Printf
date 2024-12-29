#include "ft_printf.h"
#include "libft.h"

void	print_string(char *flags, char *width, char *precision, va_list *arg)
{
	char	*str;
	int		len;
	int		i;

	str = va_arg(*arg, char *);
	if (*precision && *(precision + 1) != '-' && ft_atoi(precision + 1) < (int)ft_strlen(str))
		len = atoi(precision + 1);
	else
		len = ft_strlen(str);
	if (*width)
	{
		i = ft_atoi(width) - len;
		if (isthere('-', flags) == 0)
			handle_width(i, ' ');
		while (len-- > 0)
			write(1, str++, 1);
		if (isthere('-', flags) == 1)
			handle_width(i, ' ');
	}
	else
	{
		while (len-- > 0)
			write(1, str++, 1);
	}
}

void print_numbers(/*char *c,*/ char *flags, char *width, char *precision, va_list *arguments)
{
	int	number;
	int	len;

	number = va_arg(*arguments, int);
	if (*precision && *(precision + 1) != '-' && ft_atoi(precision + 1) > numlen(number))
		len = ft_atoi(precision + 1);
	else
		len = numlen(number);
	if ((isthere('+', flags) == 1 || isthere(' ', flags) == 1) && number > 0)
		len ++;
	if (isthere('0', flags) == 1 && isthere('-', flags) == 0)
		handle_width(ft_atoi(width) - len, '0');
	else if (isthere('-', flags) == 0)
		handle_width(ft_atoi(width) - len, ' ');
	if (isthere('+', flags) == 1 && number > 0)
		write(1, "+", 1);
	else if (isthere(' ', flags) == 1)
		write(1, " ", 1);
	handle_width(ft_atoi(precision + 1) - numlen(number), '0');
	ft_putnbr_fd(number, 1);
	if (isthere('-', flags) == 1)
		handle_width(ft_atoi(width) - len, ' ');
}

