/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helping_f2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atemunov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/11 16:18:01 by atemunov          #+#    #+#             */
/*   Updated: 2018/06/11 16:22:03 by atemunov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strdup_f(char *s1, int i)
{
	int		length;
	char	*str;

	length = ft_strlen(s1);
	str = malloc(sizeof(*str) * (length + 1));
	if (str)
	{
		while (s1[++i] != '\0')
			str[i] = s1[i];
		str[i] = '\0';
	}
	return (str);
}
