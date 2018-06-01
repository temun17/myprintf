/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atemunov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/28 23:55:21 by atemunov          #+#    #+#             */
/*   Updated: 2018/05/31 17:08:59 by atemunov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/*
** ft_printf() takes a va_list of arguments and converts each
** variable and all the necessary parameters to print the 
** formated string (Check man 3 printf)
*/

int		ft_printf(const char *restrict format, ...)
{
	int		chars_printed;
	conver_t f_list[] = {
		{"d", print_int},
		{"D", print_int},
		{"i", print_int},
		{"c", print_char},
		{"s", print_string},
	//	{"S", print_unicode},
		{"b", print_binary},
	//	{"p", print_memory_location},
		{"u", unsigned_int},
		{"U", unsigned_INT},
		{"o", print_octal},
		{"O", print_OCTAL},
		{"x", print_hex},
		{"X", print_HEX},
	//	{"f", print_float},
		{"%", print_percent},
	//	{"b", print_boolean},
	//	{"e", print_scientific_noation},
	//	{"h", print_hash}, // ex. "hello" = 5e918d2
		{NULL, NULL}
	};
	va_list args;

	if (!format)
		return (-1);

	va_start(args, format);
	/** Calling parser function **/
	chars_printed = parser(format, f_list, args);
	va_end(args);
	return (chars_printed);
}
