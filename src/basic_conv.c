#include "ft_printf.h"

char	*print_binary(unsigned long int nbr, t_flags *flags)
{
	int		i;
	int		length;
	char	*s;

	ft_bzero(flags, sizeof(t_flags));
	length = base_length(nbr, 2);
	s = malloc(sizeof(char) * length + 1);
	i = 0;
	while (nbr > 0)
	{
		if (nbr % 2 == 0)
			s[i] = '0';
		else
			s[i] = '1';
		nbr /= 2;
		i++;
	}
	s[i] = '\0';
	s = str_rev(s);
	return (s);
}

/*int	print_hex(char *format, t_flags *flags, int i)
{
	unsigned int 	nbr;
	int		length;
	char		*hex_deci;
	char		temp;
	
	ft_bzero(flags, sizeof(t_flags));
	nbr = va_arg(format, unsigned int);
	if (nbr == 0)
		return (0);
	else if (nbr < 1)
		return (-1);
	length = base_length(nbr, 16);
	hex_deci = malloc(sizeof(char) * length + 1);
	length = 0;
	while (nbr > 0)
	{
		temp = nbr % 16;
		if (temp < 10)
			temp = temp + 48;
		else
			temp = temp + 87;
		hex_deci[length++] = temp;
		nbr /= 16;
	}
	return (length); */

char	*print_memory_address(unsigned long int nbr, t_flags *pass)
{
	char				*print;
	unsigned int		i;
	int					length;

	ft_bzero(pass, sizeof(t_flags));
	i = 0;
	length = 0;
	print = malloc(sizeof(char) * length + 1);
	if (nbr == 0)
		print[i] = '0';
	while (nbr != 0)
	{
		print[i++] = H_LOWER[nbr % 16];
		nbr /= 16;
	}
	print[i] = '\0';
	print = str_rev(print);
	print = ft_strjoin("0x", print);
	return (print);
}

char	*print_octal(unsigned long int nbr, t_flags *flags)
{
	char			*num_rep;
	unsigned int		length;
	unsigned long int	i;
	
	ft_bzero(flags, sizeof(t_flags));
	flags->nbr += 1;
	length = base_length(nbr, 8);
	num_rep = malloc(sizeof(char) * length + 1);
	i = 0;
	while (nbr > 0)
	{
		num_rep[i] = (nbr % 8) + 48;
		nbr /= 8;
		i++;
	}
	num_rep[i] = '\0';
	num_rep = str_rev(num_rep);
	(i != 0 && flags->plus) ? num_rep = ft_strjoin("0", num_rep) : 0;
	return (num_rep);
} 
