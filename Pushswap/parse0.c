#include "libft.h"
#include "push_swap.h"

char	*ft_strjoin(char *s1, char const *s2)
{
	size_t	lentotal;
	char	*join;

	lentotal = 0;
	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (ft_strdup(s1));
	lentotal = ft_strlen(s1) + ft_strlen(s2);
	join = (char *)malloc(lentotal + 2);
	if (!join)
		return (NULL);
	ft_strlcpy(join, s1, ft_strlen(s1) + 1);
	ft_strlcat(join, " ",ft_strlen(s1) + 2);
	free(s1);
	ft_strlcat(join, s2, lentotal + 2);
	return (join);
}

size_t	ft_strlcpy(char *dst, char const *src, size_t size)
{
	size_t	count;
	size_t	len;

	len = ft_strlen(src);
	count = 1;
	if (size >= 1)
	{
		while ((count < size) && (*src != '\0'))
		{
			*dst = *src;
			src += 1;
			dst += 1;
			count++;
		}
		*dst = '\0';
	}
	return (len);
}

size_t	ft_strlcat(char *dst, char const *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	r;

	i = 0;
	while (dst[i] != '\0')
		++i;
	r = 0;
	while (src[r] != '\0')
		++r;
	if (size <= i)
		r = r + size;
	else
		r = r + i;
	j = 0;
	while (src[j] != '\0' && i + 1 < size)
	{
		dst[i] = src[j];
		i++;
		j++;
	}
	dst[i] = '\0';
	return (r);
}

char	*ft_strdup(const char *s)
{
	int		i;
	char	*dup;

	i = -1;
	dup = (char *) malloc(ft_strlen(s) + 1);
	if (dup == NULL)
		return (NULL);
	while (s[++i])
		dup[i] = s[i];
	dup[i] = s[i];
	return (dup);
}

int	ft_sizing(char **splitted)
{
	int	i;

	i = 0;
	while (splitted[i])
	{
		i++;
	}
	return (i);
}
