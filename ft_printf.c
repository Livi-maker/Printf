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
	if (specifier == 'u')
		print_numbers(arguments, arg);
	if (specifier == 'x' || specifier == 'X')
		print_esanum(arguments, arg);
	if (specifier == 'p')
		print_esanum(arguments, arg);
	if (specifier == 'c')
		print_char(arguments, arg);
	if (specifier == '%')
	{
		write(1, "%", 1);
	}
}

void	input_analizer(const char *input, va_list *arguments, t_arg *arg)
{
	int		len;
	t_arg	*temp;

	arg -> flags = strcreator(input, "-+ #0");
	len = ft_strlen(arg -> flags);
	arg -> width = strcreator(input + len, "*1234567890");
	len += ft_strlen(arg -> width);
	if (*(input + len) == '.')
	{
		len++;
		arg -> precision = strcreator(input + len, "-*1234567890");
	}
	if (arg -> precision)
		len += ft_strlen(arg -> precision);
	arg -> c = strcreator(input + len, "cspdiuxX");
	if (*(arg -> c) == '\0')
	{
		ft_putstr_fd((char *)(input - 1), 1);
		arg -> printed += ft_strlen(input - 1);
		return ;
	}
	input += len + ft_strlen(arg -> c);
	sorter(arguments, arg);
	temp = arg;
	arg = malloc(sizeof(t_arg);
	free_arg(temp);
	print_all(input, arguments, arg);
}

void	print_all(const char *input, va_list *arguments, t_arg *arg)
{
	int	printed_char;

	printed_char = 0;
	while (*input != '%' && *input)
	{
		write(1, input, 1);
		input++;
		arg -> printed += 1;
	}
	if (*input == '%')
	{
		input++;
		input_analizer(input, arguments, arg);
	}
}

int	ft_printf(const char *input, ...)
{
	va_list	arguments;
	t_arg	*arg;
	int		printed_char;

	arg = malloc(sizeof(t_arg);
	va_start(arguments, input);
	arg -> printed = 0;
	print_all(input, &arguments, arg);
	printed_char = arg -> printed
	free (arg);
	va_end(arguments);
	return (printed_char);
}

/*int main()
{
	int	i;
	int n;

	n = printf("orig :%c %c.\n",'0', 'l');
	i = ft_printf("test :%c %c.\n",'0', 'l');
	printf("toprint :%d\n", n);
	printf("printed :%d", i);
}*/
