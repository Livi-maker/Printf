#include "ft_printf.h"
#include "libft.h"

void	sorter(char *c, char *flags, char *width, char *precision, va_list *arguments)
{
	if (*c == 's')
		print_string(flags, width, precision, arguments);
	/*if (*c == 'd' || *c == 'i')
		print_numbers(c, flags, width, precision, arguments);
	if (*c == 'u')
		print_numbers(c, flags, width, precision, arguments);
	if (*c == 'x' || *c == 'X')
		print_esanum(c, flags, widht, precision, arguments);
	if (*c == 'p')
		print_pointer(c, flags, width, precision, arguments);
	if (*c == 'c')
		print_char(c, flags, width, precision, arguments);*/
	if (*c == '%')
	{
		write(1, "%", 1);
	}
}

void	flag_analizer(const char *input, va_list *arguments)
{
	char	*flags;
	char	*width;
	char	*precision;
	char	*c;

	flags = strcreator(input, "-+ #0");
	input += ft_strlen(flags);
	width = strcreator(input, "*1234567890");
	input += ft_strlen(width);
	precision = strcreator(input, "-.*1234567890");
	input += ft_strlen(precision);
	c = strcreator(input, "cspdiuxX");
	input += ft_strlen(c);
	sorter(c, flags, width, precision, arguments);
	print_all(input, arguments);
}

void	print_all(const char *input, va_list *arguments)
{
	while (*input != '%' && *input)
	{
		write(1, input, 1);
		input++;
	}
	if (*input == '%')
	{
		input++;
		flag_analizer(input, arguments);
	}
}

int	ft_printf(const char *input, ...)
{
	va_list	arguments;
	va_list copy;

	va_start(arguments, input);
	va_copy(copy, arguments);
	print_all(input, &copy);
	return (0);
}


int main()
{
	printf("orig :%2147.s.\n","ciao");
	ft_printf("test :%2147.s.", "ciao");
}
