#include "push_swap.h"

void ft_sa(t_list **lst)
{
    if (*lst == NULL || (*lst)->next == NULL)
        return ;
    t_list *first = *lst;
    t_list *second = first->next;
    first->next = second->next;
    second->next = first;
    *lst = second;
}

void ft_sb(t_list **lst)
{
	ft_sa(lst);
}

void ft_ss(t_list **a, t_list **b)
{
    if (*a == NULL || (*a)->next == NULL || *b == NULL || (*b)->next == NULL)
        return ;
    ft_sa(a);
    ft_sb(b);
}

void ft_pa(t_list **a, t_list **b)
{
    if (*b == NULL)
        return ;
    t_list *first = *b;
	if ((*b)->next == NULL)
		(*b)->next = NULL;
    t_list *second = (*b)->next;
    *b = second;
    ft_lstadd_front(a, first);
}

void ft_pb(t_list **a, t_list **b)
{
   ft_pa(b, a);
}

void ft_ra(t_list **a)
{
	if ((*a) == NULL || (*a)->next == NULL)
		return ;
	t_list *last = *a;
	t_list *first = *a;
	while (last->next != NULL)
		last = last->next;
	*a = first->next;
	last->next = first;
	first->next = NULL;
}

void ft_rb(t_list **b)
{
	if ((*b) == NULL || (*b)->next == NULL)
		return ;
	t_list *first = *b;
	t_list *last = *b;
	while (last->next != NULL)
		last = last->next;
	*b = first->next;
	last->next = first;
	first->next = NULL;
}

void ft_rr(t_list **a, t_list **b)
{
	if ((*a) == NULL || (*a)->next == NULL || (*b) == NULL || (*b)->next == NULL)
		return ;
	ft_ra(a);
	ft_rb(b);
}

void ft_rra(t_list **a)
{
	t_list *last = *a;
	t_list *second_last = NULL;
	if ((*a) == NULL || (*a)->next == NULL)
		return ;
	while (last->next != NULL)
	{
		second_last = last;
		last = last->next;
	}
	if (second_last != NULL)
	{
		second_last->next = NULL;
		last->next = *a;
		*a = last;
	}
}

void ft_rrb(t_list **b)
{
	ft_rra(b);
}

void ft_rrr(t_list **a, t_list **b)
{
	if ((*a) == NULL || (*a)->next == NULL || (*b) == NULL || (*b)->next == NULL)
		return ;
	ft_rra(a);
	ft_rrb(b);
}