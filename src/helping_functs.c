/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helping_functs.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atemunov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 16:57:04 by atemunov          #+#    #+#             */
/*   Updated: 2018/05/31 19:10:39 by atemunov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../libft/libft.h"

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

char			*str_rev(char *str)
{
	int 	i;
	int 	len;
	char	temp;

	len = 0;
	while (str[len] != '\0')
	{
		len++;
	}
	i = -1;
	while (++i < --len)
	{
		temp = str[i];
		str[i] = str[len];
		str[len] = temp;
	}
	return (str);
}
