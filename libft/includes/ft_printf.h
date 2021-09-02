#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>
# include "libft.h"
# include <limits.h>

typedef struct s_flags
{
	int	type;
	int	width;
	int	minus;
	int	zero;
	int	precision;
	int	star;
}				t_flags;
int		printf(const char *format, ...);
size_t	ft_parse_flag(const char *format, size_t i, \
		t_flags *flags, va_list arg);
void	ft_flag_dot(const char *format, size_t *i, t_flags *flags, va_list arg);
void	ft_flag_minus(t_flags *flags);
void	ft_flag_width(t_flags *flags, va_list arg);
void	ft_flag_digit(char c, t_flags *flags);
int		ft_is_type(int c);
size_t	ft_processor(char type, t_flags *flags, va_list arg);
size_t	ft_add_width(int width, int prec, int zero);
size_t	ft_putstr_prec(char *str, int precision);
size_t	ft_proc_char(t_flags *flags, char c);
size_t	ft_proc_string(t_flags *flags, char *str);
size_t	ft_proc_pointer(t_flags *flags, unsigned long p);
size_t	ft_proc_int(t_flags *flags, int i);
size_t	ft_proc_uint(t_flags *flags, unsigned int i);
size_t	ft_proc_hex(t_flags *flags, unsigned int h, int capitals);
size_t	put_of_uint_minus(t_flags *flags, char *str);
size_t	put_of_uint_prec(t_flags *flags);
size_t	ft_proc_percent(t_flags *flags);

#endif