/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaucoul <vvaucoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/19 13:05:10 by vvaucoul          #+#    #+#             */
/*   Updated: 2019/12/29 16:27:02 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include "../libft/libft.h"

typedef	int	t_bool;
# define TRUE 1
# define FALSE 0

typedef struct	s_attribut
{
	char		*str;
	char		*actu_str;
	char		atb;
	int			n_char;
	int			n_char_displayed;
	int			width;
	t_bool		is_neg_width;
	t_bool		is_zeros;
	int			precision;
	t_bool		has_precision;
	t_bool		precision_is_neg;
	int			nb_is_neg;
	int			neg_printed;
	int			ptr_printed;
}				t_attribut;

typedef struct	s_ft_printf
{
	char		*str;
	char		*main_str;
	int			bonus_char;
	t_attribut	*atb;
	va_list		list;
	t_bool		*display_char_zero;
	int			*i_to_char_zero;
	int			actu_char_zero;
}				t_ft_printf;

/*
** main function
*/

int				ft_printf(const char *str, ...);

/*
** functions to parse
*/

int				ft_parser(t_ft_printf *tfp);
int				found_mod(t_ft_printf *tfp, int start);

int				ft_parse_neg(t_ft_printf *tfp, int *i);
int				ft_parse_width(t_ft_printf *tfp, char *tmp, int *i);
int				ft_parse_precision(t_ft_printf *tfp, char *tmp, int *i);
int				ft_parse_zeros(t_ft_printf *tfp, char *tmp, int *i);
int				ft_parse_first_star(t_ft_printf *tfp, int *i);

int				ft_parse_zeros_star(t_ft_printf *tfp, int *i);
int				ft_parse_precision_star(t_ft_printf *tfp, int *i);

/*
** manage display
*/

int				manage_putchar(t_ft_printf *tfp);
int				manage_putstr(t_ft_printf *tfp);
int				manage_putnbr(t_ft_printf *tfp);
int				manage_putunbr(t_ft_printf *tfp);
int				manage_putbase(t_ft_printf *tfp, t_bool up);
int				manage_putadress(t_ft_printf *tfp);
int				manage_mod(t_ft_printf *tfp);

int				ft_manage_spaces(t_ft_printf *tfp, int after, char space);
int				ft_manage_precision_str(t_ft_printf *tfp, char *str);
int				ft_manage_precision_nbr(t_ft_printf *tfp, char *str);

int				get_character_to_display_str(t_ft_printf *tfp, int len);
int				get_character_to_display_nbr(t_ft_printf *tfp, int len);
t_bool			can_display_char(t_ft_printf *tfp);
t_bool			char_can_be_parsed(char c);

/*
** manage main str
*/

int				ft_add_char(t_ft_printf *tfp, char c);
int				ft_add_neg(t_ft_printf *tfp);
int				ft_add_str(t_ft_printf *tfp, char *str);

/*
** macros
*/

t_bool			is_mod(char c);
t_bool			is_neg(char c);
t_bool			is_zero(char c);
t_bool			is_dot(char c);
t_bool			is_star(char c);

t_bool			is_format(char c);
t_bool			is_format_wm(char c);
t_bool			is_attribut(char c);

/*
** utils
*/

char			*ft_utoa(unsigned int n);
char			*ft_itoa_base(int nb, int base);
char			*ft_itoa_neg_base(int nb, int base);
char			*ft_strupper(char *str);
char			*ft_ultoa(unsigned long n);
char			*ft_realloc(char *ptr, int len);
int				ft_putaddress(t_ft_printf *tfp, void *in);
int				ft_ptrlen(void *in);
int				ft_add_ptr(t_ft_printf *tfp);
void			ft_putstr_spe(t_ft_printf *tfp, char *str);
#endif
