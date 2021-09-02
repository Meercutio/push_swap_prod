#include "../includes/libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	*b1;
	unsigned char	c1;

	b1 = (unsigned char *)b;
	c1 = (unsigned char)c;
	i = 0;
	while (len)
	{
		b1[i] = c1;
		len--;
		i++;
	}
	return (b);
}
