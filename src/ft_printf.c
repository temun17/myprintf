/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atemunov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/11 13:46:19 by atemunov          #+#    #+#             */
/*   Updated: 2018/06/13 22:41:27 by atemunov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** %[parameter][flags][width][.precision][length]type
*/

void	ft_init_flags(t_flags *flags)
{
	flags->nbr = 0;
	flags->minus = 0;
	flags->hash = 0;
	flags->plus = 0;
	flags->zero = 0;
	flags->space = 0;
	flags->precision = 0;
	flags->conversion = 0;
	flags->width = 0;
	flags->modifier = 0;
	flags->p = 0;
	flags->c = 0;
	flags->chars_printed = 0;
}

void	parse_format(const char *format, va_list list, int *chars_printed)
{
	t_flags	flags;
	int	i;
	
	i = 0;
	while (format[i])
	{
		ft_init_flags(&flags);
		if (format[i] == '%' && format[i + 1] == '%')
		{
			ft_putcharf('%', &flags);
			i = i + 1;
		}
		else if (format[i] == '%')
		{
			if (parser((char *)format, &i, &flags, list))
				manage_all(&flags, list);
			else if (format[i])
				ft_putcharf(format[i], &flags);
		}
		else if (i < ft_strlen((char *)format))
			ft_putcharf(format[i], &flags);
		*chars_printed += flags.chars_printed;
		i++; 
	}
}
	
int	ft_printf(const char *format, ...)
{
	va_list	list;
	int	i;
	int	chars_printed;
	
	i = 0;
	chars_printed = 0;
	va_start(list, format);
	parse_format(format, list, &chars_printed);
	va_end(list);
	return (chars_printed);
}
