/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atemunov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/31 21:25:03 by atemunov          #+#    #+#             */
/*   Updated: 2018/06/06 16:18:27 by atemunov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

/*
** -------------------------- External Headers ---------------------------------
*/

# include "libft.h"
# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include <locale.h>
# include <wchar.h>
# include <inttypes.h>

/*
** -------------------------- Macros Definition --------------------------------
*/

# define H_LOWER ("0123456789abcdef")
# define ISLENMOD(x) (x == 'h' || x == 'l' || x == 'j' || x == 'z')
# define FLAGS(x) (x == ' ' || x == '+' || x == '-' || x == '0' || x == '#')

/*
** ------------------------- Structure Definition ------------------------------
*/

typedef struct	flags		flag_s;

typedef struct	s_flags
{
	int			minus;
	int			hash;
	int			plus;
	int			zero;
	int			space;
	int			precision;
	int			width;
	int			neg;
	int			format;
	int			final_count;
	int			flag_plus;
	char		type;
	int			str;
	int			retrn;
}					t_flags;

struct			convert
{
	char *opr;
	int	(*f)(va_list, t_flags *);
};

struct			flags
{
	int *pass;
	int (*flag)(va_list);
};

typedef struct 	convert 	conver_t;

typedef wchar_t WCHAR;

typedef enum	e_bool
{
	false,
	true
}				t_bool;

/*
** -----------------------------------------------------------------------------
** -------------------------------- Sources ------------------------------------
** -----------------------------------------------------------------------------
*/

int				ft_printf(const char *format, ...);
int				print_char(va_list, t_flags *);
int				print_wchar_t(va_list, t_flags *);
int				print_int(va_list, t_flags *);
int				print_number(va_list, t_flags *);
int				unsigned_int(va_list, t_flags *);
int				unsigned_INT(va_list, t_flags *);
int				print_percent();
int				print_string(va_list, t_flags *);
int				print_memory_address(va_list, t_flags *);
int				print_unicode(va_list, t_flags *);
int				print_unsigned_int(unsigned int, t_flags *);
int				print_binary(va_list, t_flags *);
int				print_octal(va_list, t_flags *);
int				print_OCTAL(va_list, t_flags *);
int				print_hex(va_list, t_flags *);
int				print_HEX(va_list, t_flags *);
int				check_hex(int, char);

/*
** -------------------------- Parsing Function --------------------------------
*/

int				parser(const char *format, va_list args, t_flags *pass);
void			ft_init_pass(t_flags *pass);

/*
** --------------------------------  Flags -------------------------------------
*/

void				ft_flag_parse(char *format, int *i, va_list args, t_flags *pass);
int					ft_flag_width(va_list);
int					ft_flag_plus(va_list);

/*
** ------------------------- Helping Functions --------------------------------
*/

char			_memcpy(char *dst, char *src, unsigned int nbr);
unsigned int	base_length(unsigned int nbr, int base);
void			write_string(char *str);
void			putw_str(wchar_t *str);
char			*str_rev(char *str);
int				w_char(wchar_t c);
int				ft_nbrlen(int c);
void			ft_print_char(char c, int *ret);

/*conver_t g_conversions[] = {
	{"d", print_int},
	{"D", print_int},
	{"i", print_int},
	{"c", print_char},
	{"C", print_wchar_t},
	{"s", print_string},
	{"S", print_unicode},
	{"b", print_binary},
	{"p", print_memory_address},
	{"u", unsigned_int},
	{"U", unsigned_INT},
	{"o", print_octal},
	{"O", print_OCTAL},
	{"x", print_hex},
	{"X", print_HEX},
	{"%", print_percent},
	{"0", ft_flag_width},
	{NULL, NULL}
	};*/

#endif
