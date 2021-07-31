#include "../include/checker.h"

// stack
void	*list_add_back(t_elem **head, t_elem *last)
{
	t_elem	*new_elem;

	new_elem = (t_elem *)malloc(sizeof(t_elem));
	if (!new_elem)
		return (NULL);
	ft_memset(new_elem, 0, sizeof(t_elem));
	if (!*head)
	{
		*head = new_elem;
		last = new_elem;
	}
	else
	{
		new_elem->prev = last;
		last->next = new_elem;
		last = new_elem;
	}
	return (last);
}

// stack
void	free_list(t_elem **head)
{
	t_elem	*temp;

	if (!head)
		return ;
	while (*head)
	{
		temp = *head;
		*head = (*head)->next;
		free(temp);
	}
}

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

void	free_char(char **s)
{
	if (s && *s)
	{
		free(*s);
		*s = NULL;
	}
}

int	st_is_sorted_num(t_elem *head, t_elem *extra)
{
	if (extra)
		return (0);
	while (head)
	{
		if (head->next && head->number > head->next->number)
			return (0);
		head = head->next;
	}
	return (1);
}
