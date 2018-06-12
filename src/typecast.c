/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   typecast.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atemunov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/11 14:12:09 by atemunov          #+#    #+#             */
/*   Updated: 2018/06/11 17:03:55 by atemunov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*typecast_mod(va_list list, t_flags *flags, int base)
{
	flags->nbr += 1;
	if (!flags->modifier)
		return (ft_itoaf((va_arg(list, ssize_t)), flags, 1, 0));
	else if (flags->modifier == 3)
			return (ft_itoa_smax(va_arg(list, long)));
	else if (flags->modifier == 4)
			return (ft_itoa_smax(va_arg(list, long long)));
	else if (flags->modifier == 2)
			return (ft_itoaf((short)va_arg(list, int), flags, 1, 0));
	else if (flags->modifier == 1)
			return (ft_itoa_smax((char)va_arg(list, int)));
	else if (flags->modifier == 6)
			return (ft_itoa_smax(va_arg(list, ssize_t)));
	else if (flags->modifier == 5)
			return (ft_itoa_smax(va_arg(list, intmax_t)));	
	else
		return (ft_itoa_umax(va_arg(list, intmax_t), base, flags));
}	
