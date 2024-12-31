NAME = printf

MY_SOURCES = $(wildcard *.c) $(wildcard libft/*.c)

MY_OBJECTS = $(MY_SOURCES:.c=.o)

CC = gcc

CGFLAGS += -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(MY_OBJECTS)
	$(CC) $(CGFLAGS) -o $@ $^
	#ar rcs $(NAME) $(MY_OBJECTS)

%.o: %.c
	$(CC) $(CGFLAGS) -c $< -o $@

clean: 
	rm -f $(MY_OBJECTS)

fclean:
	rm -f $(NAME) $(MY_OBJECTS)

re: fclean $(NAME)
