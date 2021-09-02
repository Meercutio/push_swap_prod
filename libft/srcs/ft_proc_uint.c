#include "../includes/ft_printf.h"

int	len_str_u(unsigned int n)
{
	unsigned int	tmp;
	int				len;

	tmp = n;
	len = 0;
	while (tmp > 0)
	{
		len++;
		tmp /= 10;
	}
	return (len);
}

char	*ft_uitoa(unsigned int n)
{
	char			*str;
	int				len;

	if (n == 0)
	{
		str = ft_strdup("0");
		return (str);
	}
	len = len_str_u(n);
	str = (char *)malloc(len + 1);
	if (!str)
		return (NULL);
	str[len--] = '\0';
	while (n > 0)
	{
		str[len] = n % 10 + '0';
		n /= 10;
		len--;
	}
	return (str);
}

size_t	put_of_uint_minus(t_flags *flags, char *str)
{
	size_t	len;

	len = 0;
	if (flags->precision >= 0)
		len += ft_add_width(flags->precision - 1, ft_strlen(str) - 1, 1);
	len += ft_putstr_prec(str, ft_strlen(str));
	return (len);
}

size_t	put_of_uint_prec(t_flags *flags)
{
	size_t	len;

	len = 0;
	flags->width -= flags->precision;
	len += ft_add_width(flags->width, 0, 0);
	return (len);
}

size_t	ft_proc_uint(t_flags *flags, unsigned int i)
{
	char	*str;
	size_t	len;

	len = 0;
	i += 4294967295 + 1;
	if (flags->precision == 0 && i == 0)
	{
		len += ft_add_width(flags->width, 0, 0);
		return (len);
	}
	str = ft_uitoa(i);
	if (flags->minus == 1)
		len += put_of_uint_minus(flags, str);
	if (flags->precision >= 0 && flags->precision < (int)(ft_strlen(str)))
		flags->precision = ft_strlen(str);
	if (flags->precision >= 0)
		len += put_of_uint_prec(flags);
	else
		len += ft_add_width(flags->width, ft_strlen(str), flags->zero);
	if (flags->minus == 0)
		len += put_of_uint_minus(flags, str);
	free(str);
	return (len);
}
