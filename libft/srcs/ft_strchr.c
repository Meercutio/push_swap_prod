#include "../includes/libft.h"

char	*ft_strchr(const char *s, int c)
{
	char			*s1;
	unsigned char	c1;

	s1 = (char *)s;
	c1 = (unsigned char)c;
	while (*s1 || c1 == '\0')
	{
		if (*s1 == c1)
			return (s1);
		s1++;
	}
	return (NULL);
}
