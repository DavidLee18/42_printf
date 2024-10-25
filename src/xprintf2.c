/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xprintf2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehylee <jaehylee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 12:04:08 by jaehylee          #+#    #+#             */
/*   Updated: 2024/10/25 12:05:56 by jaehylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	xprintf2(const t_fmt_arg *farg, const char *num)
{
	int	j;

	j = 0;
	if (farg->prec)
	{
		if (!(farg->flags && farg->flags->adjust_left)
			&& farg->min_width && *(farg->min_width) > *(farg->prec))
			j = uprint_pad(*(farg->min_width) - *(farg->prec));
		if (j >= 0 && *(farg->prec) > ft_strlen(num))
			j = uprint_padz(*(farg->prec) - ft_strlen(num));
		if (j > 0)
			j = (int)write(STDOUT_FILENO, num, ft_strlen(num));
		if (farg->flags && farg->flags->adjust_left
			&& farg->min_width && *(farg->min_width) > *(farg->prec))
			j = uprint_pad(*(farg->min_width) - *(farg->prec));
		return (j);
	}
	return (xprintf3(farg, num));
}

int	xprintf3(const t_fmt_arg *farg, const char *num)
{
	int	j;

	j = 0;
	if (farg->flags && farg->flags->alt_form)
	{
		if (!farg->flags->adjust_left && farg->min_width && *(farg->min_width)
			> ft_strlen(num) + 2 && !farg->flags->pad_zero)
			j = uprint_pad(*(farg->min_width) - ft_strlen(num) - 2);
		if (j >= 0)
			j = (int)write(STDOUT_FILENO, "0", 1);
		if (j > 0)
			j = (int)write(STDOUT_FILENO, &farg->conv_spec, 1);
		if (!farg->flags->adjust_left && farg->min_width
			&& *(farg->min_width) > ft_strlen(num) + 2 && farg->flags->pad_zero)
			j = uprint_padz(*(farg->min_width) - ft_strlen(num) - 2);
		if (j > 0)
			j = (int)write(STDOUT_FILENO, num, ft_strlen(num));
		if (j > 0 && farg->flags->adjust_left && farg->min_width
			&& *(farg->min_width) > ft_strlen(num) + 2)
			j = uprint_pad(*(farg->min_width) - ft_strlen(num) - 2);
		return (j);
	}
	return (xprintf4(farg, num));
}

int	xprintf4(const t_fmt_arg *farg, const char *num)
{
	int	j;

	j = 0;
	if (farg->flags)
	{
		if (!farg->flags->adjust_left && farg->min_width
			&& *(farg->min_width) > ft_strlen(num)
			&& !farg->flags->pad_zero)
			j = uprint_pad(*(farg->min_width) - ft_strlen(num));
		else if (!farg->flags->adjust_left && farg->min_width
			&& *(farg->min_width) > ft_strlen(num) && farg->flags->pad_zero)
			j = uprint_padz(*(farg->min_width) - ft_strlen(num));
		if (j > 0)
			j = (int)write(STDOUT_FILENO, num, ft_strlen(num));
		if (j > 0 && farg->flags->adjust_left && farg->min_width
			&& *(farg->min_width) > ft_strlen(num))
			j = uprint_pad(*(farg->min_width) - ft_strlen(num));
		return (j);
	}
	return (xprintf5(farg, num));
}

int	xprintf5(const t_fmt_arg *farg, const char *num)
{
	int		j;
	size_t	l;

	j = 0;
	l = ft_strlen(num);
	if (farg->min_width && *(farg->min_width) > l)
		j = uprint_pad(*(farg->min_width) - l);
	if (j >= 0)
		j = (int)write(STDOUT_FILENO, num, l);
	return (j);
}

char	*ultoa(const unsigned long p)
{
	char			*str;
	unsigned long	l;
	unsigned long	i;
	unsigned long	p_;

	p_ = p;
	l = ullog(10, p_);
	str = (char *)ft_calloc(l + 2, sizeof(char));
	if (!str)
		return (NULL);
	str[l + 1] = 0;
	i = 0;
	while (i < l)
	{
		str[l - i - 1] = '0' + p_ % 10;
		p_ /= 10;
		i++;
	}
	return (str);
}
