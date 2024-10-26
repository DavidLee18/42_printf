/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iprintf3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehylee <jaehylee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 15:53:33 by jaehylee          #+#    #+#             */
/*   Updated: 2024/10/24 15:53:33 by jaehylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	iprintf3(const t_fmt_arg *farg, const char *num)
{
	int	j;

	j = 0;
	if (farg->prec)
	{
		if (farg->min_width
			&& *(farg->min_width) > *(farg->prec) + isignof(num))
			j += uprint_pad(*(farg->min_width) - *(farg->prec) - isignof(num));
		j += iprints_(farg, j, num);
		if (*(farg->prec) > idigit_len(num))
			j += iprint_padz(*(farg->prec) - idigit_len(num));
		j += iprint_digits(num);
		return (j);
	}
	else
		return (iprintf4(farg, num));
}

int	iprint_digits(const char *num)
{
	int	j;

	j = 0;
	if (!isignof(num))
		j = (int)write(STDOUT_FILENO, num, ft_strlen(num));
	else
		j = (int)write(STDOUT_FILENO, num + 1, ft_strlen(num) - 1);
	return (j);
}

int	iprintf4(const t_fmt_arg *farg, const char *num)
{
	int	j;

	j = 0;
	if (farg->flags && (farg->flags->blank || farg->flags->sign))
	{
		if (!farg->flags->adjust_left && !farg->flags->pad_zero
			&& farg->min_width
			&& *(farg->min_width) > idigit_len(num) + 1)
			j += uprint_pad(*(farg->min_width) - idigit_len(num) - 1);
		j += iprints_(farg, j, num);
		if (!farg->flags->adjust_left && farg->flags->pad_zero
			&& farg->min_width
			&& *(farg->min_width) > idigit_len(num) + 1)
			j += iprint_padz(*(farg->min_width) - idigit_len(num) - 1);
		j += iprint_digits(num);
		if (farg->flags->adjust_left && farg->min_width
			&& *(farg->min_width) > idigit_len(num) + 1)
			j += uprint_pad(*(farg->min_width) - idigit_len(num) - 1);
		return (j);
	}
	return (iprintf5(farg, num));
}

int	iprintf5(const t_fmt_arg *farg, const char *num)
{
	int	j;

	j = 0;
	if (farg->flags)
	{
		if (!farg->flags->adjust_left && !farg->flags->pad_zero
			&& farg->min_width
			&& *(farg->min_width) > ft_strlen(num))
			j += uprint_pad(*(farg->min_width) - ft_strlen(num));
		j += iprints_(farg, j, num);
		if (!farg->flags->adjust_left && farg->flags->pad_zero
			&& farg->min_width
			&& *(farg->min_width) > ft_strlen(num))
			j += iprint_padz(*(farg->min_width) - ft_strlen(num));
		j += iprint_digits(num);
		if (farg->flags->adjust_left && farg->min_width
			&& *(farg->min_width) > ft_strlen(num))
			j += uprint_pad(*(farg->min_width) - ft_strlen(num));
		return (j);
	}
	return (iprintf6(farg, num));
}

int	iprintf6(const t_fmt_arg *farg, const char *num)
{
	int		j;
	size_t	l;

	l = ft_strlen(num);
	j = 0;
	if (farg->min_width && *(farg->min_width) > l)
		j += uprint_pad(*(farg->min_width) - l);
	j += (int)write(STDOUT_FILENO, num, l);
	return (j);
}
