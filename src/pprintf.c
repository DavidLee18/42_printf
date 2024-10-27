/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pprintf.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehylee <jaehylee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 14:54:53 by jaehylee          #+#    #+#             */
/*   Updated: 2024/10/25 14:54:53 by jaehylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	pprintf(const t_fmt_arg *farg, const char *p)
{
	int	j;

	j = 0;
	if (*p == '0')
		return (pprintf(farg, "(nil)"));
	else
	{
		if (!(farg->flags && farg->flags->adjust_left)
			&& farg->min_width
			&& *(farg->min_width) > (*p != '(') * 2 + ft_strlen(p))
			j = uprint_pad(*(farg->min_width) - (*p != '(') * 2 - ft_strlen(p));
		if (*p != '(')
			j += (int)write(STDOUT_FILENO, "0x", 2);
		j += (int)write(STDOUT_FILENO, p, ft_strlen(p));
		if (farg->flags && farg->flags->adjust_left
			&& farg->min_width
			&& *(farg->min_width) > (*p != '(') * 2 + ft_strlen(p))
			j += uprint_pad(*(farg->min_width)
					- (*p != '(') * 2 - ft_strlen(p));
		return (j);
	}
}

unsigned long long	ulllog(const unsigned long long base,
	const unsigned long long ul)
{
	if (base == 0 || base == 1 || ul == 0 || ul < base)
		return (0);
	return (1 + ulllog(base, ul / base));
}

int	cprintf(const t_fmt_arg *farg, const unsigned char c)
{
	int		j;
	size_t	i;

	j = 0;
	i = 0;
	if (farg->min_width && *(farg->min_width) > 1)
	{
		while (i < *(farg->min_width) - 1)
		{
			j += (int)write(STDOUT_FILENO, " ", 1);
			i++;
		}
		j += (int)write(STDOUT_FILENO, &c, 1);
		return (j);
	}
	return ((int)write(STDOUT_FILENO, &c, 1));
}

size_t	ppreflen(const char *p)
{
	if (*p == '(')
		return (0);
	else
		return (2);
}

size_t	ft_max(const size_t a, const size_t b)
{
	if (a > b)
		return (a);
	else
		return (b);
}
