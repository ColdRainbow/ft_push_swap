#include "../include/checker.h"

char	*ft_getline_error(char **static_buffer, char **buffer)
{
	free_char(buffer);
	free_char(static_buffer);
	return (NULL);
}
