#include "../includes/libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	len_s;
	size_t	i;

	if (!s)
		return (NULL);
	len_s = ft_strlen(s);
	if (len_s < start)
		len_s = 0;
	if (len_s > len)
		len_s = len;
	sub = (char *)malloc(len_s + 1);
	if (!sub)
		return (NULL);
	i = 0;
	while (i < len_s && s[start + i] != '\0')
	{
		sub[i] = s[start + i];
		i++;
	}
	sub[i] = '\0';
	return (sub);
}
