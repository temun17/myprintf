# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: atemunov <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/05/28 23:06:34 by atemunov          #+#    #+#              #
#    Updated: 2018/06/06 14:41:43 by atemunov         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = gcc

CFLAGS = -g -Wall -Wextra -Werror

INCLUDES = ./includes/

SRC = src/ft_printf.c \
	  src/parser.c \
	  src/modifiers_and_specifiers.c \
	  src/base_conversions.c \
	  src/helping_functs.c \
	  src/printflags.c \
	  src/flag_parser.c \

OBJS = $(SRC:.c=.o)

LIBFT = ./libft

LIB_OPT = -L ./libft/ -lft

READY = @echo "\033[0;32mft_printf ready to use!"

all : $(NAME)

$(NAME):
	make -C $(LIBFT)
	$(CC) $(CFLAGS) -I $(INCLUDES) -I $(LIBFT) -c $(SRC)
	cp libft/libft.a libftprintf.a
	mv *.o src/
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)
	@echo "Successfully created libftprintf.a"
	$(READY)

re_executable:
	rm -rf BofA_Deez_Nuts
	$(CC) $(CFLAGS) -I $(INCLUDES) -I $(LIBFT) -c $(SRC) src/main.c -g
	mv *.o src/
	$(CC) $(OBJS) src/main.o $(LIB_OPT) -o BofA_Deez_Nuts

clean:
	make clean -C $(LIBFT)/
	@rm -rf $(OBJS)

fclean: clean
	make fclean -C $(LIBFT)/
	rm -rf $(NAME) *.o

re: fclean all
