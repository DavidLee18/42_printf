/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehylee <jaehylee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 03:41:54 by jaehylee          #+#    #+#             */
/*   Updated: 2025/03/24 16:09:57 by jaehylee         ###   ########.fr       */
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

int					ft_fprintf(int fd, const char *fmt, ...);

int					ft_vprintf(t_list **dyn, int fd, const char *fmt,
						va_list args);

t_fmt_arg			*fst_fmt_arg(t_list **dyn, const char *fmt);

int					vprint_fmt(t_list **dyn, int fd, t_fmt_arg *farg,
						va_list args);

int					sum_or_error(const int i, const int j, const int k);

int					vprint_chr(int fd, const t_fmt_arg *farg,
						va_list args);

int					vprint_str(t_list **dyn, int fd, const t_fmt_arg *farg,
						va_list args);

int					vprint_hex(t_list **dyn, int fd, const t_fmt_arg *farg,
						va_list args);

int					vprint_int(t_list **dyn, int fd, const t_fmt_arg *farg,
						va_list args);

int					vprint_uint(t_list **dyn, int fd, const t_fmt_arg *farg,
						va_list args);

char				*gc_utoa(t_list **dyn, unsigned int u);

int					ft_ulog(const size_t base, const size_t n);

char				*gc_utox(t_list **dyn, unsigned int u);

char				*gc_utox_(t_list **dyn, unsigned int u);

_Bool				is_conv_spec(const char c);

void				preproc_flags(t_list **dyn, const char *fmt, t_fmt_arg *arg,
						size_t *i);

void				parse_width(t_list **dyn, const char *fmt, t_fmt_arg *arg,
						size_t *i);

void				parse_prec(t_list **dyn, const char *fmt, t_fmt_arg *arg,
						size_t *i);

_Bool				parse_conv_spec(const char *fmt,
						t_fmt_arg *arg, const size_t i);

size_t				ft_atoul(const char *str);

long				ft_atol(const char *str);

t_fmt_arg			*init_fmt_arg(t_list **dyn);

t_flags				*init_flags(t_list **dyn);

int					print_per(int fd, const t_fmt_arg *farg);

int					printp(t_list **dyn, int fd, const t_fmt_arg *farg,
						va_list args);

int					sprint_f(int fd, const t_fmt_arg *farg, const char *str);

int					uprintf(int fd, const t_fmt_arg *farg, const char *num);

int					uprint_pad(int fd, size_t len);

int					uprintf2(int fd, const t_fmt_arg *farg, const char *num);

int					uprint_padz(int fd, size_t len);

int					xprintf(int fd, const t_fmt_arg *farg, const char *num);

int					xprintf2(int fd, const t_fmt_arg *farg, const char *num);

int					iprintf(int fd, const t_fmt_arg *farg, const char *num);

int					iprints_(int fd, const t_fmt_arg *farg, const char *num);

int					iprint_padz(int fd, size_t len);

size_t				idigit_len(const char *num);

int					iprintf2(int fd, const t_fmt_arg *farg, const char *num);

_Bool				isignof(const char *num);

int					iprintf3(int fd, const t_fmt_arg *farg, const char *num);

int					iprint_digits(int fd, const char *num);

int					iprintf4(int fd, const t_fmt_arg *farg, const char *num);

int					iprintf5(int fd, const t_fmt_arg *farg, const char *num);

int					iprintf6(int fd, const t_fmt_arg *farg, const char *num);

int					xprintf3(int fd, const t_fmt_arg *farg, const char *num);

int					xprintf4(int fd, const t_fmt_arg *farg, const char *num);

int					xprintf5(int fd, const t_fmt_arg *farg, const char *num);

char				*ulltox(t_list **dyn, unsigned long long p);

int					pprintf(int fd, const t_fmt_arg *farg, const char *p);

unsigned long long	ulllog(unsigned long long base,
						unsigned long long ul);

int					cprintf(int fd, const t_fmt_arg *farg, unsigned char c);

size_t				usize_max(size_t a, size_t b);

int					print_vec(t_list **dyn, int fd, const t_fmt_arg *farg,
						va_list args);

int					print_vec2(t_list **dyn, int fd, const t_fmt_arg *farg,
						t_vec v);

#endif
