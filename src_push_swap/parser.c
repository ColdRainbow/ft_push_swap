#include "../include/push_swap.h"

static int	char_to_int(char *str)
{
	int	i;
	int	a;
	int	b;

	i = 0;
	a = 1;
	b = 0;
	if (str[0] == '-')
		a = -1;
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
			b = b * 10 + (str[i] - 48);
		i++;
	}
	return (a * b);
}

static int	check_duplicates(t_elem *head)
{
	t_elem			*temp;
	unsigned int	i;

	i = 0;
	if (!head)
		return (0);
	while (head)
	{
		temp = head->next;
		while (temp)
		{
			if (head->number == temp->number)
				return (0);
			temp = temp->next;
		}
		head = head->next;
	}
	return (1);
}

static int	check_char_isalnum(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
			i++;
		else
			return (0);
	}
	return (1);
}

static int	check_str_is_int(char *str)
{
	int	len;

	len = ft_strlen(str);
	if (len > 11 || check_char_isalnum(str) == 0)
		return (0);
	if (len == 11)
	{
		if (str[0] == '-')
		{
			if (ft_strncmp(str, MIN_INT, len) > 0)
				return (0);
		}
		else if (str[0] == '+')
		{
			if (ft_strncmp(str, MAX_INT_P, len) > 0)
				return (0);
		}
	}
	else if (len == 10)
	{
		if (ft_strncmp(str, MAX_INT, len) > 0)
			return (0);
	}
	return (1);
}

int	parse_args(t_st *stack, char **nums)
{
	int	i;

	i = 0;
	while (nums[i])
	{
		if (check_str_is_int(nums[i]) == 1)
		{
			stack->last = list_add_back(&stack->head, stack->last);
			if (!stack->last)
				return (0);
			stack->last->number = char_to_int(nums[i]);
		}
		else
			return (0);
		i++;
	}
	if (check_duplicates(stack->head) == 0)
		return (0);
	return (1);
}
