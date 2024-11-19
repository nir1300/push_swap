#include "push_swap.h"
#include "libft/libft.h"


void ft_sa(n_list **lst)
{
    if (!lst || (*lst) == NULL || (*lst)->next == NULL)
	{
    	return ;
	}
	n_list *head = *lst;
	n_list *second = (*lst)->next;
	n_list *third = second->next;
	second->prev = NULL;
	second->next = head;
	head->prev = second;
	head->next = third;
	if ((*lst)->next && (*lst)->next->next)
		third->prev = head;
	*lst = second;
}

void ft_sb(n_list **lst)
{
	ft_sa(lst);
}

void ft_ss(n_list **a, n_list **b)
{
    if ((*a) == NULL || (*a)->next == NULL || (*b) == NULL || (*b)->next == NULL)
        return ;
    ft_sa(a);
    ft_sb(b);
}

void ft_pa(n_list **a, n_list **b)
{
    if (*b == NULL)
        return ;
	
    n_list *first = *b;
	lstadd_front(a, first);
	if ((*b)->next)
	{
		(*b) = (*b)->next;
		(*b)->prev = NULL;
	}
	else
		*b = NULL;
}
void ft_pb(n_list **a, n_list **b)
{
    if ((*a) == NULL)
        return ;
    n_list *first = *a;
	n_list *second;
	second = (*a)->next;
	second->prev = NULL;
	(*a) = second;
	lstadd_front(b, first);

}

/* void ft_ra(n_list **a)
{
	if ((*a) == NULL || (*a)->next == NULL)
		return ;
	n_list *last = *a;
	n_list *first = *a;
	while (last->next != NULL)
		last = last->next;
	n_list *temp = last->prev;
	last->next = first->next;
	last->prev = NULL;
	first->next = NULL;
	first->prev = temp;
	temp->next = first;
	(*a) = last;
} */

void ft_rra(n_list **a)
{
	n_list *first = *a;
	n_list *last = *a;
	n_list *second_last = NULL;
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

void ft_ra(n_list **a)
{
	if ((*a) == NULL || (*a)->next == NULL)
		return ;
	n_list *last = *a;
	n_list *first = *a;
	while (last->next != NULL)
		last = last->next;
	n_list *temp = first->next;
	temp->prev = NULL;
	temp->next = first->next->next;
	first->next = NULL;
	first->prev = last;
	last->next = first;

	(*a) = temp;
}

void ft_rb(n_list **b)
{
	if ((*b) == NULL || (*b)->next == NULL)
		return ;
	ft_ra(b);
}

void ft_rr(n_list **a, n_list **b)
{
	if ((*a) == NULL || (*a)->next == NULL || (*b) == NULL || (*b)->next == NULL)
		return ;
	ft_ra(a);
	ft_rb(b);
}

void ft_rra(n_list **a)
{
	n_list *first = *a;
	n_list *last = *a;
	n_list *second_last = NULL;
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

void ft_rrb(n_list **b)
{
	ft_rra(b);
}

void ft_rrr(n_list **a, n_list **b)
{
	if ((*a) == NULL || (*a)->next == NULL || (*b) == NULL || (*b)->next == NULL)
		return ;
	ft_rra(a);
	ft_rrb(b);
}