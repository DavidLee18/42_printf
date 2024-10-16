/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_fmt_arg.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehylee <jaehylee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 14:55:16 by jaehylee          #+#    #+#             */
/*   Updated: 2024/10/16 14:55:25 by jaehylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		free_fmt_arg(t_fmt_arg *arg)
{
	if (!arg)
		return ;
	if (arg->flags)
		free(arg->flags);
	if (arg->min_width)
		free(arg->min_width);
	if (arg->prec)
		free(arg->prec);
	free(arg);
}

t_flags		*init_flags(void)
{
	t_flags	*f;

	f = (t_flags *)ft_calloc(1, sizeof(t_flags));
	if (!f)
		return (NULL);
	f->adjust_left = 0;
	f->alt_form = 0;
	f->blank = 0;
	f->pad_zero = 0;
	f->sign = 0;
}
