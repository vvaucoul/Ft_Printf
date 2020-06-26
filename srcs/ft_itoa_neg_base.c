/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_neg_base.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaucoul <vvaucoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 12:53:20 by vvaucoul          #+#    #+#             */
/*   Updated: 2019/12/23 17:28:20 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_itoa_neg_base(int nb, int base)
{
	unsigned int	tmp_nb;
	char			*str_base;
	char			*final_nb;
	int				nb_count;
	int				i;

	tmp_nb = nb;
	str_base = ft_strdup("0123456789abcdef");
	nb_count = 8;
	final_nb = ft_strdup("ffffffff");
	i = 1;
	while (tmp_nb)
	{
		final_nb[nb_count - i] = str_base[tmp_nb % base];
		tmp_nb /= base;
		++i;
	}
	free(str_base);
	return (final_nb);
}
