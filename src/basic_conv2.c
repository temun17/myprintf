/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_conv2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atemunov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/11 14:49:42 by atemunov          #+#    #+#             */
/*   Updated: 2018/06/14 19:02:12 by atemunov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_itoaf(int num, t_flags *flags, int len, int sign)
{
	char	*str;

	sign = num;
	if (num == 0 && flags->p)
		return (" ");
	while (sign /= 10)
		len++;
	sign = num < 0 ? 1 : 0;
	len = num < 0 ? len = len + 1 : len;
	str = (char *)malloc(sizeof(char) * len + 1);
	if (num == -2147483648)
		return (str = ft_strdup_f(INT_MIN, -1));
	if (!str)
		return (NULL);
	(sign) ? str[0] = '-' : 0;
	num = num < 0 ? num *= -1 : num;
	while (--len >= sign)
	{
		str[len] = (num >= 10) ? (num % 10) + '0' : num + '0';
		num /= 10;
	}
	str[ft_strlen(str)] = '\0';
	return (str);
}

int		get_unumlen(unsigned int nbr, int base, int i)
{
	while (nbr /= base)
		i++;
	return (i);
}

char	*ft_itoa_umax(unsigned int nbr, int base, t_flags *flags)
{
	char	*str;
	int		length;
	char	*tmp;
	
	tmp = ft_strdup_f(H_LOWER, -1);
	flags->nbr += 1;
	length = get_unumlen(nbr, base, 1);
	nbr == 0 ? flags->plus = 0 : 0;
	if (nbr == 0 && flags->p)
		return ("");
	if (!(str = (char *)malloc(sizeof(*str) * length + 1)))
		return (NULL);
	str[length] = '\0';
	str[--length] = tmp[nbr % base];
	while (nbr /= base)
		str[--length] = tmp[nbr % base];
	length = -1;
	if (flags->conversion == 'X')
		while (str[++length])
			(UCASE(str[length])) ? str[length] -= 32 : 0;
	free(tmp);
	return (str);
}
