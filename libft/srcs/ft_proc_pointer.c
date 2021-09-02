#include "../includes/ft_printf.h"

size_t	len_str_p(unsigned long p)
{
	unsigned long	tmp;
	size_t			i;

	i = 0;
	tmp = p;
	while (tmp != 0)
	{
		tmp = tmp / 16;
		i++;
	}
	return (i);
}

char	*str_pointer(unsigned long p)
{
	size_t	i;
	char	*str;

	if (p == 0)
		str = ft_strdup("0");
	else
	{
		i = len_str_p(p);
		str = (char *)malloc(i + 1);
		if (!str)
			return (NULL);
		str[i] = '\0';
		i--;
		while (p != 0)
		{
			if (p % 16 < 10)
				str[i] = p % 16 + 48;
			else
				str[i] = p % 16 + 87;
			p /= 16;
			i--;
		}
	}
	return (str);
}

size_t	put_result(t_flags *flags, char *str)
{
	size_t	len;

	len = 0;
	if (flags->minus == 1)
	{
		len += ft_putstr_prec("0x", 2);
		len += ft_putstr_prec(str, ft_strlen(str));
		len += ft_add_width(flags->width - 2, ft_strlen(str), flags->zero);
	}
	else
	{
		len += ft_add_width(flags->width - 2, ft_strlen(str), flags->zero);
		len += ft_putstr_prec("0x", 2);
		len += ft_putstr_prec(str, ft_strlen(str));
	}
	return (len);
}

size_t	add_len(t_flags *flags, size_t len)
{
	len += ft_putstr_prec("0x", 2);
	len += ft_add_width(flags->width - 2, flags->precision, 0);
	return (len);
}

size_t	ft_proc_pointer(t_flags *flags, unsigned long p)
{
	char			*str;
	size_t			len;

	len = 0;
	if (p == 0 && flags->precision == 0)
	{
		if (flags->minus)
			len += add_len(flags, len);
		else
		{
			len += ft_add_width(flags->width - 2, flags->precision, 0);
			len += ft_putstr_prec("0x", 2);
		}
	}
	else
	{
		if (p == 0)
			str = ft_strdup("0");
		else
			str = str_pointer(p);
		len = put_result(flags, str);
		free(str);
	}
	return (len);
}
