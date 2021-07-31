#include "../include/push_swap.h"

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

// for recursive
static t_gr	*gr_new(t_gr **head)
{
	t_gr	*new;

	new = (t_gr *)malloc(sizeof(t_gr));
	if (!new)
		return (NULL);
	ft_memset(new, 0, sizeof(t_gr));
	if (head && *head)
		new->next = *head;
	*head = new;
	return (new);
}

// for recursive
void	gr_free(t_gr **head)
{
	t_gr	*cur_lst;

	while (head && *head)
	{
		cur_lst = *head;
		*head = (*head)->next;
		free(cur_lst);
	}
}

// for recursive
int	gr_add(t_gr **head, int count)
{
	if (count <= 0 || !gr_new(head))
	{
		gr_free(head);
		return (1);
	}
	(*head)->quantity = count;
	return (0);
}
