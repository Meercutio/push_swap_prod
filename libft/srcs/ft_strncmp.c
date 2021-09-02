#include "../includes/libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*d1;
	unsigned char	*d2;

	d1 = (unsigned char *)s1;
	d2 = (unsigned char *)s2;
	while (n--)
	{
		if (*d1 != *d2)
			return (*d1 - *d2);
		else
		{
			if (*d1 && *d2)
			{
				d1++;
				d2++;
			}
			else
				return (*d1 - *d2);
		}
	}
	return (0);
}
