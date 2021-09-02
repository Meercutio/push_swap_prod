#include "../includes/push_swap.h"

t_stack	*ft_lstlast_p(t_stack *lst)
{
	if (lst)
	{
		while (lst->next)
			lst = lst->next;
	}
	return (lst);
}

t_stack	*ft_lstnew_p(int value, int order)
{
	t_stack	*new_elem;

	new_elem = (t_stack *)malloc(sizeof(t_stack));
	if (!new_elem)
		return (NULL);
	new_elem->value = value;
	new_elem->index = order;
	new_elem->ra = 0;
	new_elem->rra = 0;
	new_elem->rb = 0;
	new_elem->rrb = 0;
	new_elem->min = 0;
	new_elem->flag = 0;
	new_elem->next = NULL;
	return (new_elem);
}

void	ft_lstadd_front_p(t_stack **lst, t_stack *new)
{
	new->next = *lst;
	*lst = new;
}

void	ft_lstadd_back_p(t_stack **lst, t_stack *new)
{
	t_stack	*tmp;

	if (lst)
	{
		if (*lst == NULL)
			*lst = new;
		else
		{
			tmp = ft_lstlast_p(*lst);
			tmp->next = new;
		}
	}
}

void	ft_push(t_stack **stack_a, t_stack **stack_b, int st)
{
	t_stack	*tmp;
	t_stack	*del;

	tmp = ft_lstnew_p((*stack_a)->value, (*stack_a)->index);
	ft_lstadd_front_p(stack_b, tmp);
	del = (*stack_a);
	if ((*stack_a)->next)
	{
		*stack_a = (*stack_a)->next;
	}
	else
		*stack_a = NULL;
	free(del);
	if (st == 1)
		write(1, "pa\n", 3);
	if (st == 2)
		write(1, "pb\n", 3);
}
