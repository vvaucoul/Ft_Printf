/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_str_02.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaucoul <vvaucoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/23 17:19:53 by vvaucoul          #+#    #+#             */
/*   Updated: 2019/12/23 17:25:09 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_parse_zeros_star(t_ft_printf *tfp, int *i)
{
	if (is_star(tfp->atb->str[i[0]]))
	{
		if ((tfp->atb->width = va_arg(tfp->list, int)) < 0)
		{
			tfp->atb->width = -tfp->atb->width;
			tfp->atb->is_neg_width = 1;
			tfp->atb->is_zeros = 1;
		}
		else
			tfp->atb->is_zeros = 1;
		++i[0];
		return (1);
	}
	return (0);
}

int		ft_parse_precision_star(t_ft_printf *tfp, int *i)
{
	if (is_star(tfp->atb->str[i[0]]))
	{
		if ((tfp->atb->precision = va_arg(tfp->list, int)) < 0)
		{
			tfp->atb->precision = 1;
			tfp->atb->precision_is_neg = TRUE;
		}
		++i[0];
		return (1);
	}
	return (0);
}
