/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utox.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehylee <jaehylee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 10:40:00 by jaehylee          #+#    #+#             */
/*   Updated: 2024/10/13 10:40:00 by jaehylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_utox(unsigned int u)
{
	char			*str;
	int				dgt_len;
	unsigned int	n;

	n = u;
	dgt_len = ft_ulog(16, u);
	if (dgt_len == -1)
		dgt_len = 0;
	str = (char *)ft_calloc(dgt_len + 2, sizeof(char));
	if (!str)
		return (NULL);
	str[dgt_len + 1] = NULL;
	while (dgt_len >= 0)
	{
		str[dgt_len--] = "0123456789abcdef"[n % 16];
		n /= 16;
	}
	return (str);
}

char	*ft_utox_(unsigned int u)
{
	char			*str;
	int				dgt_len;
	unsigned int	n;

	n = u;
	dgt_len = ft_ulog(16, u);
	if (dgt_len == -1)
		dgt_len = 0;
	str = (char *)ft_calloc(dgt_len + 2, sizeof(char));
	if (!str)
		return (NULL);
	str[dgt_len + 1] = NULL;
	while (dgt_len >= 0)
	{
		str[dgt_len--] = "0123456789ABCDEF"[n % 16];
		n /= 16;
	}
	return (str);
}
