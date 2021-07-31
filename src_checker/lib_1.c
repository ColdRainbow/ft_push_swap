#include "../include/checker.h"

int	ft_strncmp(const char *str1, const char *str2, size_t num)
{
	int	a;

	a = 0;
	if (num == 0)
		return (0);
	while (num != 0 && str1[a] != '\0' && str2[a] == str1[a])
	{
		num--;
		if (str1[a] == str2[a] && num != 0)
			a++;
	}
	return (((unsigned char *)str1)[a] - ((unsigned char *)str2)[a]);
}

void	*ft_memset(void *dest, int c, size_t n)
{
	size_t	a;

	a = 0;
	while (a < n)
	{
		((char *)dest)[a] = (unsigned char)c;
		a++;
	}
	return (dest);
}

void	ft_putstr_fd(char *s, int fd)
{
	int	a;

	a = 0;
	if (s)
	{
		while (s[a] != '\0')
		{
			write(fd, &s[a], 1);
			a++;
		}
	}
}

void	*ft_calloc(size_t num, size_t size)
{
	size_t	a;
	char	*res;

	a = 0;
	res = (char *)malloc(num * size);
	if (res == NULL)
		return (NULL);
	while (a < num * size)
	{
		res[a] = 0;
		a++;
	}
	return ((void *)res);
}

char	*ft_strchr(const char *str, int c)
{
	char	ch;

	ch = c;
	while (*str)
	{
		if (*str == ch)
			return ((char *)str);
		str++;
	}
	return (NULL);
}
