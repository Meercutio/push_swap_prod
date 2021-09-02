#include "../includes/libft.h"

size_t	ft_wordcount(char const *s, char c)
{
	size_t	count;

	count = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s != c && *s)
			count++;
		while (*s != c && *s)
			s++;
	}
	return (count);
}

void	ft_free(char **arr)
{
	size_t	i;

	i = 0;
	while (arr[i] != NULL)
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

char	**ft_work(char **arr, size_t word, const char *s, char c)
{
	size_t	w;
	size_t	i;
	size_t	pos;

	arr[word] = NULL;
	w = 0;
	i = 0;
	pos = 0;
	while (w < word)
	{
		while (s[pos] == c && s[pos])
			pos++;
		while (s[pos + i] != c && s[pos + i])
			i++;
		arr[w] = ft_substr(s, pos, i);
		if (arr[w] == NULL)
		{
			ft_free(arr);
			return (arr);
		}
		pos += i;
		i = 0;
		w++;
	}
	return (arr);
}

char	**ft_split(char const *s, char c)
{
	char	**arr;
	size_t	word;

	if (!s)
		return (NULL);
	word = ft_wordcount(s, c);
	arr = ft_calloc(word + 1, sizeof(s));
	if (!arr)
		return (NULL);
	arr = ft_work(arr, word, s, c);
	return (arr);
}
