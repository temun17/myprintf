/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modifiers_and_specifiers.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atemunov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/28 23:17:47 by atemunov          #+#    #+#             */
/*   Updated: 2018/05/31 22:06:10 by atemunov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../libft/libft.h"

int	print_unsigned_int(unsigned int n)
{
	int				div; // Divides the numerator by the denominator
	int				len;
	unsigned int	nbr;

	div = 1;
	len = 0;
	nbr = n;
	while (nbr / div > 9)
	{
		div = div * 10;
	}
	while (div != 0)
	{
		len = (len + ft_putchar('0' + nbr / div));
		nbr %= div;
		div = (div / 10);
	}
	return (len);
}

int	unsigned_int(va_list list)
{
	int				nbr;

	nbr = va_arg(list, unsigned int);
	if (nbr == 0)
		return (print_unsigned_int(nbr));
	if (nbr < 1)
		return (-1);
	return (print_unsigned_int(nbr));
}

int	unsigned_INT(va_list list)
{
	int				nbr;

	nbr = va_arg(list, unsigned int);
	if (nbr == 0)
		return (print_unsigned_int(nbr));
	if (nbr < 1)
		return (-1);
	return (print_unsigned_int(nbr));
}

int	print_number(va_list args)
{
	int				nbr;
	int				div;
	int				len;
	unsigned int	num;

	nbr = va_arg(args, int);
	div = 1;
	len = 0;
	if (nbr < 0)
	{
		len = (len + ft_putchar('-'));
		num = (nbr * (-1));
	}
	else
		num = nbr;
	while (num / div > 9)
		div = (div * 10);
	while (div != 0)
	{
		len = (len + ft_putchar('0' + num / div));
		num %= div;
		div = (div / 10);
	}
	return (len);
}

int	print_int(va_list list)
{
	int nbr_len;

	nbr_len = print_number(list);
	return (nbr_len);
}

int	print_percent(void)
{
	ft_putchar('%');
	return (1);
}

int	print_string(va_list list)
{
	int			i;
	char		*str;

	i = 0;
	str = va_arg(list, char *);
	if (str == '\0')
		str = "(NULL)";
	while (str[i] != '\0')
	{
		ft_putchar(str[i]);
		i++;
	}
	return (i);
}

int	print_char(va_list list)
{
	ft_putchar((char)va_arg(list, int));
	return (1);
}

int	print_wchar_t(va_list list)
{
	w_char(va_arg(list, int));
	return (1);
}
