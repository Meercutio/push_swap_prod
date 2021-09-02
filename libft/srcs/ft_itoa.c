#include "../includes/libft.h"

int	ft_len(int n)
{
	int	len;

	len = 0;
	if (n == -2147483648)
	{
		len = 11;
		return (len);
	}
	if (n == 0)
	{
		len = 1;
		return (len);
	}
	if (n < 0)
	{
		n *= -1;
		len++;
	}
	while (n > 0)
	{
		len++;
		n /= 10;
	}
	return (len);
}

char	*ft_exclude(int n)
{
	char	*str;
	char	*str_min;
	char	*str_zero;

	str_min = "-2147483648";
	str_zero = "0";
	if (n == -2147483648)
		str = ft_strdup(str_min);
	if (n == 0)
		str = ft_strdup(str_zero);
	return (str);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		len;

	if (n == 0 || n == -2147483648)
		return (ft_exclude(n));
	len = ft_len(n);
	str = (char *)malloc(len + 1);
	if (!str)
		return (NULL);
	str[len--] = '\0';
	if (n < 0)
	{
		str[0] = '-';
		n *= -1;
	}
	while (n > 0)
	{
		str[len] = n % 10 + '0';
		n /= 10;
		len--;
	}
	return (str);
}
