/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atemunov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/19 12:53:02 by atemunov          #+#    #+#             */
/*   Updated: 2018/03/07 13:32:14 by atemunov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	int	i;
	int	res;
	int	isneg;

	i = 0;
	res = 0;
	isneg = 1;
	while (ESCAPE(str[i]) || ESCAPE2(str[i]))
		i++;
	if (str[i] == '-')
		isneg = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while ((str[i] >= '0' && str[i] <= '9'))
	{
		res *= 10;
		res += (str[i] - '0');
		i++;
	}
	return (res * isneg);
}
