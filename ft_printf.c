#include "ft_printf.h"
#include "libft.h"

void	sorter(va_list *arguments, t_arg *arg)
{
	char	specifier;

	specifier = *(arg -> c);
	if (specifier == 's')
		print_string(arguments, arg);
	if (specifier == 'd' || specifier == 'i')
		print_numbers(arguments, arg);
	/*if (*c == 'u')
		print_numbers(c, flags, width, precision, arguments);
	if (*c == 'x' || *c == 'X')
		print_esanum(c, flags, widht, precision, arguments);
	if (*c == 'p')
		print_pointer(c, flags, width, precision, arguments);
	if (*c == 'c')
		print_char(c, flags, width, precision, arguments);*/
	if (*(arg -> c) == '%')
	{
		write(1, "%", 1);
	}
}

void	flag_analizer(const char *input, va_list *arguments, t_arg *arg)
{
	int		len;

	arg -> flags = strcreator(input, "-+ #0");
	len = ft_strlen(arg -> flags);
	arg -> width = strcreator(input + len, "*1234567890");
	len += ft_strlen(arg -> width);
	if (*(input + len) == '.')
		len++;
	arg -> precision = strcreator(input + len, "-*1234567890");
	len += ft_strlen(arg -> precision);
	arg -> c = strcreator(input + len, "cspdiuxX");
	if (*(arg -> c) == '\0')
	{
		ft_putstr_fd(input - 1, 1);
		return ;
	}
	input += len + ft_strlen(arg -> c);
	sorter(arguments, arg);
	print_all(input, arguments, arg);
}

void	print_all(const char *input, va_list *arguments, t_arg *arg)
{
	while (*input != '%' && *input)
	{
		write(1, input, 1);
		input++;
	}
	if (*input == '%')
	{
		input++;
		flag_analizer(input, arguments, arg);
	}
}

int	ft_printf(const char *input, ...)
{
	va_list	arguments;
	t_arg	*arg;

	arg = malloc(sizeof(t_arg));
	va_start(arguments, input);
	print_all(input, &arguments, arg);
	return (0);
}


int main()
{
	printf("orig :%12.2s.\n","ciao");
	ft_printf("test :%12.2s.","ciao");
}
