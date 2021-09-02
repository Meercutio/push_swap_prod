#include "../includes/ft_printf.h"

size_t	ft_add_width(int width, int prec, int zero)
{
	size_t	len;

	len = 0;
	while (width - prec > 0)
	{
		if (zero)
			write(1, "0", 1);
		else
			write(1, " ", 1);
		len++;
		width--;
	}
	return (len);
}

size_t	ft_putstr_prec(char *str, int precision)
{
	size_t	len;

	len = 0;
	while (str[len] && (int)len < precision)
	{
		write(1, &str[len], 1);
		len++;
	}
	return (len);
}

size_t	ft_processor(char type, t_flags *flags, va_list arg)
{
	size_t	len;

	len = 0;
	if (type == 'c')
		len = ft_proc_char(flags, va_arg(arg, int));
	if (type == 's')
		len = ft_proc_string(flags, va_arg(arg, char *));
	if (type == 'p')
		len = ft_proc_pointer(flags, va_arg(arg, unsigned long));
	if (type == 'd' || type == 'i')
		len = ft_proc_int(flags, va_arg(arg, int));
	if (type == 'u')
		len = ft_proc_uint(flags, va_arg(arg, unsigned int));
	if (type == 'x')
		len = ft_proc_hex(flags, va_arg(arg, unsigned int), 0);
	if (type == 'X')
		len = ft_proc_hex(flags, va_arg(arg, unsigned int), 1);
	if (type == '%')
		len = ft_proc_percent(flags);
	return (len);
}
