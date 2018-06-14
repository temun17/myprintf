/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helping_f2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atemunov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/11 16:18:01 by atemunov          #+#    #+#             */
/*   Updated: 2018/06/14 00:35:10 by atemunov         ###   ########.fr       */
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

int		ft_putw_str(wchar_t *str)
{
	int	length;

	length = 0;
	while (str[length] != L'\0')
		length++;
	return (length);
}

wchar_t	*ft_wctos(wchar_t wchar)
{
	wchar_t *wide;

	wide = (wchar_t *)malloc(sizeof(wchar) * 2);
	if (wide)
	{
		wide[0] = wchar;
		wide[1] = L'\0';
	}
	return (wide);
}

void	ft_putwtstr(wchar_t *wide, t_flags *flags, int i)
{
	flags->width -= (ft_putw_str(wide) - flags->precision);
	flags->minus ? flags->zero = 0 : 0;
	if (flags->width > 0 && !flags->minus)
		while (flags->width)
		{
			flags->zero ? write(1, "0", 1) : write(1, " ", 1);
			flags->width -= 1;
		}
	while (wide[i])
	{
		if (flags->precision && flags->precision < ft_putw_str(wide))
		{
				ft_putcharf(wide[i], flags);
		}
		ft_putcharf(wide[i], flags);
		i++;
		flags->chars_printed += 1;
	}
	if (flags->width > 0 && flags->minus)
		while (flags->width)
		{
			flags->zero ? write(1, "0", 1) : write(1, " ", 1);
			flags->width -= 1;
		}
}

int		ft_atoif(const char *str, int i)
{
	int num;
	int sign;

	num = 0;
	sign = 1;
	if (*(str + i) == '-')
		sign = -1;
	while (*(str + i) && *(str + i) >= '0' && *(str + i) <= '9')
		num = num * 10 + (*(str + i++) - '0');
	return (num * sign);
}
