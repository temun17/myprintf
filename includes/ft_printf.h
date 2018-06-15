/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atemunov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/31 21:25:03 by atemunov          #+#    #+#             */
/*   Updated: 2018/06/14 19:21:09 by atemunov         ###   ########.fr       */
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
# include <locale.h>

/*
** -------------------------- Macros Definition --------------------------------
*/

# define H_LOWER ("0123456789abcdef")
# define ISSTAR(x) (x == '*')
# define ISLENMOD(x) (x == 'h' || x == 'l' || x == 'j' || x == 'z')
# define FLAGS(x) (x == ' ' || x == '+' || x == '-' || x == '0' || x == '#')
# define INT_MIN ("-2147483648")

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
char	*print_spaces(char *format, t_flags *flags);
char	*print_zeros(char *format, t_flags *flags);
char	*ft_pslice(char *format, t_flags *flags, int i);
void	manage_all(t_flags *flags, va_list list);
char	*print_octal(unsigned long int nbr, t_flags *flags);
char	*print_memory_address(unsigned long int nbr, t_flags *flags);
char	*print_binary(unsigned long int nbr, t_flags *flags);
int		get_snumlen(intmax_t nbr, int i);
char	*ft_itoa_smax(intmax_t nbr);
char	*typecast_mod(va_list list, t_flags *flags, int base);
char	*typecast_hex(va_list list, t_flags *flags, int base);
char	*ft_itoaf(int num, t_flags *flags, int len, int sign);
char	*ft_itoa_umax(unsigned int nbr, int base, t_flags *flags);
int		get_unumlen(unsigned int nbr, int base, int i);
char	*ft_ullitoaif(unsigned long long int nbr);

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
int			nbrlen(int nbr, int i);
void		ft_putstrf(char *format, t_flags *flags, int i);
unsigned int	base_length(unsigned int nbr, int base);
char		*str_rev(char *str);
char		*ft_strdup_f(char *s1, int i);
int			ft_putw_str(wchar_t *str);
wchar_t		*ft_wctos(wchar_t wchar);
void		ft_putwtstr(wchar_t *wide, t_flags *flags, int i);
int			ft_atoif(const char *str, int i);
#endif
