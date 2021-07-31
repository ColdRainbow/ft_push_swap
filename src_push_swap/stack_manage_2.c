#include "../include/push_swap.h"

//Rotate - shift up all elements of stack by 1. 
//The first element becomes the last one.

static int	rotate_extra(t_elem **head, t_elem **last)
{
	t_elem	*tmp;

	if (*head && *last && *head != *last)
	{
		tmp = *head;
		tmp->prev = (*last);
		*head = (*head)->next;
		(*head)->prev = NULL;
		(*last)->next = tmp;
		*last = tmp;
		(*last)->next = NULL;
		return (1);
	}
	return (0);
}

int	rotate(t_st *stack, char *msg)
{
	if (rotate_extra(&stack->head, &stack->last))
	{
		if (msg)
			ft_putstr_fd(msg, 1);
		return (1);
	}
	return (0);
}

//Reverse rotate - shift down all elements of stack by 1.
//The last element becomes the first one.

static int	reverse_rotate_extra(t_elem **head, t_elem **last)
{
	t_elem	*tmp;

	if (*head && *last && *head != *last)
	{
		tmp = (*last)->prev;
		tmp->next = NULL;
		(*last)->next = *head;
		(*last)->prev = NULL;
		(*head)->prev = *last;
		*head = *last;
		*last = tmp;
		return (1);
	}
	return (0);
}

int	reverse_rotate(t_st *stack, char *msg)
{
	if (reverse_rotate_extra(&stack->head, &stack->last))
	{
		if (msg)
			ft_putstr_fd(msg, 1);
		return (1);
	}
	return (0);
}
