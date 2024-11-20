#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include "libft/libft.h"

typedef struct a_list
{
	int				content;
	struct a_list	*next;
    struct a_list   *prev;
}					n_list;

n_list	*lstnew(int content);
void	lstadd_front(n_list **lst, n_list *new);
void	lstadd_back(n_list **lst, n_list *new);
n_list	*lstlast(n_list *lst);
int	lstsize(n_list *lst);
void print_list(n_list *lst);
void	ft_swap(n_list **lst, char c);
void ft_ss(n_list **a, n_list **b);
void ft_pa(n_list **a, n_list **b);
void ft_pb(n_list **a, n_list **b);
void ft_ra(n_list **a);
void ft_rb(n_list **b);
void ft_rr(n_list **a, n_list **b);
void ft_rra(n_list **a);
void ft_rrb(n_list **b);
void ft_rrr(n_list **a, n_list **b);
int find_max(n_list *a);
int find_median(n_list *a);
void sort_b(n_list *b);
void pop(n_list *a, n_list *b);
int sorted(n_list *a, n_list *b);
n_list *up_to_3(n_list *a);
n_list *up_to_5(n_list *a, n_list *b);
void create_list(n_list *list_a, int argc, char *argv[]);

#endif