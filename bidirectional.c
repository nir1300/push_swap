#include "push_swap.h"

n_list	*lstnew(int content)
{
	n_list	*first;

	first = (n_list *)malloc(sizeof(n_list));
	if (first == NULL)
		return (NULL);
	first->content = content;
	first->next = NULL;
    first->prev = NULL;
	return (first);
}

void	lstadd_front(n_list **lst, n_list *new)
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
void	lstadd_back(n_list **lst, n_list *new)
{
	n_list	*current;

	if (*lst != NULL)
	{
		current = lstlast(*lst);
		current->next = new;
		new->prev = current;
	}
	else
		*lst = new;
}

n_list	*lstlast(n_list *lst)
{
	if (lst != NULL)
	{
		while (lst->next != NULL)
			lst = lst->next;
		return (lst);
	}
	return (NULL);
}

int	lstsize(n_list *lst)
{
	int	i;

	i = 0;
	while (lst != NULL)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}