#include "../includes/libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*dst1;
	unsigned char	*src1;

	dst1 = (unsigned char *)dst;
	src1 = (unsigned char *)src;
	if (dst == NULL && src == NULL)
		return (NULL);
	if (dst <= src)
		while (len--)
			*dst1++ = *src1++;
	else
	{
		dst1 += len;
		src1 += len;
		while (len--)
			*--dst1 = *--src1;
	}
	return (dst);
}
