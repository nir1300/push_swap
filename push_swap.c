#include "push_swap.h"
#include "libft/libft.h"

// sort 100 numbers in less than 700 operations
// sort 500 numbers in less than 5500 operations

//find max and sort everything into b
// doubly linked list (new struct with prev)
// circular list

// to-do: error check for doubles, and values exceeding int min/max

int find_max(n_list *a)
{
	int max = a->content;
	n_list *current = a;
	while (current->next != NULL)
	{
		current = current->next;
		if (current->content > max)
			max = current->content;
	}
	return (max);
}

int find_min(n_list *a)
{
	int min = a->content;
	n_list *current = a;
	while (current->next != NULL)
	{
		current = current->next;
		if (current->content < min)
			min = current->content;
	}
	return (min);
}

/* void sort_chunks(n_list *b)
{
	int len = lstsize(b);
	if (b < )
} */

void split_chunks(n_list *a, n_list *b)
{
	int min = find_min(a);
	int max = find_max(b);
	int range = max - min;
	int i = 0;
	n_list *head = a;
	//int len = lstsize(a);
	if (min < 0 && max < 0)
		range = (-1) * min - max;
	while (i < 4)
	{
		a = head;
		while (a)
		{
			if (a->content <= min + (range / 4) + (range/4 * i))
			{
				ft_pb(&a, &b);
				//sort_chunks(b);
				ft_ra(&a);
			}
			a = a->next;
		}
		i++;
	}
}

void algorithm(n_list *a, n_list *b)
{
	int i = 4;
	while (i-- > 0)
		split_chunks(a, b);
}



void sort_b(n_list *b)
{
	while (b && b->next && b->content > b->next->content)
		ft_rrb(&b);
}
/* 
void most_efficient(n_list *b)
{
 	int len = ft_lstsize(*b);
	if (len <= 3)
	{
		up_to_3(b);
		return ;
	}
} */



int sorted(n_list *a, n_list *b)
{
	n_list *temp = a;
	if (b != NULL)
		return (0);
	while (temp && temp->next)
	{
		if (temp->content > temp->next->content)
			return (0);
		temp = temp->next;
	}
	return (1);
}

n_list *up_to_3(n_list *a, n_list *b)
{
	if (a && a->next && a->content > a->next->content)
		ft_sa(&a);
	if (sorted(a, b) == 1)
		return (a);
	ft_rra(&a);
	if (a && a->next && a->content > a->next->content)
		ft_sa(&a);
	printf("hello");
	return (a);
}
n_list *up_to_5(n_list *a, n_list *b)
{
	ft_pb(&a, &b);
	if (lstsize(a) == 4)
	{
		ft_pb(&a, &b);
		if (b->content > b->next->content)
			ft_sb(&b);
	}
	a = up_to_3(a, b);
	while (b != NULL)
	{
		while (a->content < b->content)
			ft_ra(&a);
		ft_pa(&a, &b);
	}
	return (a);
}

void create_list(n_list *list_a, int argc, char *argv[])
{
	int i = 1;
	list_a = lstnew(ft_atoi(argv[i]));
	while (i++ < argc)
		lstadd_back(&list_a, lstnew(ft_atoi(argv[i])));
}

// int check_limits(char *argv[])

int main(int argc, char *argv[])
{
	int i = 1;
	int n = 0;
	n_list	*list_a = NULL;
	n_list	*list_b = NULL;
	int *value;
	if (argc < 2)
		return (printf("Error, no input\n"), -1);
	while (i < argc)
	{
		// for checking int min and int max, use atoi and atol and compare if output is the same
		// check for duplicates not sure how yet
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
		lstadd_back(&list_a, lstnew(*value));
		i++;
		n = 0;
	}
	int len = lstsize(list_a);
	if (len == 1 || sorted(list_a, list_b))
		return (printf("Already sorted\n"), 0);
	/* print_list(list_a); */
	if (len <= 3)
		list_a = up_to_3(list_a, list_b);
	if (len > 3 && len <= 5)
		list_a = up_to_5(list_a, list_b);
 	print_list(list_a);
	if (sorted(list_a, list_b))
		printf("sorted\n");
	else
		ft_printf("not sorted\n");
}
