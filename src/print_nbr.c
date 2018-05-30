/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_nbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atemunov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 17:07:50 by atemunov          #+#    #+#             */
/*   Updated: 2018/05/29 17:31:29 by atemunov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	print_number(va_list args)
{
	int 			nbr;
	int 			div;
	int 			length;
	unsigned int 	n;

	nbr = va_arg(args, int);
	div = 1;
	length = 0;
	
	if (nbr < 0)
	{
		length = (length + ft_putchar('-'));
		n = (nbr * (-1));
	}
	else
	{
		n = nbr;
	}
	while (n / div > 9)
	{
		div = div * 10;
	}
	while (div != 0)
	{
		length = (length + ft_putchar('0' + n / div));
		n %= div;
		div = div / 10;
	}
	return (length);
}

int	print_unsigned_int(unsigned int nbr)
{
	int 			length;
	int 			div;
	unsigned int 	n;

	length = 0;
	div = 1;

	n = nbr;

	while (n / div > 9)
	{
		div = div * 10;
	}
	while (div != 0)
	{
		length = (length + ft_putchar('0' + n / div));
		n %= div;
		div = div / 10;
	}
	return (length);
}
