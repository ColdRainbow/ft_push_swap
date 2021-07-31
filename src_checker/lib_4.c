#include "../include/checker.h"

static char	*ft_getline_concatenate(char **static_buffer, char **buffer)
{
	char	*tmp;
	char	*buffer_if_null;

	if (buffer)
		buffer_if_null = *buffer;
	else
		buffer_if_null = NULL;
	tmp = ft_strjoin(*static_buffer, buffer_if_null);
	if (!tmp)
		return (ft_getline_error(static_buffer, buffer));
	else
	{
		free_char(static_buffer);
		*static_buffer = tmp;
		return (*static_buffer);
	}
}

static char	*ft_getline_eof(char **static_buffer, size_t len)
{
	char	*line;

	line = NULL;
	if (len)
		line = ft_strjoin(*static_buffer, NULL);
	free_char(static_buffer);
	return (line);
}

static char	*ft_getline_newline(char **static_buffer, size_t len)
{
	char	*line;
	char	*tmp;

	line = ft_calloc((len + 1), sizeof(char));
	if (!line)
		return (ft_getline_error(static_buffer, NULL));
	ft_memcpy(line, *static_buffer, len);
	tmp = ft_strjoin((*static_buffer + len + 1), NULL);
	if (!tmp)
		return (ft_getline_error(static_buffer, NULL));
	else if (*tmp)
	{
		free_char(static_buffer);
		*static_buffer = tmp;
	}
	else
	{
		free_char(&tmp);
		free_char(static_buffer);
	}
	return (line);
}

static char	*ft_getline_extra(char **static_buffer, char *nl)
{
	char	*line;
	size_t	len;

	if (nl)
	{
		len = nl - *static_buffer;
		line = ft_getline_newline(static_buffer, len);
	}
	else
	{
		len = ft_strlen(*static_buffer);
		line = ft_getline_eof(static_buffer, len);
	}
	return (line);
}

// nl is the possible pointer to new line
char	*ft_getline(int fd)
{
	static char		*static_buffer;
	char			*buffer;
	char			*nl;
	ssize_t			rd;

	buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!buffer)
		return (NULL);
	while (1)
	{
		rd = read(fd, buffer, BUFFER_SIZE);
		if (rd == -1)
			return (ft_getline_error(&static_buffer, &buffer));
		buffer[rd] = '\0';
		if (!ft_getline_concatenate(&static_buffer, &buffer))
			return (NULL);
		nl = ft_strchr(static_buffer, '\n');
		if (nl || rd == 0)
		{
			free_char(&buffer);
			break ;
		}
	}
	return (ft_getline_extra(&static_buffer, nl));
}
