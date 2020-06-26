/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaucoul <vvaucoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 16:25:51 by vvaucoul          #+#    #+#             */
/*   Updated: 2019/12/20 15:31:26 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_intlen_base(int nb, int base)
{
	int	len;

	len = 0;
	while (nb)
	{
		nb /= base;
		++len;
	}
	return (len);
}

char	*ft_calcul_base(int nb, int base, int is_neg)
{
	char	*str_base;
	char	*final_nb;
	int		nb_count;
	int		i;

	str_base = ft_strdup("0123456789abcdef");
	nb_count = ft_intlen_base(nb, base);
	nb_count += is_neg == 1 ? 1 : 0;
	final_nb = malloc(sizeof(char) * nb_count + 1);
	i = 1;
	is_neg == 1 ? (final_nb[0] = '-') : 0;
	while (nb)
	{
		final_nb[nb_count - i] = str_base[nb % base];
		nb /= base;
		++i;
	}
	final_nb[nb_count] = '\0';
	free(str_base);
	return (final_nb);
}

char	*ft_itoa_base(int nb, int base)
{
	int		is_neg;

	is_neg = 0;
	if (base < 2 || base > 16)
		return (0);
	if (base == 10 && nb == -2147483648)
		return ("-2147483648");
	if (nb == 0)
		return ("0");
	if (nb < 0)
	{
		return (ft_itoa_neg_base(nb, base));
		nb *= -1;
		if (base == 10)
			is_neg = 1;
	}
	else
		is_neg = 0;
	return (ft_calcul_base(nb, base, is_neg));
}
