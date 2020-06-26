/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_manage_attributs.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaucoul <vvaucoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/19 15:13:03 by vvaucoul          #+#    #+#             */
/*   Updated: 2019/12/27 16:01:11 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_manage_spaces(t_ft_printf *tfp, int after, char space)
{
	int i;

	i = 0;
	if ((after == 0 && tfp->atb->is_neg_width == 0) ||
	(after == 1 && tfp->atb->is_neg_width == 1))
	{
		while (i < tfp->atb->width - tfp->atb->nb_is_neg &&
			can_display_char(tfp))
		{
			if ((ft_add_char(tfp, space)) == -1)
				return (-1);
			++tfp->atb->n_char_displayed;
			++i;
		}
	}
	return (0);
}

int		ft_display_dot_str(t_ft_printf *tfp, char *str, int i)
{
	while (str[i] && can_display_char(tfp))
	{
		if ((ft_add_char(tfp, str[i])) == -1)
			return (-1);
		++tfp->atb->n_char_displayed;
		++i;
	}
	return (0);
}

int		ft_manage_precision_nbr_prec_nbr(t_ft_printf *tfp, char *str, int i)
{
	while ((i < (tfp->atb->precision - (int)ft_strlen(str))))
	{
		if ((ft_add_char(tfp, '0')) == -1)
			return (-1);
		++tfp->atb->n_char_displayed;
		++i;
	}
	return (0);
}

int		ft_manage_precision_nbr(t_ft_printf *tfp, char *str)
{
	int i;

	i = 0;
	if (tfp->atb->has_precision)
	{
		if (tfp->atb->nb_is_neg)
			ft_add_neg(tfp);
		if ((ft_manage_precision_nbr_prec_nbr(tfp, str, i)) == -1)
			return (-1);
		i = 0;
		if (tfp->atb->precision > 0)
			while (str[i] && i < tfp->atb->precision && can_display_char(tfp))
			{
				if ((ft_add_char(tfp, str[i])) == -1)
					return (-1);
				++tfp->atb->n_char_displayed;
				++i;
			}
	}
	else if ((ft_display_dot_str(tfp, str, i)) == -1)
		return (-1);
	return (0);
}

int		ft_manage_precision_str(t_ft_printf *tfp, char *str)
{
	int i;

	i = 0;
	if (tfp->atb->has_precision)
	{
		i = 0;
		while ((i < (tfp->atb->precision - (int)ft_strlen(str))))
		{
			if ((ft_add_char(tfp, ' ')) == -1)
				return (-1);
			++tfp->atb->n_char_displayed;
			++i;
		}
		i = 0;
		while (str[i] && i < tfp->atb->precision && can_display_char(tfp))
		{
			if ((ft_add_char(tfp, str[i])) == -1)
				return (-1);
			++tfp->atb->n_char_displayed;
			++i;
		}
	}
	else if ((ft_display_dot_str(tfp, str, i)) == -1)
		return (-1);
	return (0);
}
