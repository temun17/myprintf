#ifndef FT_PRINTF_H
# define FT_PRINTF_H

/*
** -------------------------- External Headers ---------------------------------
*/

# include "../libft/libft.h"
# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>


/*
** -------------------------- Macros Definition --------------------------------
*/


/*
** ------------------------- Structure Definition ------------------------------
*/

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

int						ft_printf(const char *format, ...);

/*
** -------------------------- Parsing Functions --------------------------------
*/


/*
** --------------------------------  Flags -------------------------------------
*/

void	ft_flag_plus(long n, t_infoinput *info, t_passinfo *pass);
void	ft_flag_minus(long n, t_infoinput *info, t_passinfo *pass);
void	ft_flag_space(long n, t_infoinput *info, t_passinfo *pass);
void	ft_flag_hash(long n, t_infoinput *info, t_passinfo *pass);
void	ft_flag_zero(long n, t_infoinput *info, t_passinfo *pass);
void	ft_flag_period(long n, t_infoinput *info, t_passinfo *pass);

/*
** ---------------------- Strings & Chars Functions ----------------------------
*/



#endif
