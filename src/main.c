/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atemunov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/28 23:11:32 by atemunov          #+#    #+#             */
/*   Updated: 2018/05/31 17:11:17 by atemunov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	main()
{
	int i;
	char *temp;
	int j;

	temp = "Hello,";
		
	i = 17;
	j = 1234;
	ft_printf("%s the value of i is %D\n", temp, i);
	ft_printf("%b\n", 2);
	ft_printf("%i\n", j);
	ft_printf("%%\n");
	// printf("%o\n", 1000);
	// printf("%O\n", 1000);
	// printf("%x\n", 10);
	// printf("%X\n", 10);
	// printf("%u\n", 42);
	// printf("%U\n", 42);
	ft_printf("%u\n", 42);
	ft_printf("%U\n", 42);
	ft_printf("%x\n", 11);
	ft_printf("%X\n", 11);
	ft_printf("%o\n", 1000000);
	ft_printf("%O\n", 1000000);
	return 0;
}
