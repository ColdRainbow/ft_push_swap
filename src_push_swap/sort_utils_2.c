#include "../include/push_swap.h"

// проставляем индексы числам для tmp

void	st_set_index_extra(t_elem *tmp, t_elem **point, int *min, int *max)
{
	while (tmp)
	{
		if (tmp->number > *min && tmp->number <= *max)
		{
			*max = tmp->number;
			*point = tmp;
		}
		tmp = tmp->next;
	}
}

void	st_set_index(t_elem *stack, t_info *info,
		int gr_count, t_case is_tmp_index)
{
	t_elem	*tmp;
	t_elem	*point;
	int		i;
	int		min;
	int		max;

	i = 1;
	min = info->min_num;
	max = info->max_num;
	while (stack && i <= gr_count)
	{
		tmp = stack;
		st_set_index_extra(tmp, &point, &min, &max);
		min = max;
		max = INT_MAX;
		if (is_tmp_index == INDEX_TMP)
			point->index_tmp = i;
		else
			point->index = i;
		i++;
	}	
}
