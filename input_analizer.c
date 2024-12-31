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

int	numlen(long long number, char *c, int d)
{
	int	len;
	long long n;

	len = 0;
	n = number;
	if (*c == 'u' || *c == 'x' || *c == 'X' || *c == 'p')
		n = (unsigned long) number;
	if (n < 0)
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

int	findmaxmin(int i1, int i2, char indicator)
{
	if (indicator == 'm')
	{
		if (i1 < i2)
			return (i1);
		return (i2);
	}
	if (indicator == 'M')
	{
		if (i1 > i2)
			return (i1);
	}
	return (i2);
}