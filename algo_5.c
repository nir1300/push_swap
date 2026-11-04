/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrumpfhu <nrumpfhu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 22:18:01 by nrumpfhu          #+#    #+#             */
/*   Updated: 2024/12/05 21:44:41 by nrumpfhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"

t_lst	*up_to_3(t_lst *a)
{
	if (a && a->next && a->content > a->next->content)
		ft_swap(&a, 'a');
	if (sorted(a))
		return (a);
	ft_rra(&a, 'a');
	if (a && a->next && a->content > a->next->content)
		ft_swap(&a, 'a');
	return (a);
}

void	cheapest(t_lst **a)
{
	int		len;
	int		i;
	int		min;
	t_lst	*temp;

	min = find_min(*a);
	len = lstsize(*a);
	i = 0;
	temp = *a;
	while (temp && temp->content != min)
	{
		temp = temp->next;
		i++;
	}
	while ((*a) && (*a)->content != min)
	{
		if (i > len / 2)
			ft_rra(a, 'a');
		else
			ft_ra(a, 'a');
	}
}

t_lst	*up_to_5(t_lst *a, t_lst *b)
{
	while (lstsize(a) > 3)
	{
		cheapest(&a);
		ft_pb(&a, &b);
	}
	a = up_to_3(a);
	while (b != NULL)
		ft_pa(&a, &b);
	return (a);
}
