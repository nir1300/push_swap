#include "push_swap.h"

void	print_list(n_list *lst)
{
	while (lst != NULL)
	{
		ft_printf("%d -> ", lst->content);
		lst = lst->next;
	}
	ft_printf("NULL\n");
}
