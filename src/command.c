#include "../includes/push_swap.h"

int	ft_error(void)
{
	write(1, "Error\n", 6);
	exit(1);
}

void	ft_lstdel(t_stack **lst)
{
	(*lst)->next = NULL;
	*lst = NULL;
	free(*lst);
}

int	ft_lstsize_p(t_stack *lst)
{
	t_stack	*tmp;
	int		count;

	count = 0;
	tmp = lst;
	while (tmp)
	{
		count++;
		tmp = tmp->next;
	}
	return (count);
}

void	ft_bubbleSort(int *sort, int argc)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	while (i < argc - 1)
	{
		j = argc - 1;
		while (j > i)
		{
			if (sort[j - 1] > sort[j])
			{
				tmp = sort[j - 1];
				sort[j - 1] = sort[j];
				sort[j] = tmp;
			}
			j--;
		}
		i++;
	}
}
