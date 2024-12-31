#include "ft_printf.h"
#include "libft.h"

void	printunsigned(unsigned int c)
{
	char    n;

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
	free (arg -> flags);
	free (arg -> precision);
	free (arg -> width);
}