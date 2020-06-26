/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_manage_main_str.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaucoul <vvaucoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/19 13:39:02 by vvaucoul          #+#    #+#             */
/*   Updated: 2019/12/27 17:59:24 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_add_char(t_ft_printf *tfp, char c)
{
	int		len;

	len = ft_strlen(tfp->main_str);
	tfp->main_str = ft_realloc(tfp->main_str, len + 2);
	tfp->main_str[len] = c;
	tfp->main_str[len + 1] = '\0';
	return (0);
}

int			ft_add_str(t_ft_printf *tfp, char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if ((ft_add_char(tfp, str[i])) == -1)
			return (-1);
		++i;
	}
	return (0);
}

int			ft_add_neg(t_ft_printf *tfp)
{
	if (!tfp->atb->neg_printed)
	{
		if ((ft_add_char(tfp, '-')) == -1)
			return (-1);
		tfp->atb->neg_printed = TRUE;
	}
	return (0);
}

int			ft_add_ptr(t_ft_printf *tfp)
{
	if (!tfp->atb->ptr_printed)
	{
		if ((ft_add_str(tfp, "0x")) == -1)
			return (-1);
		tfp->atb->ptr_printed = TRUE;
	}
	return (0);
}
