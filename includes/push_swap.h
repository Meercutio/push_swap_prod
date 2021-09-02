#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdarg.h>
# include <unistd.h>
# include "../libft/includes/libft.h"
# include <limits.h>
# include <stdlib.h>

typedef struct s_stack
{
	int				value;
	int				index;
	int				ra;
	int				rra;
	int				rb;
	int				rrb;
	int				min;
	int				flag;
	struct s_stack	*next;
}				t_stack;

void	ft_parse(int argc, char **argv, t_stack **stack, int is_str_parse);
void	ft_parse_str(char *str, t_stack **lst);
void	ft_rrr(t_stack **stack_a, t_stack **stack_b);
void	ft_rr(t_stack **stack_a, t_stack **stack_b);
void	ft_rrotate(t_stack **lst, int st);
void	ft_rotate(t_stack **lst, int st);
void	ft_swap(t_stack **lst);
void	ft_push(t_stack **stack_a, t_stack **stack_b, int st);
void	ft_lstadd_back_p(t_stack **lst, t_stack *new);
void	ft_lstadd_front_p(t_stack **lst, t_stack *new);
t_stack	*ft_lstnew_p(int value, int order);
t_stack	*ft_lstlast_p(t_stack *lst);
int		ft_lstsize_p(t_stack *lst);
void	ft_lstdel(t_stack **lst);
int		ft_error(void);
void	ft_bubbleSort(int *sort, int argc);
int		ft_is_sort(t_stack *stack);
void	ft_sort_two(t_stack **stack_a);
void	ft_sort_three(t_stack **stack_a);
int		*ft_sort_index(t_stack **stack_a);
void	ft_sort(t_stack **stack_a, t_stack **stack_b);
void	ft_find_min(t_stack **stack_b);
void	ft_path_def(t_stack **stack_a, t_stack **stack_b);
void	ft_fill(t_stack **stack_a, t_stack **stack_b);
int		ft_find_max_indx(t_stack *stack_a);
void	ft_sort_two(t_stack **stack_a);
void	ft_sort_three(t_stack **stack_a);

#endif