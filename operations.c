/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrumpfhu <nrumpfhu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 22:18:04 by nrumpfhu          #+#    #+#             */
/*   Updated: 2024/12/05 18:23:27 by nrumpfhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"

void	ft_swap(t_lst **lst, char c)
{
	t_lst	*head;
	t_lst	*second;
	t_lst	*third;

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

void	ft_pa(t_lst **a, t_lst **b)
{
	t_lst	*first;

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

void	ft_pb(t_lst **a, t_lst **b)
{
	t_lst	*first;
	t_lst	*second;

	if ((*a) == NULL)
		return ;
	first = *a;
	second = (*a)->next;
	second->prev = NULL;
	(*a) = second;
	lstadd_front(b, first);
	ft_printf("pb\n");
}

void	ft_ra(t_lst **a, char c)
{
	t_lst	*last;
	t_lst	*first;
	t_lst	*temp;

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
	if (c == 'a')
		ft_printf("ra\n");
	else if (c == 'b')
		ft_printf("rb\n");
}

void	ft_rra(t_lst **a, char c)
{
	t_lst	*first;
	t_lst	*last;
	t_lst	*second_last;

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
	if (c == 'a')
		ft_printf("rra\n");
	else if (c == 'b')
		ft_printf("rrb\n");
}
