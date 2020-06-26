/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_attribut.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaucoul <vvaucoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/19 13:52:29 by vvaucoul          #+#    #+#             */
/*   Updated: 2019/12/27 18:01:11 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				parse_line(t_ft_printf *tfp)
{
	char	*tmp;
	int		i;
	int		j;

	i = 0;
	j = 0;
	tmp = NULL;
	if ((tmp = malloc(sizeof(char) * ft_strlen(tfp->str + 1))) == NULL)
		return (-1);
	ft_parse_first_star(tfp, &i);
	ft_parse_neg(tfp, &i);
	ft_parse_width(tfp, tmp, &i);
	ft_parse_zeros(tfp, tmp, &i);
	ft_parse_precision(tfp, tmp, &i);
	tfp->atb->atb = tfp->atb->str[i];
	if (tfp->atb->has_precision)
		tfp->atb->is_zeros = 0;
	free(tmp);
	free(tfp->atb->str);
	return (0);
}

int				sub_string_parse_spaces(t_ft_printf *tfp, int *i, int *n_spaces)
{
	while (tfp->str[i[0]] == ' ' && tfp->str[i[0]])
	{
		++i[0];
		++n_spaces[0];
	}
	if (n_spaces[0] > 0 && char_can_be_parsed(tfp->str[i[0]]))
	{
		if ((ft_add_char(tfp, ' ')) == -1)
			return (-1);
	}
	while (!is_format(tfp->str[i[0]]) && tfp->str[i[0]])
		++i[0];
	return (0);
}

int				sub_string(t_ft_printf *tfp, const int start)
{
	int i;
	int j;
	int	n_spaces;

	i = start;
	j = 0;
	n_spaces = 0;
	if ((sub_string_parse_spaces(tfp, &i, &n_spaces)) == -1)
		return (-1);
	if ((tfp->atb->str = malloc(sizeof(char) * (i - start) + 2)) == NULL)
		return (-1);
	i = start + n_spaces;
	while (!is_format(tfp->str[i + j]) && tfp->str[i + j] &&
	char_can_be_parsed(tfp->str[i + j]))
	{
		tfp->atb->str[j] = tfp->str[i + j];
		++j;
	}
	tfp->atb->str[j] = tfp->str[i + j];
	tfp->atb->str[j + 1] = '\0';
	if (!char_can_be_parsed(tfp->str[i + j]))
		--j;
	return (start + j + n_spaces);
}

t_attribut		*init_struct_atb(t_ft_printf *tfp)
{
	if ((tfp->atb = (t_attribut *)malloc(sizeof(t_attribut))) == NULL)
		return (NULL);
	else
	{
		tfp->atb->width = 0;
		tfp->atb->is_neg_width = FALSE;
		tfp->atb->is_zeros = FALSE;
		tfp->atb->precision = 0;
		tfp->atb->has_precision = FALSE;
		tfp->atb->n_char = 0;
		tfp->atb->n_char_displayed = 0;
		tfp->atb->nb_is_neg = FALSE;
		tfp->atb->precision_is_neg = FALSE;
		tfp->atb->neg_printed = 0;
		tfp->atb->ptr_printed = 0;
	}
	return (tfp->atb);
}

int				found_mod(t_ft_printf *tfp, int start)
{
	int next_i;

	if ((tfp->atb = init_struct_atb(tfp)) == NULL)
		return (-1);
	if ((next_i = sub_string(tfp, start)) == -1)
		return (-1);
	if ((parse_line(tfp)) == -1)
		return (-1);
	return (next_i);
}
