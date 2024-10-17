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

int	vprint_per(const t_fmt_arg *farg, va_list args)
{
	int	i;
	int	j;

	if (farg->min_width)
	{
		if (farg->flags && farg->flags->adjust_left)
			i = (int)write(STDOUT_FILENO, "%", 1);
		j = -1;
		while (i > 0 && ++j < *(farg->min_width))
			i = (int)write(STDOUT_FILENO, " ", 1);
		if (i > 0 && !(farg->flags && farg->flags->adjust_left))
			i = (int)write(STDOUT_FILENO, " ", 1);
		return (*(farg->min_width));
	}
	else
		return ((int)write(STDOUT_FILENO, "%", 1));
}

int	vprint_str_flags(const t_fmt_arg *farg, const char *str)
{
	int		i;
	char	*temp;
	int		j;

	i = -1;
	if (farg->prec && *(farg->prec) < ft_strlen(str))
		temp = ft_substr(str, 0, *(farg->prec));
	else
		temp = ft_strdup(str);
	if (farg->min_width && *(farg->min_width) > ft_strlen(temp))
	{
		if (farg->flags->adjust_left && ft_strlen(temp) > 0)
			j = (int)write(STDOUT_FILENO, temp, ft_strlen(temp));
		while (j > 0 && ++i < *(farg->min_width) - ft_strlen(temp))
			j = (int)write(STDOUT_FILENO, " ", 1);
		if (j > 0 && !farg->flags->adjust_left && ft_strlen(temp) > 0)
			j = (int)write(STDOUT_FILENO, temp, ft_strlen(temp));
		return (j);
	}
	else
		return ((int)write(STDOUT_FILENO, temp, ft_strlen(temp)));
}
