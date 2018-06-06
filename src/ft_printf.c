/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atemunov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/28 23:55:21 by atemunov          #+#    #+#             */
/*   Updated: 2018/06/06 16:11:10 by atemunov         ###   ########.fr       */
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
	pass->space = 0;
	pass->format = 0;
	pass->final_count = 0;
	pass->flag_plus = 0;
	pass->type = 0;
	pass->str = 0;
	pass->retrn = 0;
}

int				ft_printf(const char *format, ...)
{
	int			chars_printed;

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
	chars_printed = parser(format, args, &pass);
	va_end(args);
	return (chars_printed);
}
