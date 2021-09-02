#include "../includes/push_swap.h"

void	ft_fill_b(t_stack **stack_b)
{
	int		i;
	int		j;
	t_stack	*tmp_b;

	tmp_b = *stack_b;
	i = 0;
	j = ft_lstsize_p(*stack_b);
	while (tmp_b)
	{
		if (j == 1)
		{
			tmp_b->rb = 0;
			tmp_b->rrb = 0;
		}
		else
		{
			tmp_b->rb = i;
			tmp_b->rrb = j - i;
			i++;
		}
		tmp_b = tmp_b->next;
	}
}

int	ft_count_i(t_stack *tmp_a, int i)
{
	while (tmp_a->index != 0)
	{
		i++;
		tmp_a = tmp_a->next;
	}
	return (i);
}

int	ft_count_i_2(t_stack *tmp_a, t_stack *tmp_b, int i)
{
	while (tmp_a)
	{
		if (ft_find_max_indx(tmp_a) < tmp_b->index)
		{
			i += ft_count_i(tmp_a, i);
			break ;
		}
		else
		{
			if ((i == 0) && ((tmp_b->index < tmp_a->index)
					 && (tmp_b->index > ft_lstlast_p(tmp_a)->index)))
				break ;
			else if (tmp_a->next && ((tmp_b->index > tmp_a->index)
					 && (tmp_b->index < tmp_a->next->index)))
			{
				i++;
				break ;
			}
			else
				i++;
			tmp_a = tmp_a->next;
		}
	}
	return (i);
}

int	ft_fill_a(t_stack *tmp_a, t_stack *tmp_b, int i, int j)
{
	if (j == 1)
		return (0);
	else
		i += ft_count_i_2(tmp_a, tmp_b, i);
	return (i);
}

void	ft_fill(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp_b;
	int		i;
	int		j;

	ft_fill_b(stack_b);
	i = 0;
	j = ft_lstsize_p(*stack_a);
	tmp_b = *stack_b;
	while (tmp_b)
	{
		i += ft_fill_a(*stack_a, tmp_b, i, j);
		if (i == j || i == 0)
		{
			tmp_b->rra = 0;
			tmp_b->ra = 0;
		}
		else
		{
			tmp_b->rra = j - i;
			tmp_b->ra = i;
		}
		i = 0;
		tmp_b = tmp_b->next;
	}
}
