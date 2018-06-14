/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helping_f.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atemunov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/11 13:46:24 by atemunov          #+#    #+#             */
/*   Updated: 2018/06/13 22:38:36 by atemunov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putcharf(char c, t_flags *flags)
{
	write(1, &c, 1);
	flags->chars_printed = flags->chars_printed + 1;
}

int		nbrlen(int nbr, int i)
{
	int	base_num;
	
	base_num = 10;
	while (nbr != 0)
	{
		nbr /= base_num;
		i++;
	}
	return (i);
}

void	ft_putstrf(char *format, t_flags *flags, int i)
{
	if (!format)
	{
		write(1, "(null)", 6);
		return ;
	}
	while (format[i])
	{
		write(1, &format[i], 1);
		flags->chars_printed += 1;
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

char		*str_rev(char *str)
{
	int 	i;
	int 	len;
	char 	temp;
	
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
