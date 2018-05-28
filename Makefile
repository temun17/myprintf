NAME = libftprintf.a

CC = gcc

CFLAGS = -Wall -Wextra -Werror

INCLUDES = ./libft/libft.a \
		./includes/ft_printf.h \

SRC = src/main.c \
	src/ft_printf.c \

OBJS = *.o

libft.a:
	make -C libft

all : $(NAME)

$(NAME): $(OBJS) libft.a
	$(CC) $(INCLUDES) $(SRC) -o $(NAME)
	@echo "Successfully created libftprintf.a"

clean:
	make -C libft fclean
	@rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: clean all
