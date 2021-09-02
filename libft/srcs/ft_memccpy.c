#include "../includes/libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*dst1;
	unsigned char	*src1;
	unsigned char	c1;

	dst1 = (unsigned char *)dst;
	src1 = (unsigned char *)src;
	c1 = (unsigned char)c;
	while (n--)
	{
		*dst1++ = *src1++;
		if (*(dst1 - 1) == c1)
			return (dst1);
	}
	return (NULL);
}
