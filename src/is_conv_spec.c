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
	arg->flags = init_flags();
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
	arg->min_width = (size_t *)ft_calloc(1, sizeof(size_t));
	if (arg->min_width == NULL)
		return;
	*(arg->min_width) = ft_atoul(sub_str);
}

void	parse_prec(const char *fmt, t_fmt_arg *arg, size_t *i)
{
	size_t	j;
	char	*sub_str;
	long	l;

	if (fmt[*i] != '.' && ft_isdigit(fmt[*i + 1]) && fmt[*i + 1] != '-')
		return ;
	j = ++(*i);
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
	arg->prec = (size_t *)ft_calloc(1, sizeof(size_t));
	if (arg->prec == NULL)
		return;
	*(arg->prec) = l;
}

t_fmt_arg	*init_fmt_arg(void)
{
	t_fmt_arg	*arg;

	arg = (t_fmt_arg *)ft_calloc(1, sizeof(t_fmt_arg));
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
