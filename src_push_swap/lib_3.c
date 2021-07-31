#include "../include/push_swap.h"

void	free_arr(char ***arr)
{
	int	i;

	i = 0;
	if (!arr || !*arr)
		return ;
	while (arr[0][i])
	{
		free(arr[0][i]);
		i++;
	}
	free(arr[0]);
	arr[0] = NULL;
}
