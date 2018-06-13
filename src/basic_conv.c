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
	{
		print[i] = '0';
		i++;
	}
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

int		get_snumlen(intmax_t nbr, int i)
{
	while (nbr /= 10)
		i++;
	return (i);
}

char	*ft_itoa_smax(intmax_t nbr)
{
		char 		*str;
		int			length;
		uintmax_t	tmp;

		length = get_snumlen(nbr, 1);
		tmp = nbr;
		if (nbr < 0)
		{
			tmp = -nbr;
			length++;
		}
		if (!(str = (char *)malloc(sizeof(*str) * length)))
			return (NULL);
		str[length] = '\0';
		str[--length] = tmp % 10 + '0';
		(nbr < 0) ? str[0] = '-' : 0;
		return (str);
}
		
char	*print_octal(unsigned long int nbr, t_flags *flags)
{
	char			*num_rep;
	unsigned int		length;
	unsigned long int	i;
	
	ft_bzero(flags, sizeof(t_flags));
	flags->nbr += 1;
	length = base_length(nbr, 8);
	num_rep = (char *)malloc(sizeof(char) * length + 1);
	i = 0;
	if (nbr == 0)
		return (ft_strdup("0"));
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
