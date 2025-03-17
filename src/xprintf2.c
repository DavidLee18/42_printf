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

int	xprintf2(const int fd, const t_fmt_arg *farg, const char *num)
{
	int		j;
	size_t	l;

	j = 0;
	if (farg->prec)
	{
		l = usize_max(ft_strlen(num) - (*num == '0'), *(farg->prec));
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
	return (xprintf3(fd, farg, num));
}

int	xprintf3(const int fd, const t_fmt_arg *farg, const char *num)
{
	int	j;

	j = 0;
	if (farg->flags && farg->flags->alt_form)
	{
		if (!farg->flags->adjust_left && farg->min_width && *(farg->min_width)
			> ft_strlen(num) + 2 && !farg->flags->pad_zero)
			j += uprint_pad(fd, *(farg->min_width) - ft_strlen(num) - 2);
		if (*num != '0')
			j += (int)write(fd, "0", 1);
		if (*num != '0')
			j += (int)write(fd, &farg->conv_spec, 1);
		if (!farg->flags->adjust_left && farg->min_width
			&& *(farg->min_width) > ft_strlen(num) + 2 && farg->flags->pad_zero)
			j += uprint_padz(fd, *(farg->min_width) - ft_strlen(num) - 2);
		j += (int)write(fd, num, ft_strlen(num));
		if (farg->flags->adjust_left && farg->min_width
			&& *(farg->min_width) > ft_strlen(num) + 2)
			j += uprint_pad(fd, *(farg->min_width) - ft_strlen(num) - 2);
		return (j);
	}
	return (xprintf4(fd, farg, num));
}

int	xprintf4(const int fd, const t_fmt_arg *farg, const char *num)
{
	int	j;

	j = 0;
	if (farg->flags)
	{
		if (!farg->flags->adjust_left && farg->min_width
			&& *(farg->min_width) > ft_strlen(num)
			&& !farg->flags->pad_zero)
			j += uprint_pad(fd, *(farg->min_width) - ft_strlen(num));
		else if (!farg->flags->adjust_left && farg->min_width
			&& *(farg->min_width) > ft_strlen(num) && farg->flags->pad_zero)
			j += uprint_padz(fd, *(farg->min_width) - ft_strlen(num));
		j += (int)write(fd, num, ft_strlen(num));
		if (farg->flags->adjust_left && farg->min_width
			&& *(farg->min_width) > ft_strlen(num))
			j += uprint_pad(fd, *(farg->min_width) - ft_strlen(num));
		return (j);
	}
	return (xprintf5(fd, farg, num));
}

int	xprintf5(const int fd, const t_fmt_arg *farg, const char *num)
{
	int		j;
	size_t	l;

	j = 0;
	l = ft_strlen(num);
	if (farg->min_width && *(farg->min_width) > l)
		j += uprint_pad(fd, *(farg->min_width) - l);
	j += (int)write(fd, num, l);
	return (j);
}

char	*ulltox(t_list **dyn, const unsigned long long p)
{
	char				*str;
	unsigned long long	l;
	unsigned long long	i;
	unsigned long long	p_;

	p_ = p;
	l = ulllog(16, p_);
	str = (char *)gc_calloc(dyn, l + 2, sizeof(char));
	if (!str)
		return (NULL);
	str[l + 1] = 0;
	i = 0;
	while (i <= l)
	{
		str[l - i] = "0123456789abcdef"[p_ % 16];
		p_ /= 16;
		i++;
	}
	return (str);
}
