#include "../includes/ft_printf.h"

void	ft_init_flags(t_flags *flags)
{
	flags->type = 0;
	flags->width = 0;
	flags->minus = 0;
	flags->zero = 0;
	flags->precision = -1;
	flags->star = 0;
}

size_t	put_char(char c)
{
	size_t	len;

	len = 0;
	write(1, &c, 1);
	len++;
	return (len);
}

size_t	ft_parse_input(const char *format, va_list arg)
{
	t_flags	flags;
	size_t	len;
	size_t	i;

	len = 0;
	i = 0;
	while (1)
	{
		if (format[i] == '\0')
			break ;
		else if (format[i] == '%')
		{
			ft_init_flags(&flags);
			if (format[i + 1] == ' ')
				len += put_char(' ');
			i = ft_parse_flag(format, i, &flags, arg);
			if (ft_is_type(format[i]))
				len += ft_processor(format[i], &flags, arg);
		}
		else
			len += put_char(format[i]);
		i++;
	}
	return (len);
}

int	printf(const char *format, ...)
{
	size_t	len;
	va_list	arg;

	va_start(arg, format);
	len = 0;
	len += ft_parse_input(format, arg);
	va_end(arg);
	return (len);
}
