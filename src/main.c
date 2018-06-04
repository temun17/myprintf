/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atemunov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/28 23:11:32 by atemunov          #+#    #+#             */
/*   Updated: 2018/06/01 19:20:40 by atemunov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	main(void)
{
	int		i;
	char	*temp;
	int		j;
	int		a;

	setlocale(LC_ALL, "en_US.UTF-8");
	temp = "Hello,";
	a = 23;
	i = -17;
	j = 1234;
	ft_printf("%s the value of i is %D\n", temp, i);
	ft_printf("%b\n", 2);
	ft_printf("%i\n", j);
	ft_printf("%%\n");
	ft_printf("%c\n", 'A');
	ft_printf("%C\n", 'a');
	// printf("%p\n", &a);
	ft_printf("%p\n", &a);
	// printf("%c\n", 'a');
	// printf("%C\n", 'a');
	printf("%5.3s\n", "swag");
	printf("%S\n", L"êêêêêêêêêêêê");
	ft_printf("%S\n", L"êêêêêêêêêêê");
	ft_printf("%u\n", 42);
	ft_printf("%U\n", 42);
	ft_printf("%x\n", 11);
	ft_printf("%X\n", 11);
	ft_printf("%o\n", 1000000);
	ft_printf("%O\n", 1000000);
	return (0);
}
