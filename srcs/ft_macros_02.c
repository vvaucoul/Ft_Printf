/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_macros_02.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaucoul <vvaucoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/19 14:02:14 by vvaucoul          #+#    #+#             */
/*   Updated: 2019/12/23 17:34:31 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_bool	char_can_be_parsed(char c)
{
	return ((ft_isdigit(c) || is_format(c) || is_attribut(c)) ? TRUE : FALSE);
}

t_bool	can_display_char(t_ft_printf *tfp)
{
	return (tfp->atb->n_char_displayed < tfp->atb->n_char ? 1 : 0);
}

t_bool	is_format(char c)
{
	return ((c == 'c' || c == 's' || c == 'd' || c == 'i' || c == 'u' ||
	c == 'p' || c == 'x' || c == 'X' || c == '%') ? TRUE : FALSE);
}

t_bool	is_format_wm(char c)
{
	return ((c == 'c' || c == 's' || c == 'd' || c == 'i' || c == 'u' ||
	c == 'p' || c == 'x' || c == 'X') ? TRUE : FALSE);
}

t_bool	is_attribut(char c)
{
	return ((c == '-' || c == '0' || c == '.' || c == '*') ? TRUE : FALSE);
}
