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

void	handle_width(int len)
{
	while (len > 0)
	{
		write (1, " ", 1);
		len--;
	}
}
