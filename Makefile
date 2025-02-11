NAME = libftprintf.a

MY_SOURCES = $(wildcard *.c) $(wildcard libft/*.c)

MY_OBJECTS = $(MY_SOURCES:.c=.o)

CC = cc

CGFLAGS += -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(MY_OBJECTS)
	ar rcs $(NAME) $(MY_OBJECTS)

%.o: %.c
	$(CC) $(CGFLAGS) -c $< -o $@

bonus: $(NAME)

clean: 
	rm -f $(MY_OBJECTS)

fclean:
	rm -f $(NAME) $(MY_OBJECTS)

re: fclean $(NAME)
