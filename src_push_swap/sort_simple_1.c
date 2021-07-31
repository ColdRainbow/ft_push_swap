#include "../include/push_swap.h"

void	sort_simple_grouping(t_st *a, t_st *b, t_info *info)
{
	int	pivot;
	int	step;

	pivot = 0;
	if (info->q >= 50)
		step = info->q / 5;
	else
		step = info->q / 3;
	st_min_max(a->head, info, info->q);
	while (st_q(a->head, info) > 3)
	{
		st_min_max(a->head, info, info->q);
		pivot += step;
		while (st_q(a->head, info) > 3
			&& st_piv_index(a->head, pivot, info->q))
		{
			if (a->head->index < pivot
				&& (a->head->index < (info->max_num_index - 2)))
				push(a, b, PB);
			else
				rotate(a, RA);
		}
	}
	st_a_sort_3_in_empty(a, info);
}

static int	num_push_extra(t_info *info)
{
	int	i;

	i = 1;
	if (info->i3 == -1)
	{
		info->i2 = -1;
		info->i1 = -1;
	}
	if (info->i2 == -1)
		info->i1 = -1;
	if (info->i3 >= 0)
		i++;
	if (info->i2 >= 0)
		i++;
	if (info->i1 >= 0)
		i++;
	return (i);
}

static int	num_push(t_st *stack, t_info *info, t_case way)
{
	t_elem	*temp;

	if (way == ABOVE)
		temp = stack->head;
	else
		temp = stack->last;
	info->i3 = -1;
	info->i2 = -1;
	info->i1 = -1;
	while (temp && temp->index != info->i4)
	{
		if (temp->index == info->i4 - 1)
			info->i3 = temp->index;
		else if (temp->index == info->i4 - 2)
			info->i2 = temp->index;
		else if (temp->index == info->i4 - 3)
			info->i1 = temp->index;
		if (way == ABOVE)
			temp = temp->next;
		else
			temp = temp->prev;
	}
	return (num_push_extra(info));
}

static void	action_for_b(t_st *b, t_case way)
{
	if (way == ABOVE)
		rotate(b, RB);
	else
		reverse_rotate(b, RRB);
}

// алгоритм для 0-500 чисел

void	sort_simple(t_st *a, t_st *b, t_info *info)
{
	t_case	way;
	int		num_to_push;
	int		pushed;

	sort_simple_grouping(a, b, info);
	while (st_q(b->head, info) > 0)
	{
		st_min_max(b->head, info, info->q);
		way = best_way_for_i4(b->head, info);
		num_to_push = num_push(b, info, way);
		pushed = 0;
		while (st_q(b->head, info) && pushed < num_to_push)
		{
			if (b->head->index == info->i4 ||b->head->index == info->i3
				|| b->head->index == info->i2 || b->head->index == info->i1)
			{
				push(b, a, PA);
				put_in_order_during(a, b, info);
				pushed++;
			}
			else
				action_for_b(b, way);
		}
		put_in_order_end(a, b, info);
	}
}
