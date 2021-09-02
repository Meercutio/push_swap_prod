#include "../includes/libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*s1;
	size_t			len;
	unsigned int	i;

	if (!s)
		return (NULL);
	len = ft_strlen(s);
	i = 0;
	s1 = (char *)malloc(len + 1);
	if (!s1)
		return (NULL);
	while (s[i])
	{	
		s1[i] = f(i, s[i]);
		i++;
	}
	s1[i] = '\0';
	return (s1);
}
