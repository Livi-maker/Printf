#include "libft.h"
#include "ft_printf.h"

void	ft_putnbr(long long number, char *c, t_arg *arg, int numlen)
{
	if (*c == 'i' || *c == 'd')
	{
		if ((int)number < 0)
		{
			number *= -1;
			write(1, "-", 1);
		}
	}
	if (arg -> precision && ft_atoi(arg -> precision) == 0 && number == 0)
		return ;
	if (arg -> precision)
		handle_width(ft_atoi(arg -> precision) - numlen, '0');
	if (*c == 'i' || *c == 'd')
		ft_putnbr_fd(number, 1);
	else if (*c == 'p')
		putnbrbase_long(number);
	else if (*c == 'u')
		putnbrbase_unsigned(number, c, 10);
	else
		putnbrbase_unsigned(number, c, 16);
}

void	putnbrbase_unsigned(unsigned int number, char *c, int d)
{
	char	*base;
	char	toprint;

	if	(*c == 'X')
		base = "0123456789ABCDEF";
	else
		base = "0123456789abcdef";
	toprint = base[number % d];
	if (number >= d)
		putnbrbase_unsigned(number / d, c, d);
	write(1, &toprint, 1);
}

void	putnbrbase_long(unsigned long number)
{
	char	*base;
	
	base = "0123456789abcdef";
	if (number == 0)
	{
		write(1, "(nil)", 5);
		return ;
	}
	if (number > 15)
		putnbrbase_long(number / 16);
	write(1, &base[number % 16], 1);
}
