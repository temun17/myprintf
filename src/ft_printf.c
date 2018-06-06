/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atemunov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/28 23:55:21 by atemunov          #+#    #+#             */
/*   Updated: 2018/06/06 11:00:29 by atemunov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** ft_printf() takes a va_list of arguments and converts each
** variable and all the necessary parameters to print the
** formated string (Check man 3 printf)
*/

void			ft_init_pass(t_flags *pass)
{
	pass->minus = 0;
	pass->hash = 0;
	pass->plus = 0;
	pass->zero = 0;
	pass->precision = -1;
	pass->width = 0;
	pass->neg = 0;
	pass->pad = 0;
	pass->argu = 0;
	pass->final_count = 0;
	pass->flag_plus = 0;
	pass->type = 0;
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
//		{'-', ft_flag_minus},
//		{'+', ft_flag_plus},
//		{' ', ft_flag_space},
//		{'#', ft_flag_hash},
		{"0", ft_flag_zero},
//		{'.', ft_flag_period},
		{NULL, NULL}
	};

//	flag_s flag_list[] = {
//		{'-', ft_flag_minus},
//		{'+', ft_flag_plus},
//		{' ', ft_flag_space},
//		{'#', ft_flag_hash},
//		{'0', ft_flag_zero},
//		{'.', ft_flag_period},
//		{NULL, NULL}
//	};
	va_list	args;
	t_flags pass;
//	pass = NULL;
	ft_init_pass(&pass);
	if (!format)
		return (-1);
	va_start(args, format);
	/** Calling parser function **/
	chars_printed = parser(format, f_list, args);
	va_end(args);
	return (chars_printed);
}
