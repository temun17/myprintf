/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base_conversions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atemunov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 14:44:14 by atemunov          #+#    #+#             */
/*   Updated: 2018/05/31 19:10:13 by atemunov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../libft/libft.h"

/********************************************************************
 **	***BONUS*** print_binary - Converts number from base 10 to binary
 ********************************************************************
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

int	print_octal(va_list list)
{
	int 			length;
	unsigned int 	nbr;
	char 			*num_rep;
	int				i;

	nbr = va_arg(list, unsigned int);
	if (nbr == 0)
	{
		return (ft_putchar('0'));
	}
	if (nbr < 1)
	{
		return (-1);
	}
	length = base_length(nbr, 8);
	num_rep = malloc(sizeof(char) * length + 1);
	if (num_rep == NULL)
	{
		return (-1);
	}
	i = 0;
	while (nbr > 0)
	{
		num_rep[i] = (nbr % 8) + 48;
		nbr /= 8;
		i++;
	}
	num_rep[i] = '\0';
	num_rep = str_rev(num_rep);
	write_string(num_rep);
	return (length);
}

/*
 ** print_OCTAL - Converts the numeric value of a number in an octal base
 **
 **/

int	print_OCTAL(va_list list)
{
	int 			length;
	unsigned int 	nbr;
	char			*num_rep;
	int				i;

	nbr = va_arg(list, unsigned int);
	if (nbr == 0)
	{
		return (ft_putchar('0'));
	}
	if (nbr < 1)
	{
		return (-1);
	}
	length = base_length(nbr, 8);
	num_rep = malloc(sizeof(char) * length + 1);
	if (num_rep == NULL)
	{
		return (-1);
	}
	i = 0;
	while (nbr > 0)
	{
		num_rep[i] = (nbr % 8) + 48;
		nbr /= 8;
		i++;
	}
	num_rep[i] = '\0';
	num_rep = str_rev(num_rep);
	write_string(num_rep);
	return (length);
}

/*
 ** print_hex - Prints a representation of a decimal integer to a lowercase character
 **
 **/

int check_hex(int n, char x)
{
	char *hex = "abcdefghijklmnopqrstuvwxyz";
	char *HEX = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	
	n -= 10;
	if (x == 'x')
		return (hex[n]);
	else
		return (HEX[n]);
	return 0;
}

int print_hex(va_list list)
{
	unsigned int 	nbr;
	int				length;
	char 			*hex_deci;
	char 			temp;

	nbr = va_arg(list, unsigned int);

	if (nbr == 0)
	{
		return (ft_putchar('0'));
	}
	else if (nbr < 1)
	{
		return (-1);
	}
	length = base_length(nbr, 16);
	hex_deci = malloc(sizeof(char) * length + 1);
	if (hex_deci == NULL)
	{
		return (-1);
	}
	length = 0;
	while (nbr > 0)
	{
		temp = nbr % 16; // Divide the decimal number by 16 and store into variable temp
		if (temp < 10)  // If the remainder is < 10, insert (48 + temp) in array.
		{
			temp = temp + 48;
		}
		else
		{
			temp = temp + 87; // remainder is greater or equal to 10 then insert (87 + temp) lowercase.
		}
		hex_deci[length++] = temp;
		nbr /= 16; // Divide the number by 16
	}
	hex_deci[length] = '\0';
	// temp = str_rev(hex_deci);
	write_string(hex_deci); // Print out array
	return (length);
}

int	print_HEX(va_list list)
{
	unsigned int	nbr;
	int				length;
	char			*hex_deci;
	char			temp;

	nbr = va_arg(list, unsigned int);

	if (nbr == 0)
	{
		return (ft_putchar('0'));
	}
	else if (nbr < 1)
	{
		return (-1);
	}
	length = 0;
	hex_deci = malloc(sizeof(char) * length + 1);
	while (nbr > 0)
	{
		temp = nbr % 16;
		if (temp < 10)
		{
			temp = temp + 48;
		}
		else
		{
			temp = temp + 55;
		}
		hex_deci[length++] = temp;
		nbr /= 16;
	}
	hex_deci[length] = '\0';
	write_string(hex_deci);
	return (length);
}
