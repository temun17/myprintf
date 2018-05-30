/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helping_functs.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atemunov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 16:57:04 by atemunov          #+#    #+#             */
/*   Updated: 2018/05/29 17:19:06 by atemunov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char			_memcpy(char *dst, char *src, unsigned int nbr)
{
	unsigned int i;

	i = 0;
	while (i < nbr)
	{
		dst[i] = src[i];
		dst[i] = '\0';
		i++;
	}
	return (*dst);
}

void			write_string(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		ft_putchar(str[i]);
		i++;
	}
}

unsigned int	base_length(unsigned int nbr, int base)
{
	unsigned int i;

	i = 0;
	while (nbr > 0)
	{
		nbr /= base;
		i++;
	}
	return (i);
}
