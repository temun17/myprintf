/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atemunov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/28 23:11:32 by atemunov          #+#    #+#             */
/*   Updated: 2018/05/30 17:28:57 by atemunov         ###   ########.fr       */
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
	ft_printf("%o\n", 1000);
	ft_printf("%O\n", 1000);
	return 0;
}
