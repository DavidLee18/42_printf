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

int iprints_(const t_fmt_arg *farg, const int j, const char *num)
{
	if (j < 0)
		return (j);
	else if (farg->flags->sign && ft_isdigit(*num))
		return ((int)write(STDOUT_FILENO, "+", 1));
	else if (*num == '-')
		return ((int)write(STDOUT_FILENO, "-", 1));
	else if (farg->flags->blank)
		return ((int)write(STDOUT_FILENO, " ", 1));
}

int	iprint_padz(const size_t len, const char *num)
{
	int	i;
	int	j;

	j = 0;
	i = -1;
	while (j >= 0 && ++i < len)
		j = (int)write(STDOUT_FILENO, "0", 1);
	if (j > 0 && ft_isdigit(*num))
		j = (int)write(STDOUT_FILENO, num, ft_strlen(num));
	else if (j > 0 && *num == '-')
		j = (int)write(STDOUT_FILENO, num + 1, ft_strlen(num) - 1);
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
}

int	iprintf2(const t_fmt_arg *farg, const char *num);
