/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printflags.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atemunov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/05 20:57:12 by atemunov          #+#    #+#             */
/*   Updated: 2018/06/05 21:52:57 by atemunov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../libft/libft.h"

int		ft_flag_zero(va_list list, t_flagmods *pass)
{
	int	nbr;
	int	n;

	nbr = va_arg(list, int);
	n = 0;
	while (pass->ft_nbrlen < pass->width)
	{
		ft_putchar('0');
		pass->ft_nbrlen++;
		pass->final_count++;
	}
	n *= 1;
	return (n);
}
