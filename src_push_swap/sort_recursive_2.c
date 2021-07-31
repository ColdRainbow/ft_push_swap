#include "../include/push_swap.h"

void	rec_2_b(t_st *a, t_st *b, int count)
{
	while (count > 0)
	{
		push(b, a, PA);
		count--;
	}
	swap_or_ss_a(a, b);
}

void	rec_3_a(t_st *a, t_st *b, t_info *info, int count)
{
	if (count <= 2)
		swap_or_ss_a(a, b);
	else if (count == 3)
	{
		st_min_max(a->head, info, info->q);
		if (a->head->number == info->max_num)
		{
			swap(a, SA);
			rotate(a, RA);
			swap_or_ss_a(a, b);
			reverse_or_rra_a(a, b);
			swap_or_ss_a(a, b);
		}
		else if (a->head->next->number == info->max_num)
		{
			rotate(a, RA);
			swap_or_ss_a(a, b);
			reverse_or_rra_a(a, b);
			swap_or_ss_a(a, b);
		}
		else
			swap_or_ss_a(a, b);
	}
}

void	rec_3_b(t_st *a, t_st *b, t_info *info, int count)
{
	if (count <= 2)
		rec_2_b(a, b, count);
	else if (count == 3)
	{
		st_min_max(b->head, info, info->q);
		if (b->head->number == info->max_num)
			rec_2_b(a, b, count);
		else if (b->head->next->number == info->max_num)
		{
			swap(b, SB);
			rec_2_b(a, b, count);
		}
		else
		{
			push(b, a, PA);
			swap(b, SB);
			push(b, a, PA);
			swap(a, SA);
			rec_2_b(a, b, count - 2);
		}
	}
}

void	rec_more_action_a(t_st *a, t_st *b, t_recg *r, int count)
{
	int	rotated;

	rotated = 0;
	while (st_pivot_num(a->head, r->pivot, count, RECURSIVE_PIVOT_LESS))
	{
		if (a->head->number < r->pivot)
		{
			push(a, b, PB);
			r->old_group--;
			r->new_group++;
		}
		else
		{
			rotate(a, RA);
			rotated++;
		}
		count--;
	}
	while (rotated > 0)
	{
		reverse_or_rra_a(a, b);
		rotated--;
	}
}

void	rec_more_action_b(t_st *a, t_st *b, t_recg *r, int count)
{
	int	rotated;

	rotated = 0;
	while (st_pivot_num(b->head, r->pivot, count, RECURSIVE_PIVOT_MORE))
	{
		if (b->head->number >= r->pivot)
		{
			push(b, a, PA);
			r->old_group--;
			r->new_group++;
		}
		else
		{
			rotate(b, RB);
			rotated++;
		}
		count--;
	}
	while (rotated > 0)
	{
		reverse_rotate(b, RRB);
		rotated--;
	}
}
