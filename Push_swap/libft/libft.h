/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarolei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 02:20:27 by pcarolei          #+#    #+#             */
/*   Updated: 2020/03/09 19:58:57 by pcarolei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

# define BUFF_SIZE 32
# define LEN 99

typedef struct	s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}				t_list;

typedef struct	s_fd_list
{
	int					fd;
	char				*fd_str;
	char				*tmp;
	struct s_fd_list	*next;
}				t_fd_list;

typedef union	u_ld_bytes
{
	long double	num;
	char		bytes[10];
}				t_ld_bytes;

typedef struct	s_ld_epf
{
	char	sign;
	char	exp[15];
	char	mnt[64];
	char	*integer_part_bin;
	char	*fract_part_bin;
	int		exp_dec;
}				t_ld_epf;

typedef struct	s_fwplt
{
	char	*flags;
	int		width;
	int		precision;
	char	*length;
	char	type;
}				t_fwplt;

int				get_next_line(const int fd, char **line);
void			*ft_memset(void *b, int c, size_t len);
void			ft_bzero(void *s, size_t n);
void			*ft_memcpy(void *dst, const void *src, size_t n);
void			*ft_memccpy(void *dst, const void *src, int c, size_t n);
void			*ft_memmove(void *dst, const void *src, size_t len);
void			*ft_memchr(const void *s, int c, size_t n);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
size_t			ft_strlen(const char *s);
char			*ft_strdup(const char *s1);
char			*ft_strcpy(char *dst, const char *src);
char			*ft_strncpy(char *dst, const char *src, size_t len);
char			*ft_strcat(char *s1, const char *s2);
char			*ft_strncat(char *s1, const char *s2, size_t len);
size_t			ft_strlcat(char *dst, const char *src, size_t size);
char			*ft_strchr(const char *s, int c);
char			*ft_strrchr(const char *s, int c);
char			*ft_strstr(const char *haystack, const char *needle);
char			*ft_strnstr(const char *haystack, const char *needle,
		size_t len);
int				ft_strcmp(const char *s1, const char *s2);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
int				ft_atoi(const char *str);
int				ft_isalpha(int c);
int				ft_isdigit(int c);
int				ft_isalnum(int c);
int				ft_isascii(int c);
int				ft_isprint(int c);
int				ft_toupper(int c);
int				ft_tolower(int c);
void			*ft_memalloc(size_t size);
void			ft_memdel(void **ap);
char			*ft_strnew(size_t size);
void			ft_strdel(char **as);
void			ft_strclr(char *s);
void			ft_striter(char *s, void (*f)(char *));
void			ft_striteri(char *s, void (*f)(unsigned int, char *));
char			*ft_strmap(char const *s, char (*f)(char));
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int				ft_strequ(char const *s1, char const *s2);
int				ft_strnequ(char const *s1, char const *s2, size_t n);
char			*ft_strsub(char const *s, unsigned int start, size_t len);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strtrim(char const *s);
char			**ft_strsplit(char const *s, char c);
char			*ft_itoa(int n);
void			ft_putchar(char c);
void			ft_putstr(const char *s);
void			ft_putendl(const char *s);
void			ft_putnbr(int n);
void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(char const *s, int fd);
void			ft_putendl_fd(char const *s, int fd);
void			ft_putnbr_fd(int n, int fd);
t_list			*ft_lstnew(void const *content, size_t content_size);
void			ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void			ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void			ft_lstadd(t_list **alst, t_list *new);
void			ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
void			ft_lstaddl(t_list **alst, t_list *new);
int				ft_lst_get_length(t_list *lst);
void			*ft_memrchr(const void *s, int c, size_t n);
int				ft_isspace(char c);
char			*ft_strtrimc(char const *s, char c);
void			*free_2_args(void *a, void *b);
char			*char_to_str(char c);
char			*ft_strjoinfree(char *s1, char *s2);
char			*str_from_char(char c);
char			*push_back(char *res, char c);
char			*str_rev(char *str);
void			swap_str(char **str1, char **str2, int mode);
char			*bignum_multiply_by_n(char *num, int n);
char			*mult_by_10_n_times(char *num, int n);
char			*power_of_2(int n);
char			*power_of_5(int n);
void			free_nums(char *num1, char *num2);
char			*bignum_sum(char *num1, char *num2);
int				ft_pow(int n, int pow);
void			get_exponent_from_bits(char *bits, char *exp);
void			get_mantissa_from_bits(char *bits, char *mnt);

void			get_decimal_exponent(t_ld_epf *epf);
void			get_integer_part_bin(t_ld_epf *epf);
void			get_fract_part_bin(t_ld_epf *epf);
void			bits_to_epf(char *bits, t_ld_epf *epf);
int				count_without_postfix_zeroes(char *str);
char			*prepend_zeroes(char *str, int last);
char			*epf_to_fract_part(t_ld_epf *epf);
char			*epf_to_integer_part(t_ld_epf *epf);
char			*prepend_minus(char *numstr);
char			*complete_fract_part(char *str);
char			*concat_parts(char *integer_part, char *fract_part, char sign);
char			*epf_to_numstr(t_ld_epf *epf);
void			epf_free(t_ld_epf *epf);
char			*bits_to_numstr(char *bits, int sign);
char			*replace_blue(char *str);
char			*replace_magenta(char *str);
char			*replace_cyan(char *str);
char			*colorize(char *str);
char			*replace_eoc(char *str);
char			*replace_red(char *str);
char			*replace_green(char *str);
char			*replace_yellow(char *str);
char			*block_one(char c);
char			*block_two(char c);
char			*block_three(char c);
char			*controlchar_to_str(char c);
int				get_hex_len(unsigned long long int n);
char			*dec_to_hex_str(unsigned long long int n, int mode);
int				get_dot_pos(char *str);
char			*float_round_prec_0(char *str);
char			*float_round(char *str, int precision);
char			*float_round_wrapper(char *str, int precision);
char			*float_to_str(long double num, int sign);
int				ft_abs(int nb);
long long int	ft_max(long long a, long long b);
long long int	ft_min(long long a, long long b);
int				get_size(long long int value, int base);
char			*ft_itoa_base(long long int value, int base);
void			free_parts(t_list *parts);
size_t			list_to_str(t_list *parts, va_list *args, int fd);
int				ft_printf(char *fmt_str, ...);
int				ft_printf_fd(int fd, char *fmt_str, ...);
size_t			handler_b(int fd, t_fwplt *fwplt, int arg);
size_t			handler_f(int fd, t_fwplt *fwplt, long double arg);
size_t			handler_percent(int fd, t_fwplt *fwplt);
size_t			handler_helper(t_fwplt *fwplt, va_list *args,
								int fd);
size_t			handler(char *str, va_list *args, int fd);
void			fwplt_free(t_fwplt *fwplt);
int				check_flag_char(char c);
char			*extract_flag_str(char *str, int n);
void			check_flags(char *str, char *cur_mod, t_fwplt *fwplt, int *pos);
void			check_width(char *str, char *cur_mod, t_fwplt *fwplt, int *pos);
void			check_precision(char *str, char *cur_mod, t_fwplt *fwplt,
									int *pos);
void			check_length(char *str, char *cur_mod, t_fwplt *fwplt,
									int *pos);
void			check_type(char c, char *cur_mod, t_fwplt *fwplt);
t_fwplt			*fwplt_create(char *str);
char			*ft_strtolower(char *str);
char			*repl_del_char(char *str);
size_t			handler_c(int fd, t_fwplt *fwplt, char arg);
size_t			handler_r(int fd, t_fwplt *fwplt, char arg);
size_t			handler_s(int fd, t_fwplt *fwplt, char *arg);
size_t			handler_k(int fd, t_fwplt *fwplt, char *arg);
size_t			handler_p(int fd, t_fwplt *fwplt, void *arg);
size_t			handler_di(int fd, t_fwplt *fwplt, va_list *args);
size_t			handler_u(int fd, t_fwplt *fwplt, va_list *args);
size_t			handler_o(int fd, t_fwplt *fwplt, va_list *args);
size_t			handler_x(int fd, t_fwplt *fwplt, va_list *args, int mode);
char			*hash_o_helper(char *str, t_fwplt *fwplt);
int				get_last_digit_pos(char *str);
char			*handler_flag_hash_f(char *str);
char			*handler_flag_hash(char *str, char type, t_fwplt *fwplt);
char			*handler_flags(t_fwplt *fwplt, char *str);
char			*handler_flag_minus(char *str);
int				check_str_is_neg(char *str);
int				check_str_is_pos(char *str);
int				check_str_has_no_spaces(char *str);
int				get_first_digit_pos(char *str);
char			*handler_flag_plus(char *str, t_fwplt *fwplt);
char			*handler_flag_space(char *str);
char			select_zero_or_space(t_fwplt *fwplt, char c);
void			cps_helper(int *flag, int *i, char *newstr);
char			*create_plussign_str(char *str, t_fwplt *fwplt);
char			*handler_flag_zero(char *str, t_fwplt *fwplt);
int				get_first_symbol_pos(char *str);
int				check_for_zero_str(char *str);
char			*add_prefix(char *str, char type, t_fwplt *fwplt);
char			*cut_extra(char *str, t_fwplt *fwplt);
char			*handler_precision_num_wrapper(t_fwplt *fwplt, char *str);
char			*handler_precision_num(t_fwplt *fwplt, char *str);
char			*handler_precision_s(t_fwplt *fwplt, char *str);
char			*ft_add_spaces(char *str, int space_cnt, int width);
char			*handler_width(t_fwplt *fwplt, char *str);
void			copy_bits_from_byte(char *bits_from_byte, char *bits, int pos);
void			byte_to_bits(char byte, char *bits_from_byte);
void			float_to_bits(char *bytes, char *bits);
void			num_to_bits(long double num, char *bits);
int				parse_month(char *str, char *month);
int				parse_day(char *str, char *day);
int				check_delimiter(char *str);
char			*get_month_str(char *month);
char			*parse_date(char *str);
int				parse_year(char *str, char *year);
int				check_closing_token(char c);
int				get_next_pos(char *fmt_str, int cur_pos);
char			*extract_str(char *str, int p1, int p2);
char			*ft_strreplace(char *str, char *from, char *to);
t_list			*ft_lstnew_wrapper(char *fmt_str, int pos, int pos_next);
t_list			*parser(char *fmt_str);

#endif
