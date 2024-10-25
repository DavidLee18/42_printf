/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iprints_.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehylee <jaehylee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 11:33:18 by jaehylee          #+#    #+#             */
/*   Updated: 2024/10/18 11:33:18 by jaehylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	iprints_(const t_fmt_arg *farg, const int j, const char *num)
{
	if (j < 0)
		return (j);
	else if (farg->flags->sign && ft_isdigit(*num))
		return ((int)write(STDOUT_FILENO, "+", 1));
	else if (*num == '-')
		return ((int)write(STDOUT_FILENO, "-", 1));
	else if (farg->flags->blank)
		return ((int)write(STDOUT_FILENO, " ", 1));
	else
		return (j);
}

int	iprint_padz(const size_t len)
{
	int	i;
	int	j;

	j = 0;
	i = -1;
	while (j >= 0 && (size_t)++i < len)
		j = (int)write(STDOUT_FILENO, "0", 1);
	return (j);
}

size_t	idigit_len(const char *num)
{
	if (!num)
		return (0);
	else if (*num == '-')
		return (ft_strlen(num + 1));
	else if (ft_isdigit(*num))
		return (ft_strlen(num));
	else
		return (0);
}

_Bool	isignof(const char *num)
{
	return (num && *num == '-' && ft_isdigit(*(num + 1)));
}

int	iprintf2(const t_fmt_arg *farg, const char *num)
{
	int	j;

	j = 0;
	if (farg->prec && farg->flags)
	{
		if (!farg->flags->adjust_left
			&& farg->min_width
			&& *(farg->min_width) > *(farg->prec) + isignof(num))
			j = uprint_pad(*(farg->min_width) - *(farg->prec) - isignof(num));
		j = iprints_(farg, j, num);
		if (j >= 0 && *(farg->prec) > idigit_len(num))
			j = iprint_padz(*(farg->prec) - idigit_len(num));
		if (j > 0)
			j = iprint_digits(num);
		if (j > 0 && farg->flags->adjust_left
			&& farg->min_width
			&& *(farg->min_width) > *(farg->prec) + isignof(num))
			j = uprint_pad(*(farg->min_width) - *(farg->prec) - isignof(num));
		return (j);
	}
	else
		return (iprintf3(farg, num));
}
