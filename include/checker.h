#ifndef CHECKER_H
# define CHECKER_H

// malloc
# include <stdlib.h>
// write
# include <unistd.h>
// INT_MIN, INT_MAX
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

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 3
# endif

typedef enum e_case
{
	EN_NO_OP,
	EN_PA,
	EN_PB,
	EN_SA,
	EN_SB,
	EN_SS,
	EN_RA,
	EN_RB,
	EN_RR,
	EN_RRA,
	EN_RRB,
	EN_RRR
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
	unsigned int	quantity;
}				t_info;

// EXTRA
void	init_structs(t_st *a, t_st *b);
int		program_error(int err, t_st *a, t_st *b, char ***av_splited);
int		st_is_sorted_num(t_elem *head, t_elem *extra);
int		parse_args(t_st *stack, char **nums);
void	*list_add_back(t_elem **head, t_elem *last);
void	free_list(t_elem **head);

// STACK MANAGE
void	push(t_st *from, t_st *to, char *msg);
int		swap(t_st *stack, char *msg);
int		rotate(t_st *stack, char *msg);
int		reverse_rotate(t_st *stack, char *msg);
void	ss(t_st *a, t_st *b);
void	rr(t_st *a, t_st *b);
void	rrr(t_st *a, t_st *b);

// LIB
char	*ft_getline(int fd);
char	*ft_getline_error(char **static_buffer, char **buffer);
void	*ft_calloc(size_t num, size_t size);
char	*ft_strchr(const char *str, int c);
char	*ft_strjoin(char const *s1, char const *s2);
void	free_char(char **buffer);
void	free_arr(char ***arr);
char	**ft_split(char const *s, char c);
size_t	ft_strlen(const char *str);
int		ft_strncmp(const char *str1, const char *str2, size_t num);
void	*ft_memset(void *dest, int c, size_t n);
void	*ft_memcpy(void *dest, const void *source, size_t count);
void	ft_putstr_fd(char *s, int fd);

void	print_stacks(t_elem *head_1, t_elem *head_2);

#endif