#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

# define MIN_INT "-2147483648"
# define MAX_INT "2147483647"
# define MAX_INT_P "+2147483647"

# define PA "pa\n"
# define PB "pb\n"
# define SA "sa\n"
# define SB "sb\n"
# define SS "ss\n"
# define RA "ra\n"
# define RB "rb\n"
# define RR "rr\n"
# define RRA "rra\n"
# define RRB "rrb\n"
# define RRR "rrr\n"

typedef enum e_case
{
	ABOVE,
	BELOW,
	RECURSIVE_PIVOT_LESS,
	RECURSIVE_PIVOT_MORE,
	INDEX_TMP,
	INDEX_MAIN
}				t_case;

typedef struct s_elem
{
	int				number;
	int				index;
	int				index_tmp;
	struct s_elem	*prev;
	struct s_elem	*next;
}				t_elem;

typedef struct s_st
{
	struct s_elem	*head;
	struct s_elem	*last;
}				t_st;

typedef struct s_info
{
	int				max_num;
	int				max_num_index;
	int				min_num;
	int				i4;
	int				i3;
	int				i2;
	int				i1;
	unsigned int	q;
}				t_info;

typedef struct s_recg
{
	int			old_group;
	int			new_group;
	int			pivot;
}				t_recg;

typedef struct s_gr
{
	int			quantity;
	struct s_gr	*next;

}	t_gr;

void	init_structs(t_st *a, t_st *b, t_info *info);
int		parse_args(t_st *stack, char **nums);
int		program_error(int err, t_st *a, t_st *b, char ***av_splited);

// SORT RECURSIVE
int		sort_recursive(t_st *a, t_st *b, t_info *info);
void	sort_recursive_a(t_st *a, t_st *b, t_info *info, int gr_count);
void	sort_recursive_b(t_st *a, t_st *b, t_info *info, int gr_count);
int		sort_recursive_grouping(t_st *a, t_st *b, t_info *info, t_gr **gr);
void	rec_more_action_a(t_st *a, t_st *b, t_recg *r, int count);
void	rec_more_action_b(t_st *a, t_st *b, t_recg *r, int count);
void	rec_2_b(t_st *a, t_st *b, int count);
void	rec_3_a(t_st *a, t_st *b, t_info *info, int count);
void	rec_3_b(t_st *a, t_st *b, t_info *info, int count);

int		gr_add(t_gr **head, int count);
// SORT RECURSIVE UTILS
int		st_pivot_num(t_elem *head, int pivot, int count, t_case less_more);
int		st_is_sorted_index(t_elem *head, int count);
int		st_find_pivot__group(t_elem *head, int gr_count);

// SORT SIMPLE
void	sort_simple(t_st *a, t_st *b, t_info *info);
void	sort_simple_grouping(t_st *a, t_st *b, t_info *info);

// SORT SIMPLE UTILS
t_case	best_way_for_i4(t_elem *head, t_info *info);
void	put_in_order_during(t_st *a, t_st *b, t_info *info);
void	put_in_order_end(t_st *a, t_st *b, t_info *info);

//SORT UTILS
void	st_set_index(t_elem *stack, t_info *info,
			int gr_count, t_case is_tmp_index);
int		st_is_sorted_num(t_elem *head, t_elem *extra);
int		st_q(t_elem *head, t_info *info);
void	st_min_max(t_elem *head, t_info *info, int count);
int		st_piv_index(t_elem *head, int pivot, int count);
void	st_a_sort_3_in_empty(t_st *stack, t_info *info);

//STACK
void	push(t_st *from, t_st *to, char *msg);
int		swap(t_st *stack, char *msg);
int		rotate(t_st *stack, char *msg);
int		reverse_rotate(t_st *stack, char *msg);
void	ss(t_st *a, t_st *b);
void	rr(t_st *a, t_st *b);
void	rrr(t_st *a, t_st *b);
void	swap_or_ss_a(t_st *a, t_st *b);
void	reverse_or_rra_a(t_st *a, t_st *b);

//LIST
void	*list_add_back(t_elem **head, t_elem *last);
void	free_list(t_elem **head);
void	gr_free(t_gr **head);

// LIB
void	free_arr(char ***arr);
char	**ft_split(char const *s, char c);
size_t	ft_strlen(const char *str);
int		ft_strncmp(const char *str1, const char *str2, size_t num);
void	ft_putstr_fd(char *s, int fd);
void	*ft_memset(void *dest, int c, size_t n);
void	*ft_memcpy(void *dest, const void *source, size_t count);
char	**ft_split(char const *s, char c);

#endif
