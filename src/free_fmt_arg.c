/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_fmt_arg.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehylee <jaehylee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 14:55:16 by jaehylee          #+#    #+#             */
/*   Updated: 2024/10/16 14:55:25 by jaehylee         ###   ########.fr       */
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
	int	i;
	int	j;

	i = 0;
	if (farg->min_width)
	{
		if (farg->flags && farg->flags->adjust_left)
			i += (int)write(STDOUT_FILENO, "%", 1);
		j = -1;
		while ((size_t)++j < *(farg->min_width))
			i += (int)write(STDOUT_FILENO, " ", 1);
		if (!(farg->flags && farg->flags->adjust_left))
			i += (int)write(STDOUT_FILENO, " ", 1);
		return (*(farg->min_width));
	}
	else
		return ((int)write(STDOUT_FILENO, "%", 1));
}

int	sprint_f(const t_fmt_arg *farg, const char *str)
{
	int	j;

	j = 0;
	if (farg->min_width && *(farg->min_width) > ft_strlen(str))
	{
		if (farg->flags && farg->flags->adjust_left)
			j += (int)write(STDOUT_FILENO, str, ft_strlen(str));
		j += uprint_pad(*(farg->min_width) - ft_strlen(str));
		if (!(farg->flags && farg->flags->adjust_left))
			j += (int)write(STDOUT_FILENO, str, ft_strlen(str));
		return (j);
	}
	else
		return ((int)write(STDOUT_FILENO, str, ft_strlen(str)));
}

int	uprintf(const t_fmt_arg *farg, const char *num)
{
	int	j;

	j = 0;
	if (farg->prec)
	{
		if (!(farg->flags && farg->flags->adjust_left)
			&& farg->min_width && *(farg->min_width) > *(farg->prec))
			j += uprint_pad(*(farg->min_width) - *(farg->prec));
		if (*(farg->prec) > ft_strlen(num))
			j += uprint_padz(*(farg->prec) - ft_strlen(num));
		j += (int)write(STDOUT_FILENO, num, ft_strlen(num));
		if (farg->flags && farg->flags->adjust_left
			&& farg->min_width && *(farg->min_width) > *(farg->prec))
			j += uprint_pad(*(farg->min_width) - *(farg->prec));
		return (j);
	}
	else
		return (uprintf2(farg, num));
}
