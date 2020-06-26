/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaucoul <vvaucoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/19 13:19:54 by vvaucoul          #+#    #+#             */
/*   Updated: 2019/12/23 17:18:24 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			switch_print(t_ft_printf *tfp, char arg)
{
	if ((arg == 'c' ? manage_putchar(tfp) : 0) == -1)
		return (-1);
	if ((arg == 's' ? manage_putstr(tfp) : 0) == -1)
		return (-1);
	if ((arg == 'd' ? manage_putnbr(tfp) : 0) == -1)
		return (-1);
	if ((arg == 'i' ? manage_putnbr(tfp) : 0) == -1)
		return (-1);
	if ((arg == 'u' ? manage_putunbr(tfp) : 0) == -1)
		return (-1);
	if ((arg == 'x' ? manage_putbase(tfp, 0) : 0) == -1)
		return (-1);
	if ((arg == 'X' ? manage_putbase(tfp, 1) : 0) == -1)
		return (-1);
	if ((arg == 'p' ? manage_putadress(tfp) : 0) == -1)
		return (-1);
	if ((arg == '%' ? manage_mod(tfp) : 0) == -1)
		return (-1);
	return (0);
}

int			ft_parser(t_ft_printf *tfp)
{
	int i;

	i = 0;
	while (tfp->str[i])
	{
		if (is_mod(tfp->str[i]))
		{
			if ((i = found_mod(tfp, i + 1)) == -1)
				return (-1);
			if ((switch_print(tfp, tfp->atb->atb)) == -1)
				return (-1);
			free(tfp->atb);
		}
		else
		{
			if ((ft_add_char(tfp, tfp->str[i])) == -1)
				return (-1);
		}
		++i;
	}
	return (0);
}
