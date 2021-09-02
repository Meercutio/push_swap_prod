#include "../includes/push_swap.h"

int	ft_abs(int num)
{
	if (num < 0)
		num *= -1;
	return (num);
}

int	ft_minimum(int a, int b)
{
	if (a < b)
		return (a);
	else
		return (b);
}

void	ft_find_min(t_stack **stack_b)
{
	int	i;
	int	sum[4];

	sum[0] = ft_abs((*stack_b)->ra - (*stack_b)->rb)
		+ ft_minimum((*stack_b)->ra, (*stack_b)->rb);
	sum[1] = (*stack_b)->ra + (*stack_b)->rrb;
	sum[2] = (*stack_b)->rra + (*stack_b)->rb;
	sum[3] = ft_abs((*stack_b)->rra - (*stack_b)->rrb)
		+ ft_minimum((*stack_b)->rra, (*stack_b)->rrb);
	i = 1;
	(*stack_b)->min = sum[0];
	(*stack_b)->flag = 0;
	while (i < 4)
	{
		if ((*stack_b)->min > sum[i])
		{
			(*stack_b)->min = sum[i];
			(*stack_b)->flag = i;
		}
		i++;
	}
}
