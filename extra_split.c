#include "push_swap.h"

static size_t	count_words(char const *s, char c)
{
	size_t	count;
	int		flag;

	count = 0;
	flag = 0;
	while (*s)
	{
		if (*s != c && flag == 0)
		{
			flag = 1;
			count++;
		}
		else if (*s == c)
			flag = 0;
		s++;
	}
	return (count);
}

static char	**free_all(char **all, size_t i)
{
	while (i > 0)
	{
		i--;
		free(all[i]);
	}
	free(all);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**all;
	size_t	i;
	size_t	len;

	if (!s)
		return (NULL);
	all = (char **)malloc(sizeof(char *) * (count_words(s, c) + 1));
	if (!all)
		return (NULL);
	i = 0;
	while (*s)
	{
		if (*s != c)
		{
			len = 0;
			while (s[len] && s[len] != c)
				len++;
			all[i++] = ft_substr(s, 0, len);
			if (all[i - 1] == NULL)
				return (free_all(all, i - 1));
			s = s + len;
		}
		else
			s++;
	}
	all[i] = NULL;
	return (all);
}
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	s_len;
	size_t	substr_len;
	size_t	i;

	if (s == NULL)
		return (NULL);
	s_len = ft_strlen(s);
	if (start >= s_len)
		return (ft_strdup(""));
	if (len > s_len - start)
		substr_len = s_len - start;
	else
		substr_len = len;
	substr = (char *)malloc(sizeof(char) * (substr_len + 1));
	if (substr == NULL)
		return (NULL);
	i = 0;
	while (i < substr_len && s[start + i] != '\0')
	{
		substr[i] = s[start + i];
		i++;
	}
	substr[i] = '\0';
	return (substr);
}

