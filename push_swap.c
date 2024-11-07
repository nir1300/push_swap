#include "push_swap.h"

// sort 100 numbers in less than 700 operations
// sort 500 numbers in less than 5500 operations

//find max and sort everything into b
// doubly linked list (new struct with prev)
// circular list

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

// void up_to_3(t_list **a, t_list **b)
// {
// 	ft_pb(a);
// 	if (*(int *)(*a)->content > *(int *)(*a)->next->content)

// }

void create_list(t_list *list_a, int argc, char *argv[])
{
	int i = 1;
	list_a = ft_lstnew(argv[i]);
	while (i++ < argc)
		ft_lstadd_back(&list_a, ft_lstnew(argv[i]));
}

int main(int argc, char *argv[])
{
	int i = 1;
	int n = 0;
	t_list	*list_a = NULL;
	int *value;
	if (argc < 2)
		return (printf("Error, no input"), -1);
	while (i < argc)
	{
		while (argv[i][n])
		{
			if (!ft_isdigit(argv[i][n]))
			{
				printf("Error, no number");
				return (-1);
			}
			n++;
		}
		value = malloc(sizeof(int));
		if (!value)
			return (printf("memory allocation error"), -1);
		*value = atoi(argv[i]);
		ft_lstadd_back(&list_a, ft_lstnew(value));
		i++;
		n = 0;
	}
	print_list(list_a);
}
