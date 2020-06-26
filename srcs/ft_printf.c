/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaucoul <vvaucoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/19 13:07:45 by vvaucoul          #+#    #+#             */
/*   Updated: 2019/12/27 18:01:51 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_ft_printf		*init_struct_tfp(const char *str)
{
	t_ft_printf *tfp;

	if ((tfp = (t_ft_printf *)malloc(sizeof(t_ft_printf))) == NULL)
		return (NULL);
	tfp->str = ft_strdup(str);
	if ((tfp->main_str = ft_calloc(1, sizeof(char))) == NULL)
		return (NULL);
	tfp->bonus_char = 0;
	if ((tfp->i_to_char_zero = (int *)malloc(sizeof(int) * 99)) == NULL)
		return (NULL);
	if ((tfp->display_char_zero = (t_bool *)malloc(sizeof(t_bool) * 99))
		== NULL)
		return (NULL);
	tfp->actu_char_zero = 0;
	return (tfp);
}

int				output_printf(t_ft_printf *tfp)
{
	int len;

	len = ft_strlen(tfp->main_str) + tfp->bonus_char;
	ft_putstr_spe(tfp, tfp->main_str);
	free(tfp->display_char_zero);
	free(tfp->i_to_char_zero);
	free(tfp->str);
	free(tfp->main_str);
	free(tfp);
	return (len);
}

int				ft_printf(const char *str, ...)
{
	t_ft_printf *tfp;

	if ((tfp = init_struct_tfp(str)) == NULL)
		return (-1);
	va_start(tfp->list, str);
	if ((ft_parser(tfp)) == -1)
		return (-1);
	va_end(tfp->list);
	return (output_printf(tfp));
}
