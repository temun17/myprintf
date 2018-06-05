/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atemunov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/28 23:55:21 by atemunov          #+#    #+#             */
/*   Updated: 2018/06/04 22:17:30 by atemunov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/*
** ft_printf() takes a va_list of arguments and converts each
** variable and all the necessary parameters to print the
** formated string (Check man 3 printf)
*/

void			ft_init_opr(t_flagmods *opr)
{
	opr->nbr = 0;
	opr->minus = 0;
	opr->hash = 0;
	opr->plus = 0;
	opr->zero = 0;
	opr->precision = 0;
	opr->width = 0;
	opr->modifier = 0;
	opr->pad = 0;
	opr->precheck = 0;
	opr->lr = 0;
	opr->f = 0;
	opr->p = 0;
	opr->c = 0;
	opr->m = 0;
	opr->w = 0;
	opr->chrfil = 0;
	opr->chk = 0;
}

int				ft_printf(const char *format, ...)
{
	int			chars_printed;
	conver_t f_list[] = {
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
	/**	{"f", print_float}, **/
		{"%", print_percent},
	/**	{"b", print_boolean}, **/
	/**	{"e", print_scientific_noation}, **/
	/**	{"h", print_hash}, // ex. "hello" = 5e918d2 **/
		{NULL, NULL}
	};
	va_list	args;
	t_flagmods opr;
//	opr = NULL;
	ft_init_opr(&opr);

	if (!format)
		return (-1);
	va_start(args, format);
	/** Calling parser function **/
	chars_printed = parser(format, f_list, args);
	va_end(args);
	return (chars_printed);
}
