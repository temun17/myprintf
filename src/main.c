/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atemunov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/28 23:11:32 by atemunov          #+#    #+#             */
/*   Updated: 2018/05/30 15:48:25 by atemunov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	main()
{
	int i;
	char *temp;

	temp = "Hello,";
		
	i = 100;
	ft_printf("%s the value of i is %d\n", temp, i);
	ft_printf("%b", 2);
	return 0;
}
