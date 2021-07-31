#include "../include/push_swap.h"

// для сортировки трех чисел в пустом стеке (чисел в стеке не больше трех)
void	st_a_sort_3_in_empty(t_st *a, t_info *info)
{
	if (info->q <= 3)
	{
		if (a->head && a->head->number == info->max_num)
			rotate(a, RA);
		else if (a->head && a->head->next
			&& a->head->next->number == info->max_num)
		{
			reverse_rotate(a, RRA);
		}
		if (a->head && a->head->next && a->head->number > a->head->next->number)
			swap(a, SA);
	}
}

// проверяет, есть ли индексы чисел меньше, чем пивот
int	st_piv_index(t_elem *head, int pivot, int count)
{
	while (head && count > 0)
	{
		if (head->index < pivot)
			return (1);
		head = head->next;
		count--;
	}
	return (0);
}

// подсчет кол-ва чисел в стеке
int	st_q(t_elem *head, t_info *info)
{
	int	count;

	count = 0;
	while (head)
	{
		head = head->next;
		count++;
	}
	info->q = count;
	return (count);
}

// находим максимальное и минимальное числа в стеке

void	st_min_max(t_elem *head, t_info *info, int count)
{
	info->min_num = INT_MAX;
	info->max_num = INT_MIN;
	while (head && count > 0)
	{
		if (head->number < info->min_num)
			info->min_num = head->number;
		if (head->number > info->max_num)
		{
			info->max_num = head->number;
			info->i4 = head->index;
		}
		head->index_tmp = 0;
		head = head->next;
		count--;
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
