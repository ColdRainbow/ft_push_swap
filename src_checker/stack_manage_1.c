#include "../include/checker.h"

//Swap - swap the first 2 elements at the top of stack. 
//Do nothing if there is only one or no elements).

static int	swap_extra(t_elem *head)
{
	t_elem	temp;

	if (head && head->next)
	{
		ft_memcpy(&temp, head, sizeof(t_elem) - (sizeof(t_elem *) * 2));
		ft_memcpy(head, head->next, sizeof(t_elem) - (sizeof(t_elem *) * 2));
		ft_memcpy(head->next, &temp, sizeof(t_elem) - (sizeof(t_elem *) * 2));
		return (1);
	}
	return (0);
}

int	swap(t_st *stack, char *msg)
{
	if (swap_extra(stack->head))
	{
		if (msg)
			ft_putstr_fd(msg, 1);
		return (1);
	}
	return (0);
}

//Push - take the first element at the top of head_1
//and put it at the top of head_2. 
//Do nothing if b is empty.

static int	push_extra(t_elem **from_head, t_elem **from_last,
							t_elem **to_head, t_elem **to_last)
{
	t_elem	*tmp;

	if (!*from_head)
		return (0);
	if (*to_head)
	{
		tmp = *from_head;
		*from_head = (*from_head)->next;
		if (*from_head)
			(*from_head)->prev = NULL;
		tmp->next = *to_head;
		(*to_head)->prev = tmp;
		*to_head = tmp;
	}
	else
	{
		*to_head = *from_head;
		*to_last = *from_head;
		*from_head = (*from_head)->next;
		(*from_head)->prev = NULL;
		(*to_head)->next = NULL;
	}
	if (!*from_head)
		*from_last = NULL;
	return (1);
}

void	push(t_st *from, t_st *to, char *msg)
{
	if (push_extra(&from->head, &from->last, &to->head, &to->last))
	{
		if (msg)
			ft_putstr_fd(msg, 1);
	}
}
