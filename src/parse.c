#include "../includes/push_swap.h"

int	ft_is_sort(t_stack *stack)
{
	while (stack->next)
	{
		if (stack->value > stack->next->value)
			return (0);
		stack = stack->next;
	}
	return (1);
}

int	ft_valid(t_stack *lst, int num)
{
	if (lst == NULL)
		return (0);
	while (lst)
	{
		if (lst->value == num)
			return (1);
		lst = lst->next;
	}
	return (0);
}

void	ft_parse(int argc, char **argv, t_stack **stack, int is_str_parse)
{
	int	i;
	int	num;

	if (is_str_parse)
		i = 0;
	else
		i = 1;
	while (i < argc)
	{
		num = ft_atoi(argv[i]);
		if (((ft_strlen(argv[i]) > 2) && (num == 0 || num == -1)) || \
			(argv[i][0] != '0' && num == 0) || ft_valid(*stack, num) || \
			(num > 2147483647 || num < -2147483648))
			ft_error();
		ft_lstadd_back_p(stack, ft_lstnew_p(num, 0));
		i++;
	}
}

void	ft_parse_str(char *str, t_stack **lst)
{
	char	**split_str;
	int		len_split;
	int		i;

	split_str = ft_split(str, ' ');
	if (!split_str)
		ft_error();
	len_split = 0;
	while (split_str[len_split])
		len_split++;
	ft_parse(len_split, split_str, lst, 1);
	i = 0;
	while (i < len_split)
	{
		free(split_str[i]);
		i++;
	}
	free(split_str[i]);
	free(split_str);
}
