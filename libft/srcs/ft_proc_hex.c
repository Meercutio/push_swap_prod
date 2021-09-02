#include "../includes/ft_printf.h"

size_t	len_str_h(unsigned int p)
{
	unsigned int	tmp;
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

char	*str_hex(unsigned int h, int capitals)
{
	size_t	i;
	char	*str;

	i = len_str_h(h);
	str = (char *)malloc(i + 1);
	if (!str)
		return (NULL);
	str[i] = '\0';
	i--;
	while (h != 0)
	{
		if (h % 16 < 10)
			str[i] = h % 16 + 48;
		else
		{
			if (capitals == 0)
				str[i] = h % 16 + 87;
			else
				str[i] = h % 16 + 55;
		}
		h /= 16;
		i--;
	}
	return (str);
}

size_t	put_of_uint_prec_x(t_flags *flags, char *str)
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

size_t	ft_proc_hex(t_flags *flags, unsigned int h, int capitals)
{
	char	*str;
	size_t	len;

	len = 0;
	h += 4294967295 + 1;
	if (flags->precision == 0 && h == 0)
	{
		len += ft_add_width(flags->width, 0, 0);
		return (len);
	}
	if (h == 0)
		str = ft_strdup("0");
	else
		str = str_hex(h, capitals);
	if (flags->minus == 1)
		len += put_of_uint_minus(flags, str);
	if (flags->precision >= 0 && flags->precision < (int)(ft_strlen(str)))
		flags->precision = ft_strlen(str);
	len += put_of_uint_prec_x(flags, str);
	if (flags->minus == 0)
		len += put_of_uint_minus(flags, str);
	free(str);
	return (len);
}
