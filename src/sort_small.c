#include "../includes/push_swap.h"

void	ft_sort_two(t_stack **stack_a)
{
	if ((*stack_a)->value > (*stack_a)->next->value)
		ft_swap(stack_a);
}

void	ft_sort_three(t_stack **stack_a)
{
	if ((*stack_a)->value < (*stack_a)->next->value \
		&& (*stack_a)->next->value > (*stack_a)->next->next->value \
		&& (*stack_a)->value < (*stack_a)->next->next->value)
	{
		ft_swap(stack_a);
		ft_rotate(stack_a, 1);
	}
	else if ((*stack_a)->value > (*stack_a)->next->value \
		&& (*stack_a)->value < (*stack_a)->next->next->value)
		ft_swap(stack_a);
	else if ((*stack_a)->value < (*stack_a)->next->value \
		&& (*stack_a)->value > (*stack_a)->next->next->value)
		ft_rrotate(stack_a, 1);
	else if ((*stack_a)->value > (*stack_a)->next->value \
		&& (*stack_a)->next->value < (*stack_a)->next->next->value)
		ft_rotate(stack_a, 1);
	else if ((*stack_a)->value > (*stack_a)->next->value \
		&& (*stack_a)->next->value > (*stack_a)->next->next->value)
	{
		ft_swap(stack_a);
		ft_rrotate(stack_a, 1);
	}
}
