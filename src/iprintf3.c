/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iprintf3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehylee <jaehylee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 15:53:33 by jaehylee          #+#    #+#             */
/*   Updated: 2025/03/23 14:42:04 by jaehylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	iprintf3(const int fd, const t_fmt_arg *farg, const char *num)
{
	int	j;

	j = 0;
	if (farg->prec)
	{
		if (farg->min_width
			&& *(farg->min_width) > *(farg->prec) + isignof(num))
			j += uprint_pad(fd,
					*(farg->min_width) - *(farg->prec) - isignof(num));
		if (*(farg->prec) || *num != '0')
			j += iprints_(fd, farg, num);
		if (*(farg->prec) > idigit_len(num))
			j += iprint_padz(fd, *(farg->prec) - idigit_len(num));
		if (*(farg->prec) || *num != '0')
			j += iprint_digits(fd, num);
		return (j);
	}
	else
		return (iprintf4(fd, farg, num));
}

int	iprint_digits(const int fd, const char *num)
{
	int	j;

	j = 0;
	if (!isignof(num))
		j = (int)write(fd, num, ft_strlen(num));
	else
		j = (int)write(fd, num + 1, ft_strlen(num) - 1);
	return (j);
}

int	iprintf4(const int fd, const t_fmt_arg *farg, const char *num)
{
	int	j;

	j = 0;
	if (farg->flags && (farg->flags->blank || farg->flags->sign))
	{
		if (!farg->flags->adjust_left && !farg->flags->pad_zero
			&& farg->min_width
			&& *(farg->min_width) > idigit_len(num) + 1)
			j += uprint_pad(fd, *(farg->min_width) - idigit_len(num) - 1);
		j += iprints_(fd, farg, num);
		if (!farg->flags->adjust_left && farg->flags->pad_zero
			&& farg->min_width
			&& *(farg->min_width) > idigit_len(num) + 1)
			j += iprint_padz(fd, *(farg->min_width) - idigit_len(num) - 1);
		j += iprint_digits(fd, num);
		if (farg->flags->adjust_left && farg->min_width
			&& *(farg->min_width) > idigit_len(num) + 1)
			j += uprint_pad(fd, *(farg->min_width) - idigit_len(num) - 1);
		return (j);
	}
	return (iprintf5(fd, farg, num));
}

int	iprintf5(const int fd, const t_fmt_arg *farg, const char *num)
{
	int	j;

	j = 0;
	if (farg->flags)
	{
		if (!farg->flags->adjust_left && !farg->flags->pad_zero
			&& farg->min_width
			&& *(farg->min_width) > ft_strlen(num))
			j += uprint_pad(fd, *(farg->min_width) - ft_strlen(num));
		j += iprints_(fd, farg, num);
		if (!farg->flags->adjust_left && farg->flags->pad_zero
			&& farg->min_width
			&& *(farg->min_width) > ft_strlen(num))
			j += iprint_padz(fd, *(farg->min_width) - ft_strlen(num));
		j += iprint_digits(fd, num);
		if (farg->flags->adjust_left && farg->min_width
			&& *(farg->min_width) > ft_strlen(num))
			j += uprint_pad(fd, *(farg->min_width) - ft_strlen(num));
		return (j);
	}
	return (iprintf6(fd, farg, num));
}

int	iprintf6(const int fd, const t_fmt_arg *farg, const char *num)
{
	int		j;
	size_t	l;

	l = ft_strlen(num);
	j = 0;
	if (farg->min_width && *(farg->min_width) > l)
		j += uprint_pad(fd, *(farg->min_width) - l);
	j += (int)write(fd, num, l);
	return (j);
}
