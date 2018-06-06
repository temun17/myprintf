/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printflags.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atemunov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/05 20:57:12 by atemunov          #+#    #+#             */
/*   Updated: 2018/06/06 14:40:15 by atemunov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_flag_width(va_list list)
{
//	int 	nbr;
//	int		i;
//	t_flags *pass;
//	int		length;
	va_arg(list, int);
	return (1);
/*	int 	nbr;
	int		i;
	t_flags *pass;
	int		length;

	pass = NULL;
	nbr = va_arg(list, int);
	if (nbr == 0)
		return (ft_putchar('0'));
	if (nbr < 1)
		return (-1);
	length = base_length(nbr, 0);
	i = 0;
	while (pass->width-- >= 1)
	{
		if (pass->zero == 1)
			ft_print_char(length, &(pass->retrn));
		else if (pass->zero == 0)
			ft_print_char(' ', &(pass->retrn));
		if (pass->width == 0)
			pass->width = -100;
	}
	ft_putchar(pass->zero);
	return (length);*/
}
