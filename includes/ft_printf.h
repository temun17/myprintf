/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atemunov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/31 21:25:03 by atemunov          #+#    #+#             */
/*   Updated: 2018/06/06 10:53:09 by atemunov         ###   ########.fr       */
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

/*
** ------------------------- Structure Definition ------------------------------
*/


struct			convert
{
	char *opr;
	int	(*f)(va_list);
};

struct			flags
{
	int *pass;
	int (*flag)(va_list);
};

typedef struct	flags		flag_s;

typedef struct 	convert 	conver_t;

typedef wchar_t WCHAR;

typedef struct	s_flags
{
	int			minus;
	int			hash;
	int			plus;
	int			zero;
	int			precision;
	int			width;
	char		pad;
	int			neg;
	int			argu;
	int			final_count;
	int			flag_plus;
	int			type;
}					t_flags;

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
int				print_char(va_list);
int				print_wchar_t(va_list);
int				print_int(va_list);
int				print_number(va_list);
int				unsigned_int(va_list);
int				unsigned_INT(va_list);
int				print_percent();
int				print_string(va_list);
int				print_memory_address(va_list);
int				print_unicode(va_list);
int				print_unsigned_int(unsigned int);
int				print_binary(va_list);
int				print_octal(va_list);
int				print_OCTAL(va_list);
int				print_hex(va_list);
int				print_HEX(va_list);
int				check_hex(int, char);

/*
** -------------------------- Parsing Function --------------------------------
*/

int				parser(const char *format, conver_t f_list[], va_list args);
void			ft_init_pass(t_flags *pass);

/*
** --------------------------------  Flags -------------------------------------
*/

int					ft_flag_zero(va_list);
void				ft_flag_plus(va_list list, t_flags *pass);

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
#endif
