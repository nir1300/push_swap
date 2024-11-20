#include "libft/libft.h"
#include "push_swap.h"

void	ft_swap(n_list **lst, char c)
{
	n_list	*head;
	n_list	*second;
	n_list	*third;
	if (!lst || (*lst) == NULL || (*lst)->next == NULL)
		return ;
	head = *lst;
	second = (*lst)->next;
	third = second->next;
	second->prev = NULL;
	second->next = head;
	head->prev = second;
	head->next = third;
	if ((*lst)->next && (*lst)->next->next)
		third->prev = head;
	*lst = second;
	if (c == 'a')
		ft_printf("sa\n");
	else if (c == 'b')
		ft_printf("sb\n");
}

void	ft_ss(n_list **a, n_list **b)
{
	if ((*a) == NULL || (*a)->next == NULL || (*b) == NULL
		|| (*b)->next == NULL)
		return ;
	ft_swap(a, 'c');
	ft_swap(b, 'c');
	ft_printf("ss\n");
}

void	ft_pa(n_list **a, n_list **b)
{
	n_list	*first;

	if ((*b) == NULL)
		return ;
	first = *b;
	if ((*b) && (*b)->next)
	{
		(*b) = (*b)->next;
		(*b)->prev = NULL;
	}
	else
		(*b) = NULL;
	lstadd_front(a, first);
	ft_printf("pa\n");
}

void	ft_pb(n_list **a, n_list **b)
{
	n_list	*first;
	n_list	*second;

	if ((*a) == NULL)
		return ;
	first = *a;
	second = (*a)->next;
	second->prev = NULL;
	(*a) = second;
	lstadd_front(b, first);
	ft_printf("pb\n");
}

void	ft_rra(n_list **a)
{
	n_list	*first;
	n_list	*last;
	n_list	*second_last;

	first = *a;
	last = *a;
	second_last = NULL;
	if ((*a) == NULL || (*a)->next == NULL)
		return ;
	while (last->next != NULL)
	{
		second_last = last;
		last = last->next;
	}
	second_last->next = NULL;
	last->prev = NULL;
	last->next = first;
	first->prev = last;
	(*a) = last;
}

void	ft_ra(n_list **a)
{
	n_list	*last;
	n_list	*first;
	n_list	*temp;

	if ((*a) == NULL || (*a)->next == NULL)
		return ;
	last = *a;
	first = *a;
	while (last->next != NULL)
		last = last->next;
	temp = first->next;
	temp->prev = NULL;
	temp->next = first->next->next;
	first->next = NULL;
	first->prev = last;
	last->next = first;
	(*a) = temp;
}

void	ft_rb(n_list **b)
{
	if ((*b) == NULL || (*b)->next == NULL)
		return ;
	ft_ra(b);
}

void	ft_rr(n_list **a, n_list **b)
{
	if ((*a) == NULL || (*a)->next == NULL || (*b) == NULL
		|| (*b)->next == NULL)
		return ;
	ft_ra(a);
	ft_rb(b);
}

void	ft_rrb(n_list **b)
{
	ft_rra(b);
}

void	ft_rrr(n_list **a, n_list **b)
{
	if ((*a) == NULL || (*a)->next == NULL || (*b) == NULL
		|| (*b)->next == NULL)
		return ;
	ft_rra(a);
	ft_rrb(b);
}