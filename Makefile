# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: atemunov <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/06/11 13:45:05 by atemunov          #+#    #+#              #
#    Updated: 2018/06/14 23:30:20 by atemunov         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = gcc

CFLAGS = -g -Wall -Werror -Wextra

INCLUDES = ./includes/

SRC = src/ft_printf.c \
	src/helping_f.c \
	src/helping_f2.c \
	src/parser.c \
	src/manage.c \
	src/basic_conv.c \
	src/basic_conv2.c \
	src/typecast.c \

OBJS = src/ft_printf.o \
	src/helping_f.o \
	src/helping_f2.o \
	src/parser.o \
	src/manage.o \
	src/basic_conv.o \
	src/basic_conv2.o \
	src/typecast.o \

LIBFT = ./libft

LIB_OPT = -L ./libft/ -lft

READY = @echo "\033[0;32mft_printf ready to use!"

all: $(NAME)

$(NAME):
	make -C $(LIBFT)
	$(CC) $(CFLAGS) -I $(INCLUDES) -I $(LIBFT) -c $(SRC)
	cp libft/libft.a libftprintf.a
	mv *.o src/
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)
	@echo "Successfully created libftprintf.a"
	$(READY)

re_execute:
	rm -rf BofA_Deez_Nuts
	$(CC) $(CFLAGS) -I $(INCLUDES) -I $(LIBFT) -c $(SRC) src/main.c -g
	mv *.o src/
	$(CC) $(OBJS) src/main.o $(LIB_OPT) -o BofA_Deez_Nuts

clean:
	make clean -C $(LIBFT)/
	rm -rf $(OBJS)

fclean: clean
	make fclean -C $(LIBFT)/
	rm -rf $(NAME) *.o
	
re: fclean all
