#include "../includes/libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	char	*h;
	size_t	pos;
	size_t	i;

	h = (char *)haystack;
	if (!*needle)
		return (h);
	pos = 0;
	while (h[pos] && pos < len)
	{
		if (h[pos] == needle[0])
		{
			i = 1;
			while (needle[i] != '\0' && h[pos + i] == needle[i]
				&& (pos + i) < len)
				i++;
			if (needle[i] == '\0')
				return (&h[pos]);
		}
		pos++;
	}
	return (NULL);
}
