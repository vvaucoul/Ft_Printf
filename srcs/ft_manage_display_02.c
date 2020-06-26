/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_manage_display_02.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaucoul <vvaucoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/23 17:17:23 by vvaucoul          #+#    #+#             */
/*   Updated: 2019/12/23 17:17:39 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			manage_putadress(t_ft_printf *tfp)
{
	char			*str;
	void			*ptr;
	unsigned long	address;

	ptr = va_arg(tfp->list, void *);
	address = (unsigned long)ptr;
	str = ft_ultoa(address);
	tfp->atb->actu_str = ft_strdup(str);
	get_character_to_display_nbr(tfp, ft_ptrlen(ptr));
	if (tfp->atb->is_zeros == FALSE)
		ft_manage_spaces(tfp, 0, ' ');
	if (tfp->atb->is_zeros)
	{
		if (tfp->atb->width > 0)
			tfp->atb->width -= 2;
	}
	ft_add_ptr(tfp);
	if (tfp->atb->is_zeros == TRUE)
		ft_manage_spaces(tfp, 0, (tfp->atb->is_zeros == 1 ? '0' : ' '));
	ft_putaddress(tfp, ptr);
	ft_manage_spaces(tfp, 1, ' ');
	free(str);
	free(tfp->atb->actu_str);
	return (0);
}

int			manage_mod(t_ft_printf *tfp)
{
	tfp->atb->actu_str = ft_strdup("%");
	tfp->atb->precision = 1;
	get_character_to_display_nbr(tfp, 1);
	if (tfp->atb->precision != 1 && tfp->atb->has_precision)
	{
		tfp->atb->precision = 1;
		tfp->atb->n_char = tfp->atb->width > 1 ? tfp->atb->width : 1;
	}
	ft_manage_spaces(tfp, 0, (tfp->atb->is_zeros == 1 ? '0' : ' '));
	ft_manage_precision_str(tfp, tfp->atb->actu_str);
	ft_manage_spaces(tfp, 1, ' ');
	free(tfp->atb->actu_str);
	return (0);
}
