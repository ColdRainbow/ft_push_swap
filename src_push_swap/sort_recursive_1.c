#include "../include/push_swap.h"

int	sort_recursive_grouping(t_st *a, t_st *b, t_info *info, t_gr **gr)
{
	int	pushed;
	int	pivot;

	while (st_q(a->head, info) > 3)
	{
		st_min_max(a->head, info, info->q);
		st_set_index(a->head, info, info->q, INDEX_TMP);
		pivot = st_find_pivot__group(a->head, info->q);
		pushed = 0;
		while (st_q(a->head, info) > 3 && st_piv_index(a->head, pivot, info->q))
		{
			if (a->head->index < pivot
				&& (a->head->index < (info->max_num_index - 2)))
			{
				push(a, b, PB);
				pushed++;
			}
			else
				rotate(a, RA);
		}
		if (gr_add(gr, pushed) != 0)
			return (0);
	}
	st_a_sort_3_in_empty(a, info);
	return (1);
}

void	sort_recursive_a(t_st *a, t_st *b, t_info *info, int gr_count)
{
	t_recg	rec_info;

	gr_count = gr_count - st_is_sorted_index(a->head, gr_count);
	ft_memset(&rec_info, 0, sizeof(t_recg));
	rec_info.old_group = gr_count;
	if (gr_count <= 3)
		rec_3_a(a, b, info, gr_count);
	else
	{
		st_min_max(a->head, info, gr_count);
		st_set_index(a->head, info, gr_count, INDEX_TMP);
		rec_info.pivot = st_find_pivot__group(a->head, gr_count);
		rec_more_action_a(a, b, &rec_info, gr_count);
		sort_recursive_a(a, b, info, rec_info.old_group);
		sort_recursive_b(a, b, info, rec_info.new_group);
	}
}

void	sort_recursive_b(t_st *a, t_st *b, t_info *info, int gr_count)
{
	t_recg	rec_info;

	ft_memset(&rec_info, 0, sizeof(t_recg));
	rec_info.old_group = gr_count;
	if (gr_count <= 3)
		rec_3_b(a, b, info, gr_count);
	else
	{
		st_min_max(b->head, info, gr_count);
		st_set_index(b->head, info, gr_count, INDEX_TMP);
		rec_info.pivot = st_find_pivot__group(b->head, gr_count);
		rec_more_action_b(a, b, &rec_info, gr_count);
		sort_recursive_a(a, b, info, rec_info.new_group);
		sort_recursive_b(a, b, info, rec_info.old_group);
	}
}

// алгоритм для 5 и 500+ чисел включительно
// группируем на числа на группы попутно скидывая все в Б
// кроме трех наибольших чисел
// во время группировки записываем количество чисел в группе в структуру t_gr
// начинаем сортировку для каждой группы с помощью sort_recursive_b
int	sort_recursive(t_st *a, t_st *b, t_info *info)
{
	t_gr	*gr;
	t_gr	*gr_tmp;

	gr = NULL;
	gr_tmp = NULL;
	if (sort_recursive_grouping(a, b, info, &gr) == 0)
	{
		gr_free(&gr);
		return (1);
	}
	gr_tmp = gr;
	while (gr_tmp)
	{
		sort_recursive_b(a, b, info, gr_tmp->quantity);
		gr_tmp = gr_tmp->next;
	}
	gr_free(&gr);
	return (0);
}
