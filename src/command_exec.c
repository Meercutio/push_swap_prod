#include "../includes/push_swap.h"

void	ft_path_0(t_stack **stack_a, t_stack **stack_b, t_stack *ptr)
{
	while (ptr->ra && ptr->rb)
	{
		ft_rr(stack_a, stack_b);
		ptr->ra--;
		ptr->rb--;
	}
	while (ptr->ra)
	{
		ft_rotate(stack_a, 1);
		ptr->ra--;
	}
	while (ptr->rb)
	{
		ft_rotate(stack_b, 2);
		ptr->rb--;
	}
}

void	ft_path_1(t_stack **stack_a, t_stack **stack_b, t_stack *ptr)
{
	while (ptr->ra)
	{
		ft_rotate(stack_a, 1);
		ptr->ra--;
	}
	while (ptr->rrb)
	{
		ft_rrotate(stack_b, 2);
		ptr->rrb--;
	}
}

void	ft_path_2(t_stack **stack_a, t_stack **stack_b, t_stack *ptr)
{
	while (ptr->rra)
	{
		ft_rrotate(stack_a, 1);
		ptr->rra--;
	}
	while (ptr->rb)
	{
		ft_rotate(stack_b, 2);
		ptr->rb--;
	}
}

void	ft_path_3(t_stack **stack_a, t_stack **stack_b, t_stack *ptr)
{
	while (ptr->rra && ptr->rrb)
	{
		ft_rrr(stack_a, stack_b);
		ptr->rra--;
		ptr->rrb--;
	}
	while (ptr->rra)
	{
		ft_rrotate(stack_a, 1);
		ptr->rra--;
	}
	while (ptr->rrb)
	{
		ft_rrotate(stack_b, 2);
		ptr->rrb--;
	}
}

void	ft_path_def(t_stack **stack_a, t_stack **stack_b)
{
	int		i;
	t_stack	*ptr;
	t_stack	*tmp;

	tmp = *stack_b;
	ptr = tmp;
	i = tmp->min;
	while (tmp)
	{
		if (i > tmp->min)
		{
			i = tmp->min;
			ptr = tmp;
		}
		tmp = tmp->next;
	}
	if (ptr->flag == 0)
		ft_path_0(stack_a, stack_b, ptr);
	else if (ptr->flag == 1)
		ft_path_1(stack_a, stack_b, ptr);
	else if (ptr->flag == 2)
		ft_path_2(stack_a, stack_b, ptr);
	else if (ptr->flag == 3)
		ft_path_3(stack_a, stack_b, ptr);
	ft_push(stack_b, stack_a, 1);
}
