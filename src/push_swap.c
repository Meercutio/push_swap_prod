#include "../includes/push_swap.h"

void	ft_sort_small(t_stack **stack_a)
{
	int	size;

	size = ft_lstsize_p(*stack_a);
	if (size == 2)
	{
		ft_sort_two(stack_a);
		exit(1);
	}
	if (size == 3)
	{
		ft_sort_three(stack_a);
		exit(1);
	}
}

void	ft_fill_index(t_stack **stack_a)
{
	int		*sort;
	int		size;
	int		j;
	int		i;
	t_stack	*tmp_a;

	j = 0;
	tmp_a = *stack_a;
	sort = ft_sort_index(stack_a);
	size = ft_lstsize_p(*stack_a);
	while (j < size)
	{
		i = 0;
		while (i < size)
		{
			if (tmp_a->value == sort[i])
				tmp_a->index = i;
			i++;
		}
		tmp_a = tmp_a->next;
		j++;
	}
}

void	ft_final_sort(t_stack **stack_a)
{
	int	i;
	int	j;

	i = 0;
	if (ft_is_sort(*stack_a) == 0)
	{
		while (ft_is_sort(*stack_a) != 1)
		{
			i++;
			ft_rotate(stack_a, 0);
		}
	}
	j = ft_lstsize_p(*stack_a) - i;
	if (i < j)
	{
		while (i--)
			ft_rotate(stack_a, 1);
	}
	else
		while (j--)
			ft_rrotate(stack_a, 1);
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (argc < 2)
		exit(1);
	stack_a = NULL;
	stack_b = NULL;
	if (argc == 2)
		ft_parse_str(argv[1], &stack_a);
	else
		ft_parse(argc, argv, &stack_a, 0);
	if (ft_lstsize_p(stack_a) < 4)
		ft_sort_small(&stack_a);
	ft_fill_index(&stack_a);
	ft_sort(&stack_a, &stack_b);
	ft_final_sort(&stack_a);
	return (0);
}
