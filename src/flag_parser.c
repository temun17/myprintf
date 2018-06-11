/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atemunov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/06 14:41:55 by atemunov          #+#    #+#             */
/*   Updated: 2018/06/06 16:25:56 by atemunov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

conver_t g_conversions[] = {
	{"d", print_int},
	{"D", print_int},
	{"i", print_int},
	{"c", print_char},
	{"C", print_wchar_t},
	{"s", print_string},
	{"S", print_unicode},
	{"b", print_binary},
	{"p", print_memory_address},
	{"u", unsigned_int},
	{"U", unsigned_INT},
	{"o", print_octal},
	{"O", print_OCTAL},
	{"x", print_hex},
	{"X", print_HEX},
	{"%", print_percent},
	{NULL, NULL}
};

void	ft_assign_flags(char flag, t_flags *pass)
{
	if (flag == '#')
		pass->hash = 1;
	else if (flag == '0')
		pass->zero = 1;
	else if (flag == ' ')
		pass->space = 1;
	else if (flag == '-')
		pass->minus = 1;
	else if (flag == '+')
		pass->plus = 1;
}


void	ft_assign_format(char *flag, t_flags *pass, int *i)
{
	if (flag[0] == 'h' && flag[1] == 'h')
	{
		pass->format = 1;
		(*i)++;
	}
	else if (flag[0] == 'h')
		pass->format = 2;
	else if (flag[0] == 'l' && flag[1] == 'l')
	{
		pass->format = 4;
		(*i)++;
	}
	else if (flag[0] == 'l')
		pass->format = 3;
	else if (flag[0] == 'j')
		pass->format = 5;
	else if (flag[0] == 'z')
		pass->format = 6;
}

void	ft_convert(va_list args, t_flags *pass)
{
	int i;

	i = 0;
	while (g_conversions[i].opr)
	{
		if (!ft_strcmp((g_conversions[i].opr), &(pass->type)))
		{
			//positive_width
			g_conversions[i].f(args, pass);
			//negative width
			//prec
		}
		i++;
	}
}

void	ft_flag_parse(char *format, int *i, va_list args, t_flags *pass)
{
	while (!ft_strchr("dDicCsSbpuUoOxX", format[*i]))
	{
		if (FLAGS(format[*i]))
			ft_assign_flags(format[*i], pass);
		else if (ISLENMOD(format[*i]))
			ft_assign_format(&format[*i], pass, i);
		else if (ft_isdigit(format[*i]))
		{
			pass->width = ft_atoi(&format[*i]);
			while (ft_isdigit(format[(*i) + 1]) && format[(*i) + 1])
				(*i)++;
		}
		else if (format[*i] == '.')
		{
			pass->precision = ft_atoi(&format[*i + 1]);
			while (ft_isdigit(format[(*i) + 1]) && format[(*i) + 1])
				(*i)++;
		}
		(*i)++;
		if (format[*i] == '%')
			break ;
	}
	pass->type = format[*i];
	ft_convert(args, pass);
}
