#include "../includes/push_swap.h"

int	ft_find_max_indx(t_stack *stack_a)
{
	int		max;
	t_stack	*tmp;

	tmp = stack_a;
	max = tmp->index;
	while (tmp)
	{
		if (tmp->index > max)
			max = tmp->index;
		tmp = tmp->next;
	}
	return (max);
}
