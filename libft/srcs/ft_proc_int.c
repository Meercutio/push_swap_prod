#include "../includes/ft_printf.h"

size_t	proc_j(t_flags *flags, int i, long int *j)
{
	size_t		len;

	len = 0;
	if (i < 0 && (flags->precision >= 0 || flags->zero == 1))
	{
		if (flags->zero == 1 && flags->precision < 0)
		{
			len += ft_putstr_prec("-", 1);
			len--;
		}
		*(j) *= -1;
		flags->zero = 1;
		flags->width -= 1;
		len++;
	}
	return (len);
}

size_t	put_of_int_minus(t_flags *flags, char *str, int i)
{
	size_t	len;

	len = 0;
	if (i < 0 && flags->precision >= 0)
		write(1, "-", 1);
	if (flags->precision >= 0)
		len += ft_add_width(flags->precision - 1, ft_strlen(str) - 1, 1);
	len += ft_putstr_prec(str, ft_strlen(str));
	return (len);
}

size_t	put_of_int_prec(t_flags *flags, char *str)
{
	size_t	len;

	len = 0;
	if (flags->precision >= 0)
	{
		flags->width -= flags->precision;
		len += ft_add_width(flags->width, 0, 0);
	}
	else
		len += ft_add_width(flags->width, ft_strlen(str), flags->zero);
	return (len);
}

size_t	ft_proc_int(t_flags *flags, int i)
{
	char		*str;
	size_t		len;
	long int	j;

	len = 0;
	j = (long int)i;
	if (flags->precision == 0 && i == 0)
		len += ft_add_width(flags->width, 0, 0);
	else
	{
		len += proc_j(flags, i, &j);
		str = ft_itoa(j);
		if (flags->minus == 1)
			len += put_of_int_minus(flags, str, i);
		if (flags->precision >= 0 && flags->precision < (int)(ft_strlen(str)))
			flags->precision = ft_strlen(str);
		len += put_of_int_prec(flags, str);
		if (flags->minus == 0)
			len += put_of_int_minus(flags, str, i);
		free(str);
	}
	return (len);
}
