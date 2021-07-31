#include "../include/checker.h"

void	check_apply_command(t_st *a, t_st *b, t_case cmd)
{
	if (cmd == EN_PA)
		push(b, a, NULL);
	else if (cmd == EN_PB)
		push(a, b, NULL);
	else if (cmd == EN_SA)
		swap(a, NULL);
	else if (cmd == EN_SB)
		swap(b, NULL);
	else if (cmd == EN_SS)
		ss(a, b);
	else if (cmd == EN_RA)
		rotate(a, NULL);
	else if (cmd == EN_RB)
		rotate(b, NULL);
	else if (cmd == EN_RR)
		rr(a, b);
	else if (cmd == EN_RRA)
		reverse_rotate(a, NULL);
	else if (cmd == EN_RRB)
		reverse_rotate(b, NULL);
	else if (cmd == EN_RRR)
		rrr(a, b);
}

static t_case	check_is_valid_command_extra(char *line, size_t len)
{
	if (ft_strncmp(RRA, line, len) == 0)
		return (EN_RRA);
	else if (ft_strncmp(RRB, line, len) == 0)
		return (EN_RRB);
	else if (ft_strncmp(RRR, line, len) == 0)
		return (EN_RRR);
	else if (ft_strncmp(PA, line, len) == 0)
		return (EN_PA);
	else if (ft_strncmp(PB, line, len) == 0)
		return (EN_PB);
	return (EN_NO_OP);
}

t_case	check_is_valid_command(char *line)
{
	size_t	len;

	len = ft_strlen(line);
	if (ft_strncmp(SA, line, len) == 0)
		return (EN_SA);
	else if (ft_strncmp(SB, line, len) == 0)
		return (EN_SB);
	else if (ft_strncmp(SS, line, len) == 0)
		return (EN_SS);
	else if (ft_strncmp(RA, line, len) == 0)
		return (EN_RA);
	else if (ft_strncmp(RB, line, len) == 0)
		return (EN_RB);
	else if (ft_strncmp(RR, line, len) == 0)
		return (EN_RR);
	else
		return (check_is_valid_command_extra(line, len));
}

int	get_command(t_st *a, t_st *b)
{
	t_case	cmd;
	char	*line;

	line = NULL;
	while (1)
	{
		line = ft_getline(0);
		if (!line)
			break ;
		cmd = check_is_valid_command(line);
		if (cmd == EN_NO_OP)
		{
			free_char(&line);
			return (0);
		}
		else
			check_apply_command(a, b, cmd);
		free_char(&line);
	}
	if (st_is_sorted_num(a->head, b->head))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	return (1);
}

int	main(int ac, char **av)
{
	t_st	stack[2];
	char	**av_splited;

	av_splited = NULL;
	init_structs(stack, stack + 1);
	if (ac == 1)
		return (0);
	if (ac < 2)
		return (program_error(2, NULL, NULL, NULL));
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
	if (!get_command(stack, stack + 1))
		return (program_error(6, stack, stack + 1, &av_splited));
	return (program_error(0, stack, stack + 1, &av_splited));
}
