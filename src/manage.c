#include "ft_printf.h"

/*
char	*print_space(char *format, t_flags *flags)
{
	char	ret[2];
	char	print[flags->width + 1];
	int	i;
	
	i = 0;
	ret[0] = format[0];
	ret[1] = '\0';
	if (format[0])
		return (format);
	while (i < flags->width)
	{
		print[i] = (flags->zero) ? '0' : ' ';
		i++;
	}
} */

void	ft_apply_flagmods(char *format, t_flags *flags)
{
	if (!format)
	{
		ft_putstrf("(NULL)", flags, 0);
		return ;
	}
	(format[0] == '-') ? flags->precision += 1 : 0;
//	if (!flags->nbr)
//		format = (flags->precison) ?
	format = (flags->plus && flags->conversion == 'X' && !flags->zero)
		? ft_strjoin("0X", format) : format;
	format = (flags->plus && flags->conversion == 'x' && !flags->zero)
		? ft_strjoin("0x", format) : format;
	ft_putstrf(format, flags, 0);
} 	

void	manage_all(t_flags *flags, va_list list)
{
	if (flags->conversion == 'o' || flags->conversion == 'O')
		ft_apply_flagmods(print_octal(va_arg(list, unsigned int), flags), flags);
	else if (flags->conversion == 's' && !flags->modifier)
		ft_apply_flagmods(va_arg(list, char *), flags);
	
}	
