NAME = printf.a

MY_SOURCES = *.c libft/*.c

MY_OBJECTS = $(MY_SOURCES:.c=.o)

CC = gcc

CGFLAGS += -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(MY_OBJECTS)
	ar rcs $(NAME) $(MY_OBJECTS)

clean: 
	rm -f $(MY_OBJECTS)

fclean:
	rm -f $(NAME) $(MY_SOURCES)

re: flean $(NAME)
