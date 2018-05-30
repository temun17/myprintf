# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: atemunov <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/05/28 23:06:34 by atemunov          #+#    #+#              #
#    Updated: 2018/05/29 17:18:34 by atemunov         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = gcc

CFLAGS = -Wall -Wextra -Werror

INCLUDES = ./includes/ft_printf.h


SRC = src/main.c \
	  src/ft_printf.c \
	  src/parser.c \
	  src/modifiers_and_specifiers.c \
	  src/base_conversions.c \
	  src/helping_functs.c \
	  src/print_nbr.c \


OBJS = $(patsubst %.c, %.o, $(SRC))

LIBFT = libft

all : $(NAME)

$(NAME): 
		make -C $(LIBFT)
		cp $(LIBFT)/libft.a ./$(NAME)
		$(CC) $(CFLAGS) $(INCLUDES) -c $(SRC)
		ar rc $(NAME) $(OBJS)
		ranlib $(NAME)
		@echo "Successfully created libftprintf.a"

clean:
	make clean -C $(LIBFT)/
	@rm -rf $(OBJS) 

fclean: clean
	make fclean -C $(LIBFT)/
	rm -rf $(NAME) *.o

re: clean all
