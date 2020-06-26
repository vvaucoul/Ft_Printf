/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_manage_display.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaucoul <vvaucoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/19 15:07:31 by vvaucoul          #+#    #+#             */
/*   Updated: 2019/12/28 16:10:37 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			manage_putchar(t_ft_printf *tfp)
{
	char c;

	c = va_arg(tfp->list, int);
	tfp->display_char_zero[tfp->actu_char_zero] = (c == 0 ? TRUE : FALSE);
	tfp->bonus_char += c == 0 ? 1 : 0;
	get_character_to_display_str(tfp, 1);
	if (tfp->atb->has_precision)
		tfp->atb->width -= tfp->atb->precision == 0 ? 1 : tfp->atb->precision
		- 1;
	tfp->atb->n_char = tfp->atb->width;
	ft_manage_spaces(tfp, 0, (tfp->atb->is_zeros == 1 ? '0' : ' '));
	if (tfp->display_char_zero[tfp->actu_char_zero])
	{
		tfp->i_to_char_zero[tfp->actu_char_zero] =
		(int)ft_strlen(tfp->main_str);
		++tfp->actu_char_zero;
	}
	else
		ft_add_char(tfp, c);
	tfp->atb->is_neg_width ? ft_manage_spaces(tfp, 1, ' ') : 0;
	return (0);
}

int			manage_putstr(t_ft_printf *tfp)
{
	char *str;
	char *tmp;

	if ((tmp = va_arg(tfp->list, char *)) == NULL)
		str = ft_strdup("(null)");
	else
		str = ft_strdup(tmp);
	if (tfp->atb->precision_is_neg)
		tfp->atb->precision = ft_strlen(str);
	get_character_to_display_str(tfp, ft_strlen(str));
	ft_manage_spaces(tfp, 0, ' ');
	ft_manage_precision_str(tfp, str);
	ft_manage_spaces(tfp, 1, ' ');
	free(str);
	return (0);
}

int			manage_putnbr(t_ft_printf *tfp)
{
	char	*str;
	int		nbr;

	nbr = va_arg(tfp->list, int);
	if ((tfp->atb->nb_is_neg = nbr < 0 ? 1 : 0) == 1)
		nbr *= -1;
	str = (nbr == -2147483648 ? ft_strdup("2147483648") : ft_itoa(nbr));
	tfp->atb->actu_str = ft_strdup(str);
	get_character_to_display_nbr(tfp, ft_strlen(str));
	if (tfp->atb->nb_is_neg && !tfp->atb->has_precision && tfp->atb->is_zeros)
		ft_add_neg(tfp);
	ft_manage_spaces(tfp, 0, (tfp->atb->is_zeros == 1 ? '0' : ' '));
	if (tfp->atb->nb_is_neg && !tfp->atb->has_precision)
		ft_add_neg(tfp);
	ft_manage_precision_nbr(tfp, str);
	ft_manage_spaces(tfp, 1, (tfp->atb->is_zeros == 1 ? '0' : ' '));
	free(str);
	free(tfp->atb->actu_str);
	return (0);
}

int			manage_putunbr(t_ft_printf *tfp)
{
	char				*str;
	unsigned int		nbr;

	nbr = va_arg(tfp->list, unsigned int);
	str = ft_utoa(nbr);
	tfp->atb->actu_str = ft_strdup(str);
	get_character_to_display_nbr(tfp, ft_strlen(str));
	ft_manage_spaces(tfp, 0, (tfp->atb->is_zeros == 1 ? '0' : ' '));
	ft_manage_precision_nbr(tfp, str);
	ft_manage_spaces(tfp, 1, ' ');
	free(str);
	free(tfp->atb->actu_str);
	return (0);
}

int			manage_putbase(t_ft_printf *tfp, t_bool up)
{
	char		*str;
	int			nbr;
	int			is_neg;

	is_neg = 0;
	if ((nbr = va_arg(tfp->list, int)) < 0)
		is_neg = 1;
	str = (nbr != 0 ? ft_itoa_base(nbr, 16) : ft_strdup("0"));
	tfp->atb->actu_str = ft_strdup(str);
	if (up)
		str = ft_strupper(str);
	if (tfp->atb->precision < (int)ft_strlen(str) && tfp->atb->has_precision)
		tfp->atb->precision = (int)ft_strlen(str);
	get_character_to_display_nbr(tfp, ft_strlen(str));
	if (tfp->atb->precision == 1 && nbr == 0)
	{
		tfp->atb->width += tfp->atb->width > 0 ? 1 : 0;
		tfp->atb->precision = 0;
	}
	ft_manage_spaces(tfp, 0, (tfp->atb->is_zeros == 1 ? '0' : ' '));
	ft_manage_precision_nbr(tfp, str);
	ft_manage_spaces(tfp, 1, ' ');
	free(str);
	free(tfp->atb->actu_str);
	return (0);
}
