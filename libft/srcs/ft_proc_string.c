#include "../includes/ft_printf.h"

size_t	proc_flag_minus(t_flags *flags, char *str)
{
	size_t	len;

	len = 0;
	if (flags->precision >= 0)
	{
		len += ft_add_width(flags->precision, ft_strlen(str), flags->zero);
		len += ft_putstr_prec(str, flags->precision);
	}
	else
		len += ft_putstr_prec(str, ft_strlen(str));
	return (len);
}

size_t	ft_proc_string(t_flags *flags, char *str)
{
	size_t	len;

	len = 0;
	if (!str)
		str = "(null)";
	if (flags->precision >= 0 && flags->precision > (int)ft_strlen(str))
		flags->precision = (int)ft_strlen(str);
	if (flags->minus == 1)
		len += proc_flag_minus(flags, str);
	if (flags->precision >= 0)
		len += ft_add_width(flags->width, flags->precision, flags->zero);
	else
		len += ft_add_width(flags->width, ft_strlen(str), flags->zero);
	if (flags->minus == 0)
		len += proc_flag_minus(flags, str);
	return (len);
}
