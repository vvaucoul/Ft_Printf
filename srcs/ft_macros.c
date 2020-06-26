/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_macros.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaucoul <vvaucoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/19 13:21:40 by vvaucoul          #+#    #+#             */
/*   Updated: 2019/12/19 13:26:18 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_bool		is_mod(char c)
{
	return (c == '%' ? TRUE : FALSE);
}

t_bool		is_neg(char c)
{
	return (c == '-' ? TRUE : FALSE);
}

t_bool		is_zero(char c)
{
	return (c == '0' ? TRUE : FALSE);
}

t_bool		is_dot(char c)
{
	return (c == '.' ? TRUE : FALSE);
}

t_bool		is_star(char c)
{
	return (c == '*' ? TRUE : FALSE);
}
