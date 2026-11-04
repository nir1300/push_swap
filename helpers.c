/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrumpfhu <nrumpfhu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 22:18:20 by nrumpfhu          #+#    #+#             */
/*   Updated: 2024/12/05 21:53:20 by nrumpfhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"

int	find_max(t_lst *a)
{
	int		max;
	t_lst	*current;

	max = a->content;
	current = a;
	while (current->next != NULL)
	{
		current = current->next;
		if (current->content > max)
			max = current->content;
	}
	return (max);
}

int	find_min(t_lst *a)
{
	int		min;
	t_lst	*current;

	min = a->content;
	current = a;
	while (current->next != NULL)
	{
		current = current->next;
		if (current->content < min)
			min = current->content;
	}
	return (min);
}

int	sorted(t_lst *a)
{
	t_lst	*temp;

	temp = a;
	while (temp && temp->next)
	{
		if (temp->content > temp->next->content)
			return (0);
		temp = temp->next;
	}
	return (1);
}

long int	ft_atol(const char *nptr)
{
	long int	n;
	int			i;
	int			sign;

	i = 0;
	n = 0;
	sign = 1;
	while (nptr[i] == ' ' || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign = -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		n = n * 10 + (nptr[i] - '0');
		i++;
	}
	return (n * sign);
}
