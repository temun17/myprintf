/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base_conversions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atemunov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 14:44:14 by atemunov          #+#    #+#             */
/*   Updated: 2018/06/01 19:06:36 by atemunov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../libft/libft.h"

/********************************************************************
 **	***BONUS*** print_binary - Converts number from base 10 to binary
 ********************************************************************
 **/

int	print_binary(va_list list, t_flags *pass)
{
	int				i;
	int				length;
	unsigned int	nbr;
	char			*s;

	ft_bzero(pass, sizeof(t_flags));
	nbr = va_arg(list, unsigned int);
	if (nbr == 0)
		return (ft_putchar('0'));
	if (nbr < 1)
		return (-1);
	length = base_length(nbr, 2);
	s = malloc(sizeof(char) * length + 1);
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
	write_string(s);
	return (length);
}

/*
 ** print_octal - Converts the numeric value of a number in an octal base
 **
 **/

int	print_octal(va_list list, t_flags *pass)
{
	int				length;
	unsigned int	nbr;
	char			*num_rep;
	int				i;

	ft_bzero(pass, sizeof(t_flags));
	nbr = va_arg(list, unsigned int);
	if (nbr == 0)
		return (ft_putchar('0'));
	if (nbr < 1)
		return (-1);
	length = base_length(nbr, 8);
	num_rep = malloc(sizeof(char) * length + 1);
	if (num_rep == NULL)
		return (-1);
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

int	print_OCTAL(va_list list, t_flags *pass)
{
	int				length;
	unsigned int	nbr;
	char			*num_rep;
	int				i;

	ft_bzero(pass, sizeof(t_flags));
	nbr = va_arg(list, unsigned int);
	if (nbr == 0)
		return (ft_putchar('0'));
	if (nbr < 1)
		return (-1);
	length = base_length(nbr, 8);
	num_rep = malloc(sizeof(char) * length + 1);
	if (num_rep == NULL)
		return (-1);
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

int	check_hex(int n, char x)
{
	char *hex = "abcdefghijklmnopqrstuvwxyz";
	char *HEX = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

	n -= 10;
	if (x == 'x')
		return (hex[n]);
	else
		return (HEX[n]);
	return (0);
}

int print_hex(va_list list, t_flags *pass)
{
	unsigned int	nbr;
	int				length;
	char			*hex_deci;
	char			temp;

	ft_bzero(pass, sizeof(t_flags));
	nbr = va_arg(list, unsigned int);
	if (nbr == 0)
		return (ft_putchar('0'));
	else if (nbr < 1)
		return (-1);
	length = base_length(nbr, 16);
	hex_deci = malloc(sizeof(char) * length + 1);
	length = 0;
	while (nbr > 0)
	{
		temp = nbr % 16;
		if (temp < 10)
			temp = temp + 48;
		else
			temp = temp + 87;
		hex_deci[length++] = temp;
		nbr /= 16; // Divide the number by 16
	}
	hex_deci[length] = '\0';
	write_string(hex_deci); // Print out array
	return (length);
}

int	print_HEX(va_list list, t_flags *pass)
{
	unsigned int	nbr;
	int				length;
	char			*hex_deci;
	char			temp;

	ft_bzero(pass, sizeof(t_flags));
	nbr = va_arg(list, unsigned int);
	if (nbr == 0)
		return (ft_putchar('0'));
	else if (nbr < 1)
		return (-1);
	length = 0;
	hex_deci = malloc(sizeof(char) * length + 1);
	while (nbr > 0)
	{
		temp = nbr % 16;
		if (temp < 10)
			temp = temp + 48;
		else
			temp = temp + 55;
		hex_deci[length++] = temp;
		nbr /= 16;
	}
	hex_deci[length] = '\0';
	write_string(hex_deci);
	return (length);
}

int	print_memory_address(va_list list, t_flags *pass)
{
	char				*print;
	unsigned int		i;
	unsigned long int	nbr;
	int					length;

	ft_bzero(pass, sizeof(t_flags));
	i = 0;
	length = 0;
	nbr = va_arg(list, unsigned long int);
	print = malloc(sizeof(char) * length + 1);
	if (nbr == 0)
		print[i] = '0';
	while (nbr != 0)
	{
		print[i++] = H_LOWER[nbr % 16];
		nbr /= 16;
	}
	print[i] = '\0';
	print = str_rev(print);
	print = ft_strjoin("0x", print);
	write_string(print);
	return (*print);
}

int	print_unicode(va_list list, t_flags *pass)
{
	wchar_t	*fake_wide;
	wchar_t *wide;
	int	len;
	char	org;
	int	i;

	ft_bzero(pass, sizeof(t_flags));
	i = 0;
	len = 0;
	org = 0;
	wide = va_arg(list, wchar_t*);
	fake_wide = NULL;
	if (len == 1)
		fake_wide[0] = org;
	else if (len == 2)
	{
		fake_wide[0] = ((org >> 6) | 0xC0);
		fake_wide[1] = ((org & 0x3f) | 0x80);
	}
	else if (len == 3)
	{
		fake_wide[0] = ((org >> 12) | 0xE0);
		fake_wide[1] = (((org >> 6) & 0x3f) | 0x80);
		fake_wide[2] = ((org & 0x3f) | 0x80);
	}
	else if (len == 4)
	{
		fake_wide[0] = ((org >> 18) | 0xf0);
		fake_wide[1] = (((org >> 12) & 0x3f) | 0x80);
		fake_wide[2] = (((org >> 6) & 0x3f) | 0x80);
		fake_wide[3] = ((org & 0x3f) | 0x80);
	}
	putw_str(wide);
	return (len);
}
