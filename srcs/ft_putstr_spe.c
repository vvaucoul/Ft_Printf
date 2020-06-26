/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_spe.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaucoul <vvaucoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/23 16:52:20 by vvaucoul          #+#    #+#             */
/*   Updated: 2019/12/27 16:09:19 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_end(t_ft_printf *tfp)
{
	int j;

	j = 0;
	while (j < tfp->actu_char_zero)
	{
		if (tfp->display_char_zero[j])
			write(1, &("\0"), 1);
		++j;
	}
}

void		ft_putstr_spe(t_ft_printf *tfp, char *str)
{
	int i;
	int	j;

	i = 0;
	j = 0;
	while (str[i])
	{
		while (j < tfp->actu_char_zero)
		{
			if (i == tfp->i_to_char_zero[j] && tfp->display_char_zero[j])
			{
				write(1, &("\0"), 1);
				tfp->display_char_zero[j] = FALSE;
			}
			++j;
		}
		ft_putchar_fd(str[i], 1);
		++i;
		j = 0;
	}
	ft_end(tfp);
}
