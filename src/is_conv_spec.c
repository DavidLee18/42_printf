/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_conv_spec.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehylee <jaehylee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 09:00:10 by jaehylee          #+#    #+#             */
/*   Updated: 2024/10/14 09:00:10 by jaehylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

_Bool	is_conv_spec(const char c)
{
	return (c == 'c' || c == 's'
		|| c == 'p' || c == 'd' || c == 'i'
		|| c == 'u' || c == 'x' || c == 'X'
		|| c == '%');
}

void	preproc_flags(const char *fmt, t_fmt_arg *arg, size_t *i)
{
	if (!(fmt[*i] == '#' || fmt[*i] == '0' || fmt[*i] == '-'
			|| fmt[*i] == ' ' || fmt[*i] == '+'))
		return ;
	arg->flags = (t_flags *)ft_calloc(1, sizeof(t_flags));
	if (arg->flags == NULL)
		return ;
	while (fmt[*i] == '#' || fmt[*i] == '0' || fmt[*i] == '-'
		|| fmt[*i] == ' ' || fmt[*i] == '+')
	{
		if (fmt[*i] == '#')
			arg->flags->alt_form = 1;
		if (fmt[*i] == '0')
			arg->flags->pad_zero = 1;
		if (fmt[*i] == '-')
			arg->flags->adjust_left = 1;
		if (fmt[*i] == ' ')
			arg->flags->blank = 1;
		if (fmt[*i] == '+')
			arg->flags->sign = 1;
		(*i)++;
	}
	return ;
}

void	parse_width(const char *fmt, t_fmt_arg *arg, size_t *i)
{
	size_t	j;
	char	*sub_str;

	if (fmt[*i] < '1' || fmt[*i] > '9')
		return ;
	j = *i;
	while (fmt[*i] >= '1' && fmt[*i] <= '9')
		(*i)++;
	sub_str = ft_substr(fmt, j, *i - j + 1);
	if (sub_str == NULL)
		return ;
	arg->min_width = ft_atoul(sub_str);
}

void	parse_prec(const char *fmt, t_fmt_arg *arg, size_t *i)
{
	size_t	j;
	char	*sub_str;
	long	l;

	if (ft_isdigit(fmt[*i]) && fmt[*i] != '-')
		return ;
	j = *i;
	if (fmt[*i] == '-')
		(*i)++;
	while (fmt[*i] >= '0' && fmt[*i] <= '9')
		(*i)++;
	sub_str = ft_substr(fmt, j, *i - j + 1);
	if (sub_str == NULL)
		return ;
	l = ft_atol(sub_str);
	if (l < 0)
		l = 0;
	*(arg->prec) = l;
}
