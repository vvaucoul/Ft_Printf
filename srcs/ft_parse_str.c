/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaucoul <vvaucoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/19 14:44:59 by vvaucoul          #+#    #+#             */
/*   Updated: 2019/12/23 17:25:51 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_parse_first_star(t_ft_printf *tfp, int *i)
{
	int nb;

	if (is_star(tfp->atb->str[i[0]]))
	{
		if ((nb = va_arg(tfp->list, int)) < 0)
		{
			tfp->atb->width = -nb;
			tfp->atb->is_neg_width = 1;
		}
		else
			tfp->atb->width = nb;
		++i[0];
	}
	return (0);
}

int		ft_parse_neg(t_ft_printf *tfp, int *i)
{
	while (is_neg(tfp->atb->str[i[0]]))
	{
		tfp->atb->is_neg_width = 1;
		++i[0];
	}
	return (0);
}

int		ft_parse_width(t_ft_printf *tfp, char *tmp, int *i)
{
	int j;

	j = 0;
	if (is_star(tfp->atb->str[i[0]]))
	{
		if ((tfp->atb->width = va_arg(tfp->list, int)) < 0)
		{
			tfp->atb->width *= -1;
			tfp->atb->is_neg_width = 1;
		}
		++i[0];
		return (0);
	}
	if (ft_isdigit(tfp->atb->str[i[0]]) && tfp->atb->str[i[0]] != '0')
	{
		while (ft_isdigit(tfp->atb->str[i[0]]) && tfp->atb->str[i[0]])
		{
			tmp[j] = tfp->atb->str[i[0]];
			++i[0];
			++j;
		}
		tmp[j] = '\0';
		tfp->atb->width = ft_atoi(tmp);
	}
	return (0);
}

int		ft_parse_zeros(t_ft_printf *tfp, char *tmp, int *i)
{
	int j;

	j = 0;
	if (ft_isdigit(tfp->atb->str[i[0]]) && tfp->atb->str[i[0]] == '0')
	{
		++i[0];
		if ((ft_parse_zeros_star(tfp, i)) == 1)
			return (0);
		while (ft_isdigit(tfp->atb->str[i[0]]) && tfp->atb->str[i[0]])
		{
			tmp[j] = tfp->atb->str[i[0]];
			++i[0];
			++j;
		}
		tmp[j] = '\0';
		tfp->atb->is_zeros = 1;
		tfp->atb->width = ft_atoi(tmp);
	}
	return (0);
}

int		ft_parse_precision(t_ft_printf *tfp, char *tmp, int *i)
{
	int j;

	j = 0;
	if (tfp->atb->str[i[0]] == '.')
	{
		tfp->atb->has_precision = TRUE;
		++i[0];
	}
	if ((ft_parse_precision_star(tfp, i)) == 1)
		return (0);
	while (ft_isdigit(tfp->atb->str[i[0]]) && tfp->atb->str[i[0]])
	{
		tmp[j] = tfp->atb->str[i[0]];
		++i[0];
		++j;
	}
	tmp[j] = '\0';
	tfp->atb->precision = ft_atoi(tmp);
	return (0);
}
