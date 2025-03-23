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
		|| c == '%' || c == 'v');
}

void	preproc_flags(t_list **dyn, const char *fmt, t_fmt_arg *arg, size_t *i)
{
	if (!(fmt[*i] == '#' || fmt[*i] == '0' || fmt[*i] == '-'
			|| fmt[*i] == ' ' || fmt[*i] == '+'))
		return ;
	arg->flags = init_flags(dyn);
	if (arg->flags == NULL)
		return ;
	while (fmt[*i] == '#' || fmt[*i] == '0' || fmt[*i] == '-'
		|| fmt[*i] == ' ' || fmt[*i] == '+')
	{
		arg->flags->alt_form += (fmt[*i] == '#');
		arg->flags->pad_zero += (fmt[*i] == '0');
		arg->flags->adjust_left += (fmt[*i] == '-');
		arg->flags->blank += (fmt[*i] == ' ');
		arg->flags->sign += (fmt[*i] == '+');
		(*i)++;
	}
}

void	parse_width(t_list **dyn, const char *fmt, t_fmt_arg *arg, size_t *i)
{
	size_t	j;
	size_t	k;
	char	*sub_str;

	if (fmt[*i] < '1' || fmt[*i] > '9')
		return ;
	j = *i;
	while (ft_isdigit(fmt[*i]))
		(*i)++;
	sub_str = gc_substr(dyn, fmt, j, *i - j);
	if (sub_str == NULL)
		return ;
	k = ft_atoul(sub_str);
	arg->min_width = (size_t *)gc_calloc(dyn, 1, sizeof(size_t));
	if (arg->min_width == NULL)
		return ;
	*(arg->min_width) = k;
}

void	parse_prec(t_list **dyn, const char *fmt, t_fmt_arg *arg, size_t *i)
{
	size_t	j;
	char	*sub_str;
	size_t	l;

	if (fmt[*i] != '.')
		return ;
	j = ++(*i);
	if (fmt[*i] == '-')
		return ;
	while (fmt[*i] >= '0' && fmt[*i] <= '9')
		(*i)++;
	sub_str = gc_substr(dyn, fmt, j, *i - j);
	if (sub_str == NULL)
		return ;
	l = 0;
	if (ft_strlen(sub_str) != 0)
		l = ft_atoul(sub_str);
	arg->prec = (size_t *)gc_calloc(dyn, 1, sizeof(size_t));
	if (arg->prec == NULL)
		return ;
	*(arg->prec) = l;
}

t_fmt_arg	*init_fmt_arg(t_list **dyn)
{
	t_fmt_arg	*arg;

	arg = (t_fmt_arg *)gc_calloc(dyn, 1, sizeof(t_fmt_arg));
	if (arg == NULL)
		return (NULL);
	arg->conv_spec = 0;
	arg->end = 0;
	arg->flags = NULL;
	arg->min_width = NULL;
	arg->prec = NULL;
	arg->start = 0;
	return (arg);
}
