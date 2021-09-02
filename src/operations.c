#include "../includes/push_swap.h"

void	ft_swap(t_stack **lst)
{
	t_stack	*swap;
	t_stack	*del;

	if (ft_lstsize_p(*lst) < 2)
		exit(1);
	del = (*lst)->next;
	(*lst)->next = del->next;
	swap = ft_lstnew_p(del->value, del->index);
	if (!swap)
		ft_error();
	ft_lstadd_front_p(lst, swap);
	ft_lstdel(&del);
	write(1, "sa\n", 3);
}

void	ft_rotate(t_stack **lst, int st)
{
	t_stack	*tmp;
	t_stack	*del;

	tmp = ft_lstnew_p((*lst)->value, (*lst)->index);
	ft_lstadd_back_p(lst, tmp);
	del = (*lst);
	(*lst) = (*lst)->next;
	ft_lstdel(&del);
	if (st == 1)
		write(1, "ra\n", 3);
	if (st == 2)
		write(1, "rb\n", 3);
}

void	ft_rrotate(t_stack **lst, int st)
{
	t_stack	*tmp;
	t_stack	*del;

	del = ft_lstlast_p(*lst);
	tmp = ft_lstnew_p(del->value, del->index);
	ft_lstadd_front_p(lst, tmp);
	tmp = *lst;
	while (tmp->next != del)
		tmp = tmp->next;
	tmp->next = NULL;
	ft_lstdel(&del);
	if (st == 1)
		write(1, "rra\n", 4);
	if (st == 2)
		write(1, "rrb\n", 4);
}

void	ft_rr(t_stack **stack_a, t_stack **stack_b)
{
	ft_rotate(stack_a, 0);
	ft_rotate(stack_b, 0);
	write(1, "rr\n", 3);
}

void	ft_rrr(t_stack **stack_a, t_stack **stack_b)
{
	ft_rrotate(stack_a, 0);
	ft_rrotate(stack_b, 0);
	write(1, "rrr\n", 4);
}
