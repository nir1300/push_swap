#include "push_swap.h"
#include "libft/libft.h"

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
    ft_printf("Init a: ");
	print_list(list_a);
    ft_printf("Init b: ");
	print_list(list_b);
    ft_sa(&list_a);
    ft_printf("sa: ");
    print_list(list_a);
    ft_pb(&list_a, &list_b);
    ft_pb(&list_a, &list_b);
    ft_pb(&list_a, &list_b);
    ft_printf("pb pb pb a: ");
    print_list(list_a);
    ft_printf("b: ");
    print_list(list_b);
    ft_rr(&list_a, &list_b);
    ft_printf("rr a: ");
    print_list(list_a);
    printf("b: ");
    print_list(list_b);
    ft_rrr(&list_a, &list_b);
    ft_printf("rrr a: ");
    print_list(list_a);
    ft_printf("b: ");
    print_list(list_b);
    ft_sa(&list_a);
    ft_printf("sa a: ");
    print_list(list_a);
    ft_printf("b: ");
    print_list(list_b);
    // pa is the root of the issue
    // ft_pa(&list_a, &list_b);
    // ft_pa(&list_a, &list_b);
    // ft_pa(&list_a, &list_b);
    // ft_printf("pa pa pa a: ");
    // print_list(list_a);
    // ft_printf("b: ");
    // print_list(list_b);


	// if (len <= 3)
	// 	list_a = up_to_3(list_a, list_b);
	// if (len > 3 && len <= 5)
	// 	list_a = up_to_5(list_a, list_b);
 	// print_list(list_a);
	if (sorted(list_a, list_b))
		printf("sorted\n");
	else
		ft_printf("not sorted\n");
}
