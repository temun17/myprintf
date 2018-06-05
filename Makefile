# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: atemunov <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/05/28 23:06:34 by atemunov          #+#    #+#              #
#    Updated: 2018/06/04 22:15:10 by atemunov         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = gcc

CFLAGS = -g -Wall -Wextra -Werror

INCLUDES = ./includes/ft_printf.h

SRC = src/main.c \
	  src/ft_printf.c \
	  src/parser.c \
	  src/modifiers_and_specifiers.c \
	  src/base_conversions.c \
	  src/helping_functs.c \

OBJS = $(SRC:.c=.o)

LIBFT = libft

READY = @echo "\033[0;32mft_printf ready to use!"

all : $(NAME)

$(NAME):
	make -C $(LIBFT)
	$(CC) $(CFLAGS) -I $(INCLUDES) -c $(SRC)
	cp libft/libft.a libftprintf.a
	mv *.o src/
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)
	@echo "Successfully created libftprintf.a"
	$(READY)

clean:
	make clean -C $(LIBFT)/
	@rm -rf $(OBJS)

fclean: clean
	make fclean -C $(LIBFT)/
	rm -rf $(NAME) *.o

re: fclean all
