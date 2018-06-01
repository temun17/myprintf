#ifndef PRINTF_H
# define PRINTF_H

/*
** -------------------------- External Headers ---------------------------------
*/

# include "../libft/libft.h"
# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>
# include <math.h>


/*
** -------------------------- Macros Definition --------------------------------
*/


/*
** ------------------------- Structure Definition ------------------------------
*/

struct	convert
{
	char *opr;
	int	(*f)(va_list);
};

typedef struct convert conver_t;

typedef struct	s_infoinput
{
	int	space;
	int	minus;
	int	hash;
	int	plus;
	int	zero;
	int	precision;
	char	conversion;
	char	*modifier;
	int	f;
	int	p;
	int	c;
	int	m;
}		t_infoinput;

typedef struct	s_passinfo
{
	int	n;
	int	numlen;
	int	strlen;
	int	width;
	char	*stuff;
	int	final_count;
	int	count;
}		t_passinfo;

typedef struct	s_printf_list
{
	char	name;
	void	(*function)(va_list *list, t_infoinput *info, t_passinfo *pass);
}		t_printf_list;

typedef struct s_printf_flag
{
	char	name;
	void	(*function)(long n, t_infoinput *info, t_passinfo *pass);
}		t_printf_flag;
	

/*
** -----------------------------------------------------------------------------
** -------------------------------- Sources ------------------------------------
** -----------------------------------------------------------------------------
*/

int				ft_printf(const char *restrict format, ...);
int				print_char(va_list);
int				print_wchar_t(va_list);
int				print_int(va_list);
int				print_number(va_list);
int				unsigned_int(va_list);
int				unsigned_INT(va_list);
int				print_percent();
int				print_string(va_list);
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

/*
** --------------------------------  Flags -------------------------------------
*/

void			ft_flag_plus(long n, t_infoinput *info, t_passinfo *pass);
void			ft_flag_minus(long n, t_infoinput *info, t_passinfo *pass);
void			ft_flag_space(long n, t_infoinput *info, t_passinfo *pass);
void			ft_flag_hash(long n, t_infoinput *info, t_passinfo *pass);
void			ft_flag_zero(long n, t_infoinput *info, t_passinfo *pass);
void			ft_flag_period(long n, t_infoinput *info, t_passinfo *pass);

/*
** ------------------------- Helping Functions --------------------------------
*/

char			_memcpy(char *dst, char *src, unsigned int nbr);
unsigned int	base_length(unsigned int nbr, int base);
void			write_string(char *str);
char			*str_rev(char *str);
int				w_char(wchar_t c);



#endif
