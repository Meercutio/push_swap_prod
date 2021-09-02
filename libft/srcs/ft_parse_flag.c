#include "../includes/ft_printf.h"

size_t	ft_parse_flag(const char *format, size_t i, t_flags *flags, va_list arg)
{
	i++;
	while (format[i])
	{
		if (format[i] == '0' && !(flags->width) && !(flags->minus))
			flags->zero = 1;
		if (format[i] == '.')
			ft_flag_dot(format, &i, flags, arg);
		if (format[i] == '-')
			ft_flag_minus(flags);
		if (format[i] == '*')
			ft_flag_width(flags, arg);
		if (ft_isdigit(format[i]))
			ft_flag_digit(format[i], flags);
		if (ft_is_type(format[i]))
		{
			flags->type = format[i];
			break ;
		}
		i++;
	}
	return (i);
}
