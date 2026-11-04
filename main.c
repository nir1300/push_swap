/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrumpfhu <nrumpfhu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 17:01:46 by nrumpfhu          #+#    #+#             */
/*   Updated: 2024/12/05 22:10:07 by nrumpfhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"

char	print_error(int argc, char **args)
{
	ft_putendl_fd("Error", 2);
	if (argc == 2)
		free_array(args);
	exit(1);
}

int	duplicate_check(char **args)
{
	int	i;
	int	n;
	int	current;

	i = 0;
	while (args[i])
	{
		current = ft_atoi(args[i]);
		n = i + 1;
		while (args[n])
		{
			if (ft_atoi(args[n]) == current)
				return (1);
			n++;
		}
		i++;
	}
	return (0);
}

int	error_handling(char **args)
{
	int	i;
	int	n;

	i = 0;
	while (args[i])
	{
		n = 0;
		if ((args[i][n] == '+' || args[i][n] == '-'))
		{
			if (!ft_isdigit(args[i][n + 1]))
				return (1);
			n++;
		}
		if (ft_atoi(args[i]) != ft_atol(args[i]) || args[0] == NULL)
			return (1);
		while (args[i][n])
		{
			if (!ft_isdigit(args[i][n]))
				return (1);
			n++;
		}
		i++;
	}
	return (0);
}

t_lst	*error_mgm(int argc, char *argv[], t_lst *a)
{
	char	**args;
	int		argc_true;

	argc_true = 0;
	args = NULL;
	if (argc == 1)
		exit(0);
	if (argc == 2 && ft_strchr(argv[1], ' ') != NULL)
	{
		args = ft_split(argv[1], ' ');
		argc_true = 2;
		if (!args)
			print_error(argc, args);
	}
	else if (argc > 2 || (argc == 2 && ft_strchr(argv[1], ' ') == NULL))
		args = argv + 1;
	else
		print_error(-1, args);
	if (error_handling(args) == 1 || duplicate_check(args) == 1)
		print_error(argc_true, args);
	return (create_list(argc, args, a));
}

int	main(int argc, char *argv[])
{
	t_lst	*a;
	t_lst	*b;
	int		len;

	a = NULL;
	b = NULL;
	a = error_mgm(argc, argv, a);
	len = lstsize(a);
	if (len <= 3)
		a = up_to_3(a);
	else if (len > 3 && len <= 5)
		a = up_to_5(a, b);
	else
		a = up_to_500(a, b);
	free_list(&a);
	free_list(&b);
}
