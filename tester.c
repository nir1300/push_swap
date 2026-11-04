/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrumpfhu <nrumpfhu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 22:19:58 by nrumpfhu          #+#    #+#             */
/*   Updated: 2025/01/15 03:55:54 by nrumpfhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"

void	free_array(char **arr)
{
	int	i;

	i = 0;
	if (!arr)
		return ;
	while (arr[i])
		i++;
	while (i >= 0)
	{
		free(arr[i]);
		i--;
	}
	free(arr);
}

t_lst	*create_list(int argc, char **args, t_lst *a)
{
	int		i;
	t_lst	*value;

	i = 0;
	while (args[i])
	{
		value = lstnew(ft_atoi(args[i]));
		if (!value)
		{
			free_list(&a);
			exit(1);
		}
		lstadd_back(&a, value);
		i++;
	}
	if (argc == 2 && lstsize(a) != 1)
		free_array(args);
	if (sorted(a))
	{
		free_list(&a);
		exit(0);
	}
	return (a);
}

int	lstsize(t_lst *lst)
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
