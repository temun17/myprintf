/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base_conversions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atemunov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 14:44:14 by atemunov          #+#    #+#             */
/*   Updated: 2018/05/30 15:54:35 by atemunov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/**
 **	print_binary - Converts number from base 10 to binary
 **
 **/

int	print_binary(va_list list)
{
	int 			i;
	int 			length;
	unsigned int 	nbr;
	char 			*s;

	nbr = va_arg(list, unsigned int);
	if (nbr == 0)
	{
		return (ft_putchar('0'));
	}
	if (nbr < 1)
	{
		return (-1);
	}
	length = base_length(nbr, 2);
	s = malloc(sizeof(char) * length + 1);
	if (s == NULL)
	{
		return (-1);
	}
	i = 0;
	while (nbr > 0)
	{
		if (nbr % 2 == 0)
			s[i] = '0';
		else
			s[i] = '1';
		nbr /= 2;
		i++;
	}
	s[i] = '\0';
	s = str_rev(s);
	//rev_str = str_rev(s);
//	if (str_rev == NULL)
//	{
//		return (-1);
//	}
////	write_string(str_rev);
	write_string(s);
	//free(s);
	//free(str_rev);
	return (length);
}

/*
 ** print_octal - Converts the numeric value of a number in an octal base
 **
 **/

