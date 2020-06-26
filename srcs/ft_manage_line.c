/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_manage_line.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaucoul <vvaucoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/19 15:40:42 by vvaucoul          #+#    #+#             */
/*   Updated: 2019/12/23 17:33:16 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		get_character_to_display_str(t_ft_printf *tfp, int len)
{
	int	spaces;
	int	precision;

	spaces = tfp->atb->width;
	precision = tfp->atb->has_precision ? tfp->atb->precision : 0;
	if (!tfp->atb->has_precision)
	{
		tfp->atb->n_char = spaces >= len ? spaces : len;
		tfp->atb->width = spaces >= len ? spaces - len : 0;
	}
	else
	{
		if (precision > len || precision < 0)
			precision = len;
		if (spaces < 0)
			spaces = -1;
		if (spaces > precision)
			spaces -= precision;
		else
			spaces = 0;
		tfp->atb->width = spaces;
		tfp->atb->precision = precision;
		tfp->atb->n_char = precision + spaces;
	}
	return (0);
}

int		gctdn_nbr(t_ft_printf *tfp, int len, int *spaces, int *precision)
{
	if (precision[0] > len)
		precision[0] -= len;
	else
		precision[0] = 0;
	if (spaces[0] > len + precision[0])
		spaces[0] -= len + precision[0];
	else
		spaces[0] = 0;
	tfp->atb->n_char = spaces[0] + len;
	tfp->atb->width = spaces[0];
	return (0);
}

int		get_character_to_display_nbr(t_ft_printf *tfp, int len)
{
	int spaces;
	int precision;

	spaces = tfp->atb->width;
	precision = tfp->atb->precision;
	if (!tfp->atb->has_precision)
		gctdn_nbr(tfp, len, &spaces, &precision);
	else
	{
		if (precision < len && ft_atoi(tfp->atb->actu_str) != 0)
			precision = len;
		if (spaces > 0 && precision < spaces)
			spaces = spaces - (precision);
		else if (precision >= spaces)
			spaces = 0;
		tfp->atb->width = spaces;
		tfp->atb->precision = precision;
		tfp->atb->n_char = precision + spaces;
	}
	return (0);
}
