#include "../includes/push_swap.h"

int	*ft_sort_index(t_stack **stack_a)
{
	int		size;
	int		*sort;
	int		i;
	t_stack	*tmp_a;

	size = ft_lstsize_p(*stack_a);
	sort = (int *)malloc(sizeof (int) * size);
	i = 0;
	tmp_a = *stack_a;
	while (i < size)
	{
		sort[i] = tmp_a->value;
		i++;
		tmp_a = tmp_a->next;
	}
	ft_bubbleSort(sort, size);
	return (sort);
}

void	ft_comm_exe(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp;

	tmp = *stack_b;
	while (*stack_b)
	{
		ft_fill(stack_a, stack_b);
		while (tmp)
		{
			ft_find_min(&tmp);
			tmp = tmp->next;
		}
		ft_path_def(stack_a, stack_b);
		tmp = *stack_b;
	}
}

void	ft_first_operat(t_stack **stack_a, t_stack **stack_b)
{
	int	size;
	int	i;

	size = ft_lstsize_p(*stack_a);
	i = 0;
	while (i++ < size)
	{
		if (ft_is_sort(*stack_a))
			break ;
		else if ((*stack_a)->index == 0)
		{
			ft_rotate(stack_a, 1);
			break ;
		}
		else
			ft_push(stack_a, stack_b, 2);
	}
}

void	ft_sort(t_stack **stack_a, t_stack **stack_b)
{
	int	j;

	ft_first_operat(stack_a, stack_b);
	j = (*stack_a)->index;
	while ((*stack_a)->index != 0)
	{
		if (ft_is_sort(*stack_a))
			break ;
		else if ((*stack_a)->index >= j)
		{
			j = (*stack_a)->index;
			ft_rotate(stack_a, 1);
		}
		else
			ft_push(stack_a, stack_b, 2);
	}
	ft_comm_exe(stack_a, stack_b);
}
