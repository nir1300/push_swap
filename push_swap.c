#include "push_swap.h"
#include "./libft/libft.h"
#include "./libft/printf/ft_printf.h"
// sort 100 numbers in less than 700 operations
// sort 500 numbers in less than 5500 operations

//find max and sort everything into b
// doubly linked list (new struct with prev)
// circular list

// to-do: error check for doubles, and values exceedint int min/max

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
				ft_sb(b);
		}
		else
			ft_ra(a);
		i++;
	}
}

// void sort_substack(t_list **a, t_list **b)
// {
// 	t_list *first = *a;
// 	t_list *last = ft_lstlast(&a);

// }

int sorted(t_list **a, t_list **b)
{
	t_list *temp = *a;
	if ((*b))
		return (0);
	while (temp && temp->next)
	{
		if (*(int *)temp->content > *(int *)temp->next->content)
			return (0);
		temp = temp->next;
	}
	return (1);
}

void up_to_3(t_list **a, t_list **b, int len)
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
}

void create_list(t_list *list_a, int argc, char *argv[])
{
	int i = 1;
	list_a = ft_lstnew(argv[i]);
	while (i++ < argc)
		ft_lstadd_back(&list_a, ft_lstnew(argv[i]));
}

// int check_limits(char *argv[])

int main(int argc, char *argv[])
{
	int i = 1;
	int n = 0;
	t_list	*list_a = NULL;
	t_list	*list_b = NULL;
	int *value;
	if (argc < 2)
		return (printf("Error, no input\n"), -1);
	while (i < argc)
	{
		// for checking int min and int max, count length of string
		// if it is longer than 10 (or 11 for neg), it is not an int
		// if it is exactly 10/11, use strcmp (if it returns 1, it is not an int)
		if (argv[i][0] == '-')
			n++;
		while (argv[i][n])
		{
			if (!ft_isdigit(argv[i][n]))
			{
				printf("Error, no number\n");
				return (-1);
			}
			n++;
		}
		value = malloc(sizeof(int));
		if (!value)
			return (printf("memory allocation error\n"), -1);
		*value = atoi(argv[i]);
		ft_lstadd_back(&list_a, ft_lstnew(value));
		i++;
		n = 0;
	}
	int len = ft_lstsize(list_a);

	if (len == 1 || sorted(&list_a, &list_b))
		return (printf("Already sorted\n"), 0);
	print_list(list_a);
	if (len <= 3)
		up_to_3(&list_a, &list_b, len);
	print_list(list_a);
	print_list(list_b);
	if (sorted(&list_a, &list_b))
		printf("sorted\n");
	else
		ft_printf("not sorted\n");
}
