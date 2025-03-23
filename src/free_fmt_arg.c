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

t_flags	*init_flags(t_list **dyn)
{
	t_flags	*f;

	f = (t_flags *)gc_calloc(dyn, 1, sizeof(t_flags));
	if (!f)
		return (NULL);
	f->adjust_left = 0;
	f->alt_form = 0;
	f->blank = 0;
	f->pad_zero = 0;
	f->sign = 0;
	return (f);
}

int	print_per(const int fd, const t_fmt_arg *farg)
{
	int	i;
	int	j;

	i = 0;
	if (farg->min_width)
	{
		if (farg->flags && farg->flags->adjust_left)
			i += (int)write(fd, "%", 1);
		j = -1;
		while ((size_t)++j < *(farg->min_width))
			i += (int)write(fd, " ", 1);
		if (!(farg->flags && farg->flags->adjust_left))
			i += (int)write(fd, " ", 1);
		return (i);
	}
	else
		return ((int)write(fd, "%", 1));
}

int	sprint_f(const int fd, const t_fmt_arg *farg, const char *str)
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
			j += (int)write(fd, str, l);
		j += uprint_pad(fd, *(farg->min_width) - l);
		if (!(farg->flags && farg->flags->adjust_left))
			j += (int)write(fd, str, l);
		return (j);
	}
	else if (l > 0)
		return ((int)write(fd, str, l));
	else
		return (0);
}

int	uprintf(const int fd, const t_fmt_arg *farg, const char *num)
{
	int		j;
	size_t	l;

	j = 0;
	if (farg->prec)
	{
		l = usize_max(ft_strlen(num) - (*num == '0'),
				*(farg->prec) + isignof(num));
		if (!(farg->flags && farg->flags->adjust_left)
			&& farg->min_width && *(farg->min_width) > l)
			j += uprint_pad(fd, *(farg->min_width) - l);
		if (*(farg->prec) > ft_strlen(num))
			j += uprint_padz(fd, *(farg->prec) - ft_strlen(num));
		if (*(farg->prec) || *num != '0')
			j += (int)write(fd, num, ft_strlen(num));
		if (farg->flags && farg->flags->adjust_left
			&& farg->min_width && *(farg->min_width) > l)
			j += uprint_pad(fd, *(farg->min_width) - l);
		return (j);
	}
	else
		return (uprintf2(fd, farg, num));
}

int	print_vec2(t_list **dyn, int fd, const t_fmt_arg *farg, t_vec v)
{
	size_t	i;
	int		j;
	char	*str;

	j = 0;
	if (farg->flags == NULL || !farg->flags->adjust_left)
	{
		i = 0;
		while (++i <= v.len)
		{
			str = gc_itoa(dyn, v.ptr[i - 1]);
			if (str == NULL)
				return (-1);
			j += (int)write(fd, str, ft_strlen(str));
			if (i != v.len)
				j += (int)write(fd, ", ", 2);
		}
	}
	j += (int)write(fd, "]", 1);
	return (j);
}
