#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdarg.h>

typedef struct	s_arg
{
	char	*flags;
	char	*width;
	char	*precision;
	char	*c;
	int		printed;
} t_arg;

int		isthere(char input, char *set);
char	*strcreator(const char *input, char *set);
int		print_all(const char *input, va_list *arguments, t_arg *arg);
void	print_string(va_list *arguments, t_arg *arg);
void	handle_width(int len, char c);
void	print_numbers(va_list *arguments, t_arg *arg);
int		numlen(long long number, char *c, int d);
int		findmaxmin(int i1, int i2, char indicator);
void	printunsigned(unsigned int number);
void	print_char(va_list *arguments, t_arg *arg);
void	putnbr_base(long unsigned number, char *base);
void	print_esanum(va_list *arguments, t_arg *arg);
void	free_arg(t_arg *arg);
int		ft_printf(const char *input, ...);

#endif
