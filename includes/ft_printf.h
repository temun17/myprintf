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
# define ISSTAR(x) (x == '*')
# define ISLENMOD(x) (x == 'h' || x == 'l' || x == 'j' || x == 'z')
# define FLAGS(x) (x == ' ' || x == '+' || x == '-' || x == '0' || x == '#')

/*
** ------------------------- Structure Definition ------------------------------
*/

typedef struct	s_flags
{
	int			nbr;
	int			minus;
	int			hash;
	int			plus;
	int			zero;
	int			space;
	int			precision;
	int			conversion;
	int			width;
	int			modifier;
	int			p;
	int			c;
	int			chars_printed;
}					t_flags;


/*
** -----------------------------------------------------------------------------
** -------------------------------- Sources ------------------------------------
** -----------------------------------------------------------------------------
*/

int	ft_printf(const char *format, ...);
void	ft_assign_flags(char *format, t_flags *flags, int *i);
void	search_width_prec(char *format, int *i, t_flags *flags, va_list list);
void	ft_assign_mods(char *format, int *i, t_flags *flags);
int	ft_convert(int i, char *format, char c);
char	*print_space(char *format, t_flags *flags);
void	manage_all(t_flags *flags, va_list list);
char	*print_octal(unsigned long int nbr, t_flags *flags);	

/*
** -------------------------- Parsing Function --------------------------------
*/

void	ft_init_flags(t_flags *flags);
int	parser(char *format, int *i, t_flags *flags, va_list list);
void	parse_format(const char *format, va_list list, int *chars_printed);


/*
** --------------------------------  Flags -------------------------------------
*/

void	ft_apply_flagmods(char *format, t_flags *flags);

/*
** ------------------------- Helping Functions --------------------------------
*/

void		ft_putcharf(char c, t_flags *flags);
size_t		nbrlen(int nbr, char *base);
void		ft_putstrf(char *format, t_flags *flags, int i);
unsigned int	base_length(unsigned int nbr, int base);
char		*str_rev(char *str);

#endif
