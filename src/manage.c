#include "ft_printf.h"

char	*print_zeros(char *format, t_flags *flags)
{
	char	*spc;
	int		i;

	i = 0;
	spc = (char*)malloc(sizeof(char) * flags->precision + 1);
	if (flags->precision < 1)
		return (format);
	while (i < flags->precision)
	{
		spc[i] = '0';
		i++;
	}
	spc[i] = '\0';
	if (format[0] == '-')
	{
		format = ft_strjoin(spc, &format[1]);
		format = ft_strjoin("-", format);
	}
	else
		format = ft_strjoin(spc, format);
	flags->zero = 0;
	free(spc);
	return (format);
}

char	*print_spaces(char *format, t_flags *flags)
{
	char	ret[2];
	char	print[flags->width + 1];
	int	i;
	
	i = 0;
	ret[0] = format[0];
	ret[1] = '\0';
	if (!format || flags->width < 1)
		return (format);
	while (i < flags->width)
	{
		print[i] = (flags->zero) ? '0' : ' ';
		i++;
	}
	print[i] = '\0';
	if ((print[0] == '-' || print[0] == '+') && flags->zero && flags->nbr)
	{
		format = ft_strjoin(print, &format[1]);
		format = ft_strjoin(print, format);
	}
	else
		format = (flags->minus) ? ft_strjoin(format, print) : ft_strjoin(print, format);
	return (format);
}

char	*ft_pslice(char *format, t_flags *flags, int i)
{
	char	*str;

	str = (char *)malloc(sizeof(char) * flags->precision + 1);
	while (i < flags->precision)
	{
		str[i] = format[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

void	ft_apply_flagmods(char *format, t_flags *flags)
{
	if (!format)
	{
		ft_putstrf("(NULL)", flags, 0);
		return ;
	}
//	(flags->zero && flags->width) ? flags->width -= flags->precision : 0;
	(format[0] == '-') ? flags->precision += 1 : 0;
	if (!flags->nbr)
		format = (flags->precision) ? ft_pslice(format, flags, 0) : format;
	format = (flags->plus && flags->conversion == 'X' && !flags->zero)
		? ft_strjoin("0X", format) : format;
	format = (flags->plus && flags->conversion == 'x' && !flags->zero)
		? ft_strjoin("0x", format) : format;
	(flags->precision == ft_strlen(format)) ? flags->zero = 0 : 0;
	(flags->space && format[0] != '-') ? flags->width -= 1 : 0;
	(flags->plus && format[0] != '-') ? flags->width -= 1 : 0;
	flags->precision -= ft_strlen(format);
	format = (flags->nbr) ? print_zeros(format, flags) : format;
	format = (flags->plus && format[0] != '-') ? ft_strjoin("+", format) : format;
	flags->width -= ft_strlen(format);
	format = print_spaces(format, flags);
	format = (flags->plus && flags->conversion == 'x' && flags->zero) ? ft_strjoin("0x", format) : format;
	format = (flags->plus && flags->conversion == 'X' && flags->zero) ? ft_strjoin("0X", format) : format;
	format = (flags->space && format[0] != '-') ? ft_strjoin(" ", format) : format;
	ft_putstrf(format, flags, 0);
} 	

void	manage_all(t_flags *flags, va_list list)
{
	if (flags->conversion == 'o' || flags->conversion == 'O')
		ft_apply_flagmods(print_octal(va_arg(list, unsigned int), flags), flags);
	else if (flags->conversion == 's' && !flags->modifier)
		ft_apply_flagmods(va_arg(list, char *), flags);
	else if (flags->conversion == 'p')
		ft_apply_flagmods(print_memory_address(va_arg(list, unsigned long int), flags), flags);
	else if (flags->conversion == 'b')
		ft_apply_flagmods(print_binary(va_arg(list, unsigned long int), flags), flags);
	else if (flags->conversion == 'c')
		ft_putcharf(va_arg(list, int), flags);
	else if (flags->conversion == 'd' || flags->conversion == 'i')
		ft_apply_flagmods(typecast_mod(list, flags, 10), flags);
	else if (flags->conversion == 'S' || (flags->modifier == 3 && flags->conversion == 's'))
		ft_putwtstr(va_arg(list, wchar_t *), flags, 0);
	else if (flags->conversion == 'C')
		ft_putwtstr((ft_wctos(va_arg(list, wchar_t))), flags, 0);
	else if (flags->conversion == 'x' || flags->conversion == 'X')
		ft_apply_flagmods(typecast_hex(list, flags, 16), flags);
	else if (flags->conversion == 'D')
		ft_apply_flagmods(ft_itoa_umax(va_arg(list, long), 10, flags), flags);
	else if (flags->conversion == 'u' || flags->conversion == 'X')
		ft_apply_flagmods(ft_itoa_umax(va_arg(list, intmax_t), 10, flags), flags);
}
