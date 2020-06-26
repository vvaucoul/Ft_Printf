/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putaddress.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaucoul <vvaucoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/20 16:32:38 by vvaucoul          #+#    #+#             */
/*   Updated: 2019/12/23 17:46:18 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_add_address(t_ft_printf *tfp, unsigned long n)
{
	if (n > 15)
	{
		ft_add_address(tfp, (n / 16));
		ft_add_address(tfp, (n % 16));
	}
	else if (n < 10)
	{
		ft_add_char(tfp, (n + '0'));
	}
	else
	{
		n == 10 ? ft_add_char(tfp, 'a') : 0;
		n == 11 ? ft_add_char(tfp, 'b') : 0;
		n == 12 ? ft_add_char(tfp, 'c') : 0;
		n == 13 ? ft_add_char(tfp, 'd') : 0;
		n == 14 ? ft_add_char(tfp, 'e') : 0;
		n == 15 ? ft_add_char(tfp, 'f') : 0;
	}
	return (0);
}

int		ft_putaddress(t_ft_printf *tfp, void *in)
{
	void			*output;
	unsigned long	address;

	output = in;
	address = (unsigned long)(output);
	if ((ft_add_address(tfp, address)) == -1)
		return (-1);
	return (0);
}
