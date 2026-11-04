/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bidirectional.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrumpfhu <nrumpfhu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 22:18:09 by nrumpfhu          #+#    #+#             */
/*   Updated: 2024/12/05 18:23:20 by nrumpfhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_lst	*lstnew(int content)
{
	t_lst	*first;

	first = (t_lst *)malloc(sizeof(t_lst));
	if (first == NULL)
		return (NULL);
	first->content = content;
	first->next = NULL;
	first->prev = NULL;
	return (first);
}

void	lstadd_front(t_lst **lst, t_lst *new)
{
	if (!*lst)
	{
		new->next = NULL;
		new->prev = NULL;
		*lst = new;
		return ;
	}
	new->next = *lst;
	new->prev = NULL;
	(*lst)->prev = new;
	*lst = new;
}

t_lst	*lstlast(t_lst *lst)
{
	if (lst != NULL)
	{
		while (lst->next != NULL)
			lst = lst->next;
		return (lst);
	}
	return (NULL);
}

void	lstadd_back(t_lst **lst, t_lst *new)
{
	t_lst	*current;

	if (*lst != NULL)
	{
		current = lstlast(*lst);
		current->next = new;
		new->prev = current;
	}
	else
		*lst = new;
}

void	free_list(t_lst **lst)
{
	t_lst	*temp;
	t_lst	*head;

	if (!lst)
		return ;
	head = *lst;
	while (head)
	{
		temp = head;
		head = head->next;
		free(temp);
	}
}
