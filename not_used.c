/* int find_median(t_list **a)
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
} */

/* void pop(t_list **a, t_list **b)
{
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
				ft_sb(b);
		}
		else
			ft_ra(a);
		i++;
	}
} */



// void sort_substack(t_list **a, t_list **b)
// {
// 	t_list *first = *a;
// 	t_list *last = ft_lstlast(&a);

// }

/* void up_to_3(t_list **a, t_list **b, int len)
{
	int i = 0;
	if (len == 2)
	{
		if (*(int *)(*a)->content > *(int *)(*a)->next->content)
			ft_sa(a);
		return ;
	}		
	while (i < 2)
	{
		if (*(int *)(*a)->content > *(int *)(*a)->next->content)
			ft_ra(a);
		ft_pb(a, b);
		i++;
	}
	if (*(int *)(*b)->content < *(int *)(*b)->next->content)
		ft_sb(b);
	ft_pa(a, b);
	ft_pa(a, b);
} */



// int	main(void)
// {
// 	t_list	*list = NULL;
//     t_list *list_b = NULL;

// 	int	num1 = 6;
// 	int	num2 = 5;
// 	int	num3 = 8;
// 	int	num4 = 3;
// 	int	num5 = 14;

// 	ft_lstadd_back(&list, ft_lstnew(&num1));
// 	ft_lstadd_back(&list, ft_lstnew(&num2));
// 	ft_lstadd_back(&list, ft_lstnew(&num3));
// 	ft_lstadd_back(&list, ft_lstnew(&num4));
// 	ft_lstadd_back(&list, ft_lstnew(&num5));

// 	print_list(list);
// 	pop(&list, &list_b);
// 	print_list(list);
// 	print_list(list_b);
//     // ft_sa(&list);
//     // print_list(list);
//     // ft_pb(&list, &list_b);
//     // print_list(list_b);
// 	// print_list(list);
// 	// ft_pa(&list, &list_b);
//     // print_list(list_b);
// 	// print_list(list);
// 	// // ft_ra(&list);
// 	// // print_list(list);
// 	// // ft_rra(&list);
// 	// // print_list(list);
// 	// // Freeing the list
// 	// t_list *temp;
// 	// while (list)
// 	// {
// 	// 	temp = list;
// 	// 	list = list->next;
// 	// 	free(temp);
// 	// }
// 	// return 0;
// }