/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_500.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrumpfhu <nrumpfhu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 17:04:01 by nrumpfhu          #+#    #+#             */
/*   Updated: 2025/01/15 03:57:40 by nrumpfhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"

void	least_moves(t_lst **a, t_lst *b)
{
	t_lst	*front;
	int		len;
	int		fr;

	front = *a;
	len = lstsize(*a);
	fr = 0;
	while (front->next && ((front->content > b->content
				|| front->next->content < b->content)))
	{
		front = front->next;
		fr++;
	}
	if (fr < len / 2)
		ft_ra(a, 'a');
	else
		ft_rra(a, 'a');
}

t_lst	*pushback(t_lst *a, t_lst *b)
{
	while (b)
	{
		if (b && (b->content < find_min(a) || b->content > find_max(a)))
		{
			if (a->content != find_min(a))
				cheapest(&a);
			ft_pa(&a, &b);
		}
		else if (b && b->content < a->content
			&& b->content > lstlast(a)->content)
			ft_pa(&a, &b);
		else if (b)
			least_moves(&a, b);
	}
	cheapest(&a);
	return (a);
}

void	split_chunks(t_lst **a, t_lst **b, int i)
{
	int	last;

	last = lstlast(*a)->content;
	while ((*a) && (*a)->content != last)
	{
		if ((*a)->chunk_nb == i || i == 0)
			ft_pb(a, b);
		else
			ft_ra(a, 'a');
	}
}

void	positions(t_lst *b, int chunk_len)
{
	t_lst	*temp;
	int		pos;
	t_lst	*start;

	start = b;
	while (b)
	{
		temp = start;
		pos = 1;
		while (temp)
		{
			if (temp->content < b->content)
				pos++;
			temp = temp->next;
		}
		b->pos = pos;
		b->chunk_nb = pos / chunk_len;
		b = b->next;
	}
}

t_lst	*up_to_500(t_lst *a, t_lst *b)
{
	int	i;
	int	len;
	int	chunks;
	int	chunk_len;

	len = lstsize(a);
	if (len <= 50)
		chunk_len = 3;
	else if (len < 200)
		chunk_len = 18;
	else
		chunk_len = 40;
	chunks = len / chunk_len;
	positions(a, chunk_len);
	i = chunks;
	while (i >= 0)
	{
		split_chunks(&a, &b, i);
		i--;
	}
	a = pushback(a, b);
	return (a);
}
