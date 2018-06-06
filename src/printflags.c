/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printflags.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atemunov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/05 20:57:12 by atemunov          #+#    #+#             */
/*   Updated: 2018/06/06 10:50:36 by atemunov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_flag_zero(va_list list)
{
	int nbr;
	int len;

	nbr = va_arg(list, int);
	len = 0;

	return (0);
}

/*void		ft_flag_plus(va_list list, t_flags *pass)
{
	char	*tmp;
	char	*tmp2;
	char	*num;

	num = params->str;
	if (!pass->flag_plus)
		return ;
	if (pass->type != 'i' && pass->type != 'd' && pass->type != 'D')
		return ;
	if (num[0] != '-')
	{
		tmp = ft_strtrim(params->str);
		tmp2 = ft_strjoin("+", tmp);
		pass->str = tmp2;
		ft_width(pass);
	}
}*/
