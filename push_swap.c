#include "push_swap.h"

// sort 100 numbers in less than 700 operations
// sort 500 numbers in less than 5500 operations

//find max and sort everything into b

int find_max(t_list **a)
{
	int max = *(int *)(*a)->content;
	t_list *current = *a;
	while (current->next != NULL)
	{
		current = current->next;
		if (*(int *)current->content > max)
			max = *(int *)current->content;
	}
	return (max);
}

 int find_median(t_list **a)
{
	int len = ft_lstsize(*a);
	int median;
	int i = 0;
	t_list *current = *a;
	while (i < len / 2)
	{
		current = current->next;
		i++;
	}
	median = *(int *)current->content;
	return (median);
}

void sort_b(t_list **b)
{
	while ((*b) && (*b)->next && *(int *)(*b)->content > *(int *)(*b)->next->content)
		ft_rrb;
}

void pop(t_list **a, t_list **b)
{
	
	t_list *current = *a;
	t_list *current_b = *b;
	int len = ft_lstsize(*a);
	int i = 0;
	int median = find_median(a);
	while (i < len)
	{
		if (*a == NULL)
			break;
		if (*(int *)(*a)->content < median)
		{
			ft_pb(a, b);
			if ((*b) && (*b)->next && *(int *)(*b)->content < *(int *)(*b)->next->content)
			{
				ft_sb(b);
			}

		}
		else
			ft_ra(a);
		i++;
	}
}



int	main(void)
{
	t_list	*list = NULL;
    t_list *list_b = NULL;

	int	num1 = 6;
	int	num2 = 5;
	int	num3 = 8;
	int	num4 = 3;
	int	num5 = 14;

	ft_lstadd_back(&list, ft_lstnew(&num1));
	ft_lstadd_back(&list, ft_lstnew(&num2));
	ft_lstadd_back(&list, ft_lstnew(&num3));
	ft_lstadd_back(&list, ft_lstnew(&num4));
	ft_lstadd_back(&list, ft_lstnew(&num5));

	print_list(list);
	pop(&list, &list_b);
	print_list(list);
	print_list(list_b);
    // ft_sa(&list);
    // print_list(list);
    // ft_pb(&list, &list_b);
    // print_list(list_b);
	// print_list(list);
	// ft_pa(&list, &list_b);
    // print_list(list_b);
	// print_list(list);
	// // ft_ra(&list);
	// // print_list(list);
	// // ft_rra(&list);
	// // print_list(list);
	// // Freeing the list
	// t_list *temp;
	// while (list)
	// {
	// 	temp = list;
	// 	list = list->next;
	// 	free(temp);
	// }
	// return 0;
}