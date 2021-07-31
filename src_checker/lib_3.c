#include "../include/checker.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

void	*ft_memcpy(void *dest, const void *source, size_t size)
{
	char	*dest_copy;
	char	*source_copy;

	if (!dest && !source)
		return (NULL);
	dest_copy = (char *)dest;
	source_copy = (char *)source;
	while (size)
	{
		*dest_copy = *source_copy;
		dest_copy++;
		source_copy++;
		size--;
	}
	return (dest);
}

static size_t	ft_strjoin_get_len(char const *s1, char const *s2)
{
	size_t	len;

	len = 0;
	if (s1)
		len = ft_strlen(s1);
	if (s2)
		len += ft_strlen(s2);
	return (len);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*dest;
	size_t	i;
	size_t	len;

	i = 0;
	if (!s1 && !s2)
		return (NULL);
	len = ft_strjoin_get_len(s1, s2);
	dest = (char *)ft_calloc(len + 1, sizeof(char));
	if (!dest)
		return (NULL);
	while (s1 && *s1)
	{
		dest[i++] = *s1;
		s1++;
	}
	while (s2 && *s2)
	{
		dest[i++] = *s2;
		s2++;
	}
	dest[i] = '\0';
	return (dest);
}
