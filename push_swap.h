/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrumpfhu <nrumpfhu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 22:27:56 by nrumpfhu          #+#    #+#             */
/*   Updated: 2025/01/15 03:58:07 by nrumpfhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"

typedef struct a_list
{
	int				content;
	int				pos;
	int				chunk_nb;
	struct a_list	*next;
	struct a_list	*prev;
}					t_lst;

void				least_moves(t_lst **a, t_lst *b);
t_lst				*pushback(t_lst *a, t_lst *b);
void				split_chunks(t_lst **a, t_lst **b, int i);
t_lst				*up_to_500(t_lst *a, t_lst *b);
t_lst				*lstnew(int content);
void				lstadd_front(t_lst **lst, t_lst *new);
t_lst				*lstlast(t_lst *lst);
void				lstadd_back(t_lst **lst, t_lst *new);
int					lstsize(t_lst *lst);
void				free_list(t_lst **lst);
int					find_max(t_lst *a);
int					find_min(t_lst *a);
int					sorted(t_lst *a);
long int			ft_atol(const char *nptr);
char				print_error(int argc, char **args);
int					duplicate_check(char **args);
int					error_handling(char **args);
t_lst				*error_mgm(int argc, char *argv[], t_lst *a);
void				ft_swap(t_lst **lst, char c);
void				ft_pa(t_lst **a, t_lst **b);
void				ft_pb(t_lst **a, t_lst **b);
void				ft_ra(t_lst **a, char c);
void				ft_rra(t_lst **a, char c);
t_lst				*up_to_3(t_lst *a);
void				cheapest(t_lst **a);
t_lst				*up_to_5(t_lst *a, t_lst *b);
void				free_array(char **arr);
t_lst				*create_list(int argc, char **args, t_lst *a);

#endif