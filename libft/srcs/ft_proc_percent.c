#include "../includes/ft_printf.h"

size_t	ft_proc_percent(t_flags *flags)
{
	size_t	len;

	len = 0;
	if (flags->minus == 1)
		len += ft_putstr_prec("%", 1);
	len += ft_add_width(flags->width, 1, flags->zero);
	if (flags->minus == 0)
		len += ft_putstr_prec("%", 1);
	return (len);
}
