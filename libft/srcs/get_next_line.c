#include "../includes/get_next_line.h"

char	*ft_strnew(size_t size)
{
	char	*str;

	str = (char *)malloc(sizeof(char) * size + 1);
	if (!str)
		return (NULL);
	str[size] = '\0';
	while (size--)
		str[size] = '\0';
	return (str);
}

int	check_rem(char **rem, char **line)
{
	char	*ptr_n;
	char	*tmp;

	if (*rem)
	{
		ptr_n = ft_strchr(*rem, '\n');
		if (ptr_n)
		{
			*ptr_n = '\0';
			*line = ft_strdup(*rem);
			ptr_n++;
			tmp = (*rem);
			(*rem) = ft_strdup(ptr_n);
			free(tmp);
			return (1);
		}
		*line = ft_strdup(*rem);
		free(*rem);
		*rem = NULL;
	}
	else
		*line = ft_strnew(0);
	return (0);
}

int	if_new_line(char **rem, char **line, char *ptr_n, char *buf)
{
	char	*tmp;

	*ptr_n = '\0';
	tmp = *line;
	*line = ft_strjoin(*line, buf);
	if (!(*line))
		return (-1);
	free(tmp);
	tmp = *rem;
	*rem = ft_strdup(++ptr_n);
	free(tmp);
	free(buf);
	return (1);
}

int	free_line(char **line, char *buf, char *tmp_ptr)
{
	tmp_ptr = *line;
	*line = ft_strjoin(*line, buf);
	if (!(*line))
		return (-1);
	free(tmp_ptr);
	return (0);
}

int	get_next_line(int fd, char **line)
{
	static char	*rem;
	char		*buf;
	size_t		byte_wr;
	char		*tmp_ptr;

	if (fd < 0 || fd > 19 || line == NULL || BUFFER_SIZE <= 0)
		return (-1);
	if (check_rem(&rem, line))
		return (1);
	buf = (char *)malloc(BUFFER_SIZE + 1);
	if (!buf)
		return (-1);
	byte_wr = read(fd, buf, BUFFER_SIZE);
	while (byte_wr)
	{
		buf[byte_wr] = '\0';
		tmp_ptr = ft_strchr(buf, '\n');
		if (tmp_ptr)
			return (if_new_line(&rem, line, tmp_ptr, buf));
		if (free_line(line, buf, tmp_ptr) == -1)
			return (-1);
		byte_wr = read(fd, buf, BUFFER_SIZE);
	}
	free(buf);
	return (0);
}
