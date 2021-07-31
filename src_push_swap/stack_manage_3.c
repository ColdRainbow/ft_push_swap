#include "../include/push_swap.h"

void	ss(t_st *a, t_st *b)
{
	if (swap(a, NULL) && swap(b, NULL))
		ft_putstr_fd(SS, 1);
}

void	rr(t_st *a, t_st *b)
{
	if (rotate(a, NULL) && rotate(b, NULL))
		ft_putstr_fd(RR, 1);
}

void	rrr(t_st *a, t_st *b)
{
	if (reverse_rotate(a, NULL) && reverse_rotate(b, NULL))
		ft_putstr_fd(RRR, 1);
}

// проверяет, если в стеке А первое число больше последнего:
// 1. если в стеке Б противоположная ситуация (первое число меньше последнего),
// то делает reverse_rotate в двух стеках
// 2. в противном случае reverse_rotate только для стека A

void	reverse_or_rra_a(t_st *a, t_st *b)
{
	if (b->head && b->last && b->head != b->last
		&& b->last->number > b->head->number)
		rrr(a, b);
	else
		reverse_rotate(a, RRA);
}

// проверяет, если в стеке А большее число из двух верних сверху:
// 1. если в стеке Б противоположная ситуация (меньшее из двух верхних сверху),
// то делает swap в двух стеках
// 2. в противном случае swap только для стека A

void	swap_or_ss_a(t_st *a, t_st *b)
{
	if (a->head && a->head->next && a->head->number > a->head->next->number)
	{
		if (b && b->head && b->head->next
			&& b->head->number < b->head->next->number)
			ss(a, b);
		else
			swap(a, SA);
	}
}
