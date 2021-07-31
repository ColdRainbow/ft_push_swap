#include "../include/push_swap.h"

void	init_structs(t_st *a, t_st *b, t_info *info)
{
	ft_memset(a, 0, sizeof(t_st) * 1);
	ft_memset(b, 0, sizeof(t_st) * 1);
	ft_memset(info, 0, sizeof(t_info) * 1);
	info->max_num = INT_MIN;
	info->min_num = INT_MAX;
}

// manage yourself your programm!111!!
// fuck exit(), all my hommies use return
int	program_error(int err, t_st *a, t_st *b, char ***av_splited)
{
	free_arr(av_splited);
	free_list(&a->head);
	free_list(&b->head);
	if (err != 0)
		ft_putstr_fd("Error\n", 1);
	return (err);
}
