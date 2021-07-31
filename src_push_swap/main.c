#include "../include/push_swap.h"

static int	main_sort(t_st *a, t_st *b, t_info *info)
{
	if (st_q(a->head, info) > 1 && !st_is_sorted_num(a->head, b->head))
	{
		info->max_num_index = info->q - 1;
		st_min_max(a->head, info, info->q);
		st_set_index(a->head, info, info->q, INDEX_MAIN);
		if (info->q >= 500 || info->q == 5)
		{
			if (sort_recursive(a, b, info) != 0)
				return (1);
		}
		else
			sort_simple(a, b, info);
	}
	return (0);
}

int	main(int ac, char **av)
{
	t_st	stack[2];
	t_info	info[1];
	char	**av_splited;

	av_splited = NULL;
	init_structs(stack, stack + 1, info);
	if (ac == 1)
		return (0);
	if (ac < 2)
		return (program_error(2, stack, stack + 1, &av_splited));
	av++;
	if (ac == 2)
	{
		av_splited = ft_split(*av, ' ');
		if (!av_splited)
			return (program_error(3, stack, stack + 1, &av_splited));
	}
	if (av_splited)
		av = av_splited;
	if (parse_args(stack, av) != 1)
		return (program_error(5, stack, stack + 1, &av_splited));
	if (main_sort(stack, stack + 1, info) != 0)
		return (program_error(6, stack, stack + 1, &av_splited));
	return (program_error(0, stack, stack + 1, &av_splited));
}
