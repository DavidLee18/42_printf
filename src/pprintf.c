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

int	pprintf(const char *p)
{
	int	j;

	j = (int)write(STDOUT_FILENO, "0x", 2);
	if (j > 0)
		j = (int)write(STDOUT_FILENO, p, ft_strlen(p));
	return (j);
}

unsigned long long	ullog(const unsigned long long base, const unsigned long long ul)
{
	if (base == 0 || base == 1 || ul == 0 || ul < base)
		return (0);
	return (1 + ullog(base, ul / base));
}
