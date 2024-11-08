#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include "./libft/libft.h"
# include "./libft/printf/ft_printf.h"

typedef struct s_list
{
	int				*content;
	struct s_list	*next;
}					t_list;

void print_list(t_list *lst);
void ft_sa(t_list **lst);
void ft_sb(t_list **lst);
void ft_ss(t_list **a, t_list **b);
void ft_pa(t_list **a, t_list **b);
void ft_pb(t_list **a, t_list **b);
void ft_ra(t_list **a);
void ft_rb(t_list **b);
void ft_rr(t_list **a, t_list **b);
void ft_rra(t_list **a);
void ft_rrb(t_list **b);
void ft_rrr(t_list **a, t_list **b);

#endif