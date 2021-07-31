#include "../include/push_swap.h"

int	st_pivot_num(t_elem *head, int pivot, int count, t_case less_more)
{
	while (head && count > 0)
	{
		if (less_more == RECURSIVE_PIVOT_LESS)
		{
			if (head->number < pivot)
				return (1);
		}
		else if (less_more == RECURSIVE_PIVOT_MORE)
		{
			if (head->number >= pivot)
				return (1);
		}
		head = head->next;
		count--;
	}
	return (0);
}

// pivot by number, NOT BY INDEX

int	st_find_pivot__group(t_elem *head, int gr_count)
{
	int	pivot;
	int	midpoint;

	pivot = 0;
	midpoint = (gr_count + 1) / 2;
	while (head && gr_count > 0)
	{
		if (head->index_tmp == midpoint)
		{
			pivot = head->number;
			break ;
		}
		head = head->next;
		gr_count--;
	}
	return (pivot);
}

int	st_is_sorted_index(t_elem *head, int count)
{
	int			i;
	t_elem		*lower;

	i = count;
	while (i > 1)
	{
		head = head->next;
		i--;
	}
	lower = head->next;
	i = 0;
	while (head)
	{
		if (head->index != lower->index - 1)
			break ;
		i++;
		head = head->prev;
		lower = lower->prev;
	}
	return (i);
}
