/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_fmt_arg.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehylee <jaehylee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 14:55:16 by jaehylee          #+#    #+#             */
/*   Updated: 2025/03/15 16:57:34 by jaehylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	free_fmt_arg(t_fmt_arg *arg)
{
	if (!arg)
		return ;
	if (arg->flags)
		free(arg->flags);
	if (arg->min_width)
		free(arg->min_width);
	if (arg->prec)
		free(arg->prec);
	free(arg);
}

t_flags	*init_flags(void)
{
	t_flags	*f;

	f = (t_flags *)ft_calloc(1, sizeof(t_flags));
	if (!f)
		return (NULL);
	f->adjust_left = 0;
	f->alt_form = 0;
	f->blank = 0;
	f->pad_zero = 0;
	f->sign = 0;
	return (f);
}

int	print_per(const t_fmt_arg *farg)
{
	int	j;

	if (farg->min_width)
	{
		if (farg->flags && farg->flags->adjust_left)
			write(STDOUT_FILENO, "%", 1);
		j = -1;
		while ((size_t)++j < *(farg->min_width))
			write(STDOUT_FILENO, " ", 1);
		if (!(farg->flags && farg->flags->adjust_left))
			write(STDOUT_FILENO, " ", 1);
		return (*(farg->min_width));
	}
	else
		return ((int)write(STDOUT_FILENO, "%", 1));
}

int	sprint_f(const t_fmt_arg *farg, const char *str)
{
	int		j;
	size_t	l;

	j = 0;
	if (!str || !*str)
		l = 0;
	else
		l = ft_strlen(str);
	if (farg->min_width && *(farg->min_width) > l)
	{
		if (farg->flags && farg->flags->adjust_left)
			j += (int)write(STDOUT_FILENO, str, l);
		j += uprint_pad(*(farg->min_width) - l);
		if (!(farg->flags && farg->flags->adjust_left))
			j += (int)write(STDOUT_FILENO, str, l);
		return (j);
	}
	else if (l > 0)
		return ((int)write(STDOUT_FILENO, str, l));
	else
		return (0);
}

int	uprintf(const t_fmt_arg *farg, const char *num)
{
	int		j;
	size_t	l;

	j = 0;
	if (farg->prec)
	{
		l = ft_max(ft_strlen(num) - (*num == '0'),
				*(farg->prec) + isignof(num));
		if (!(farg->flags && farg->flags->adjust_left)
			&& farg->min_width && *(farg->min_width) > l)
			j += uprint_pad(*(farg->min_width) - l);
		if (*(farg->prec) > ft_strlen(num))
			j += uprint_padz(*(farg->prec) - ft_strlen(num));
		if (*(farg->prec) || *num != '0')
			j += (int)write(STDOUT_FILENO, num, ft_strlen(num));
		if (farg->flags && farg->flags->adjust_left
			&& farg->min_width && *(farg->min_width) > l)
			j += uprint_pad(*(farg->min_width) - l);
		return (j);
	}
	else
		return (uprintf2(farg, num));
}
