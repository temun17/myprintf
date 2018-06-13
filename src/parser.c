/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atemunov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/11 13:46:40 by atemunov          #+#    #+#             */
/*   Updated: 2018/06/13 00:43:13 by atemunov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_convert(int i, char *format, char c)
{
	while (format[i])
	{
		if (c == format[i])
			return (1);
		(i)++;
	}
	return (0);
}

void	ft_assign_mods(char *format, int *i, t_flags *flags)
{
	if (format[0] == 'h' && format[1] == 'h')
	{
		flags->modifier = 1;
		(*i)++;
	}
	else if (format[0] == 'h')
		flags->modifier = 2;
	else if (format[0] == 'l' && format[1] ==  'l')
	{
		flags->modifier = 4;
		(*i)++;
	}
	else if (format[0] == 'l')
		flags->modifier = 3;
	else if (format[0] == 'j')
		flags->modifier = 5;
	else if (format[0] == 'z')
		flags->modifier = 6;
}

void	search_width_prec(char *format, int *i, t_flags *flags, va_list list)
{
	if (format[*i] && (((DIGIT(format[*i]))) 
			|| (format[*i] == '*' && format[*i - 1] != '*')))
	{
		if (format[*i] == '*' && format[*i - 1] != '*')
		{
			flags->width = va_arg(list, int);
			(*i)++;
		}
		else
		{
			flags->width = (ft_atoif(&format[*i], 0));
			*i += nbrlen(ft_atoi(&format[*i]), 0);
		}
	}
	if (format[*i] == '.')
	{
		*i = *i + 1;
		flags->p += 1;
		if (ISSTAR(format[*i]))
			flags->precision = va_arg(list, int);
		else if(format[*i] && DIGIT(format[*i]))
			flags->precision = ft_atoi(&format[*i]);
		while (ft_isdigit(format[*i]) || ISSTAR(format[*i]))
			*i = *i + 1;
	}
}
		
void	ft_assign_flags(char *format, t_flags *flags, int *i)
{
	while (format[*i] && (FLAGS(format[*i])))
	{
		(format[*i] == '-') ? flags->minus += 1 : 0;
		(format[*i] == '#') ? flags->hash += 1 : 0;
		(format[*i] == ' ') ? flags->space += 1 : 0;
		(format[*i] == '0') ? flags->zero += 1 : 0;
		(format[*i] == '+') ? flags->plus += 1 : 0;
		(*i)++;
	}
}

int	parser(char *format, int *i, t_flags *flags, va_list list)
{
	*i = *i + 1;
	ft_assign_flags(format, flags, i);
	search_width_prec(format, i, flags, list);
	ft_assign_mods(format, i, flags);
	if (ft_convert(0, "cCdDisSpoOxXuUb", format[*i]))
	{
		flags->c += 1;
		flags->conversion = format[*i];
	}
	if (flags->p <= 1 && flags->c == 1 ? 1 : 0)
		return (1);
	else if (flags->width)
	{
		flags->width = flags->width - 1;
		(flags->width) ? ft_putcharf(format[*i], flags) : 0;
		(flags->width) ? *i = *i + 1 : 0;
		ft_putstrf(print_spaces("", flags), flags, 0);
	}
	else if (flags->zero)
	{
		ft_putstrf(print_zeros("", flags), flags, 0);
	}
	return (0);
}
