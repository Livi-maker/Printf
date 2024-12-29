#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdarg.h>

int		isthere(char input, char *set);
char	*strcreator(const char *input, char *set);
void	print_all(const char *input, va_list *arg);
void	print_string(char *flags, char *width, char *precision, va_list *arg);
void	handle_width(int len);
#endif
