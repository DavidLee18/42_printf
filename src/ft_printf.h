/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehylee <jaehylee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 03:41:54 by jaehylee          #+#    #+#             */
/*   Updated: 2024/10/14 12:57:10 by jaehylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "../libft/libft.h"

typedef struct s_flags
{
	_Bool	alt_form;
	_Bool	pad_zero;
	_Bool	adjust_left;
	_Bool	blank;
	_Bool	sign;
}	t_flags;

typedef struct s_fmt_arg
{
	size_t	start;
	t_flags	*flags;
	size_t	*min_width;
	size_t	*prec;
	char	conv_spec;
	size_t	end;
}	t_fmt_arg;

int					ft_printf(const char *fmt, ...);

int					ft_vprintf(const char *fmt, va_list args);

t_fmt_arg			*fst_fmt_arg(const char *fmt);

int					vprint_fmt(t_fmt_arg *farg, va_list args);

int					sum_or_error(const int i, const int j, const int k);

int					vprint_chr(const t_fmt_arg *farg, va_list args);

int					vprint_str(const t_fmt_arg *farg, va_list args);

int					vprint_hex(const t_fmt_arg *farg, va_list args);

int					vprint_int(const t_fmt_arg *farg, va_list args);

int					vprint_uint(const t_fmt_arg *farg, va_list args);

char				*ft_utoa(unsigned int u);

int					ft_ulog(const size_t base, const size_t n);

char				*ft_utox(unsigned int u);

char				*ft_utox_(unsigned int u);

_Bool				is_conv_spec(const char c);

void				preproc_flags(const char *fmt, t_fmt_arg *arg, size_t *i);

int					free_and_return(t_fmt_arg *arg, const int i);

void				parse_width(const char *fmt, t_fmt_arg *arg, size_t *i);

void				parse_prec(const char *fmt, t_fmt_arg *arg, size_t *i);

_Bool				parse_conv_spec(const char *fmt,
					t_fmt_arg *arg, const size_t i);

size_t				ft_atoul(const char *str);

long				ft_atol(const char *str);

t_fmt_arg			*init_fmt_arg(void);

void				free_fmt_arg(t_fmt_arg *arg);

t_flags				*init_flags(void);

int					print_per(const t_fmt_arg *farg);

int					printp(va_list args);

int					sprint_f(const t_fmt_arg *farg, const char *str);

int					uprintf(const t_fmt_arg *farg, const char *num);

int					uprint_pad(const size_t len);

int					uprintf2(const t_fmt_arg *farg, const char *num);

int					uprint_padz(const size_t len);

int					xprintf(const t_fmt_arg *farg, const char *num);

int					xprintf2(const t_fmt_arg *farg, const char *num);

int					iprintf(const t_fmt_arg *farg, const char *num);

int					iprints_(const t_fmt_arg *farg, const int j, const char *num);

int					iprint_padz(const size_t len);

size_t				idigit_len(const char *num);

int					iprintf2(const t_fmt_arg *farg, const char *num);

_Bool				isignof(const char *num);

int					iprintf3(const t_fmt_arg *farg, const char *num);

int					iprint_digits(const char *num);

int					iprintf4(const t_fmt_arg *farg, const char *num);

int					iprintf5(const t_fmt_arg *farg, const char *num);

int					iprintf6(const t_fmt_arg *farg, const char *num);

int					xprintf3(const t_fmt_arg *farg, const char *num);

int					xprintf4(const t_fmt_arg *farg, const char *num);

int					xprintf5(const t_fmt_arg *farg, const char *num);

char				*ulltox(const unsigned long long p);

int					pprintf(const char *p);

unsigned long long	ulllog(const unsigned long long base, const unsigned long long ul);

#endif
