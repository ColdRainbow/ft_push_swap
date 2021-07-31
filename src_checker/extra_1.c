#include "../include/checker.h"

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

void	init_structs(t_st *a, t_st *b)
{
	ft_memset(a, 0, sizeof(t_st) * 1);
	ft_memset(b, 0, sizeof(t_st) * 1);
}
