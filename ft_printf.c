#include "ft_printf.h"
#include "libft.h"

void	sorter(const char *input, va_list arguments)
{
	char	*flags;
	int		len;

	len = ft_strlen(input);
	flags = ft_substr(input, len);
	printf("%s", flags);
	free (flags);
}
void	print_all(const char *input, va_list arguments)
{
	while (*input != '%' && *input)
	{
		write(1, input, 1);
		input++;
	}
	if (*input == '%')
	{
		input++;
		sorter(input, arguments);
	}
}

int	ft_printf(const char *input, ...)
{
	va_list	arguments;

	va_start(arguments, input);
	print_all(input, arguments);
	return (0);
}


int main()
{
	//printf("%-123.5u",123456);
	ft_printf("ciao%s", "ciao");
}
