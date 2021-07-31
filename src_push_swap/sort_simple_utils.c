#include "../include/push_swap.h"

void	put_in_order_end(t_st *a, t_st *b, t_info *info)
{
	while (a->last->index == info->i2 || a->last->index == info->i1)
	{
		reverse_or_rra_a(a, b);
		swap_or_ss_a(a, b);
	}
}

void	put_in_order_during(t_st *a, t_st *b, t_info *info)
{
	if (a->head->index == info->i2 || a->head->index == info->i1)
		rotate(a, RA);
	swap_or_ss_a(a, b);
}

t_case	best_way_for_i4(t_elem *head, t_info *info)
{
	int	midpoint;

	if (info->q == 0)
		return (0);
	midpoint = (info->q + 1) / 2;
	while (head && head->index != info->i4)
	{
		midpoint--;
		head = head->next;
	}
	if (info->q % 2 == 0)
	{
		if (midpoint >= 0)
			return (ABOVE);
		else
			return (BELOW);
	}
	if (midpoint > 0)
		return (ABOVE);
	else
		return (BELOW);
}
