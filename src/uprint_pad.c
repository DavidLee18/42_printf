/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   uprint_pad.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehylee <jaehylee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 15:10:18 by jaehylee          #+#    #+#             */
/*   Updated: 2024/10/17 15:10:18 by jaehylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	uprint_pad(const int fd, const size_t len)
{
	int		j;
	size_t	i;

	i = 0;
	j = 0;
	while (i < len)
	{
		j += (int)write(fd, " ", 1);
		i++;
	}
	return (j);
}

int	uprint_padz(const int fd, const size_t len)
{
	size_t	i;
	int		j;

	j = 0;
	i = 0;
	while (i < len)
	{
		j += (int)write(fd, "0", 1);
		i++;
	}
	return (j);
}

int	uprintf2(const int fd, const t_fmt_arg *farg, const char *num)
{
	int	j;

	j = 0;
	if (farg->flags)
	{
		if (farg->flags->adjust_left)
		{
			j += (int)write(fd, num, ft_strlen(num));
			if (farg->min_width
				&& *(farg->min_width) > ft_strlen(num))
				j += uprint_pad(fd, *(farg->min_width) - ft_strlen(num));
			return (j);
		}
		else if (farg->flags->pad_zero && farg->min_width
			&& *(farg->min_width) > ft_strlen(num))
			return (j + uprint_padz(fd, *(farg->min_width) - ft_strlen(num))
				+ (int)write(fd, num, ft_strlen(num)));
	}
	else if (farg->min_width && *(farg->min_width) > ft_strlen(num))
		j += uprint_pad(fd, *(farg->min_width) - ft_strlen(num));
	j += (int)write(fd, num, ft_strlen(num));
	return (j);
}

int	xprintf(const int fd, const t_fmt_arg *farg, const char *num)
{
	int	j;

	j = 0;
	if (farg->prec && farg->flags && farg->flags->alt_form)
	{
		if (!farg->flags->adjust_left && farg->min_width && *(farg->min_width)
			> *(farg->prec) + 2)
			j += uprint_pad(fd, *(farg->min_width) - *(farg->prec) - 2);
		if (*(farg->prec) || *num != '0')
			j += (int)write(fd, "0", 1);
		if (*(farg->prec) || *num != '0')
			j += (int)write(fd, &farg->conv_spec, 1);
		if (*(farg->prec) > ft_strlen(num))
			j += uprint_padz(fd, *(farg->prec) - ft_strlen(num));
		if (*(farg->prec) || *num != '0')
			j += (int)write(fd, num, ft_strlen(num));
		if (farg->flags->adjust_left && farg->min_width
			&& *(farg->min_width) > *(farg->prec) + 2)
			j += uprint_pad(fd, *(farg->min_width) - *(farg->prec) - 2);
		return (j);
	}
	else
		return (xprintf2(fd, farg, num));
}

int	print_vec(t_list **dyn, int fd, const t_fmt_arg *farg, va_list args)
{
	t_vec	v;
	size_t	i;
	int		j;
	char	*str;

	v = va_arg(args, t_vec);
	j = (int)write(fd, "vec[", 4);
	if (j < 0)
		return (j);
	if (farg->flags && farg->flags->adjust_left)
	{
		i = v.len;
		while (i > 0)
		{
			str = gc_itoa(dyn, v.ptr[i - 1]);
			if (str == NULL)
				return (-1);
			j += (int)write(fd, str, ft_strlen(str));
			if (i != 1)
				j += (int)write(fd, ", ", 2);
			i--;
		}
	}
	return (j + print_vec2(dyn, fd, farg, v));
}
