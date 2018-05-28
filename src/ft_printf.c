/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atemunov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/27 21:30:03 by atemunov          #+#    #+#             */
/*   Updated: 2018/05/27 22:15:38 by atemunov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/ft_printf.h"


/*
** ft_printf() takes a va_list of arguments and converts each
** variable and all teh necessary parameter to print the 
** formated string (Check man 3 printf)
*/

int		ft_printf(const char format, ...)
{
	int		chars_printed;
	conver_t f_list[] = {
		{"d", print_int},
		{"i", print_int},
		{"c", print_char},
		{"s", print_string},
		{"b", print_binary},
		{"u", unsigned_int},
		{"o", print_octal},
		{"x", print_hex},
		{"X", print_HEX},
		{"f", print_float},
		{"%", print_percent},
		{"b", print_boolean},
		{"e", print_scientific_noation},
		{"h", print_hash}, // ex. "hello" = 5e918d2
		{NULL, NULL}
	};
	va_list args;

	if (!format)
		return (-1);

	va_start(args, format);
	/** Calling parser function **/
	chars_printed = parser(format, f_list, &args);
	va_end(args);
	return (chars_printed);
}
