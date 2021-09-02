#include "../includes/libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	size_t	len;
	size_t	i;

	if (!s)
		return ;
	i = 0;
	len = ft_strlen(s);
	while (len--)
	{
		write (fd, &s[i], 1);
		i++;
	}
}
