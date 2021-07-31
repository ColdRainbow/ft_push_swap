#include "../include/push_swap.h"

size_t	ft_strlen(const char *str)
{
	size_t	a;

	a = 0;
	while (str[a] != '\0')
		a++;
	return (a);
}

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

void	*ft_memcpy(void *dest, const void *source, size_t count)
{
	size_t	a;

	a = 0;
	if (count == 0 || dest == source)
		return (dest);
	while (a < count)
	{
		((char *)dest)[a] = ((unsigned char *)source)[a];
		a++;
	}
	return (dest);
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
