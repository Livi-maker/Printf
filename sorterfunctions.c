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
			handle_width(i);
		while (len-- > 0)
			write(1, str++, 1);
		if (isthere('-', flags) == 1)
			handle_width(i);
	}
	else
	{
		while (len-- > 0)
			write(1, str++, 1);
	}
}

/*void print_numbers(char *c, char *flags, char *width, char *precision, va_list arguments)
{
	char	*str;

	if (*c == 'c' || *c == 'd')
		str = va_arg(arguments, int);
	else 
		str = va_arg(arguments, unsigned int);
	ft_putnbr_fd(str, 1);
}*/

