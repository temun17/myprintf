/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atemunov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/27 22:15:53 by atemunov          #+#    #+#             */
/*   Updated: 2018/06/06 15:57:50 by atemunov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../libft/libft.h"

int	parser(const char *format, va_list args, t_flags *pass)
{
	int i;
	int chars_printed;

	i = 0;
	chars_printed = 0;
	while (format[i] != '\0') // Iterates through the string
	{
		if (format[i] == '%') // This checks for format specifiers
		{
			ft_flag_parse((char *)format, &i, args, pass);
			ft_init_pass(pass);
			//j = 0;
			//while (flag_list[f].pass != '\0')
			//printf("i = %d\n", find_flags(opr, format, args));
			//i += find_flags(opr, format, args);
			//printf("here: %s\n", &format[i + 1]);
		/*	while (f_list[j].opr != '\0')
			{
				printf("format = %c\n", format[i + 1]);
				if (format[i + 1] == f_list[j].opr[0])
				{
					ret = f_list[j].f(args);
					if (ret == -1)
					{
						chars_printed = ret + chars_printed;
						break ;
					}
				}
				j++;
			}*/
		}
		else
			ft_putchar(format[i]);
		/*if (f_list[j].opr == NULL && format[i + 1] != '%')
		{
			if (format[i + 1] != '\0')
			{
				//ft_putchar(format[i]);
				ft_putchar(format[i + 1]);
				//printf("here = [%c]\n", format[i + 1]);
				chars_printed = chars_printed + 2;
			}
			else
				return (-1);
		}*/
		i++; // This updates i to change format operators
	}
	if (format[i])
	{
		ft_putchar(format[i]); // Calls the write function in my libft
		chars_printed++;
	}
	return (chars_printed);
}
