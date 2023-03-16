/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   st_a_actions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hait-hsa <hait-hsa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 15:45:11 by hait-hsa          #+#    #+#             */
/*   Updated: 2023/02/16 16:01:31 by hait-hsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_list **st_a)
{
	t_list	*tmp;
	t_list	*last;

	if (!(*st_a) || !(*st_a)->link)
		return ;
	tmp = NULL;
	last = NULL;
	push_front(st_a, &tmp);
	while (*st_a)
		push_front(st_a, &last);
	push_front(&tmp, st_a);
	while (last)
		push_front(&last, st_a);
	write(1, "ra\n", 3);
}

void	pa(t_list **st_b, t_list **st_a)
{
	t_list	*tmp;

	if (!*st_b)
		return ;
	tmp = *st_b;
	*st_b = (*st_b)->link;
	tmp->link = *st_a;
	*st_a = tmp;
	write(1, "pa\n", 3);
	return ;
}

void	sa(t_list **st_a)
{
	t_list	*ptr;
	t_list	*tmp;

	if (!(*st_a) || !(*st_a)->link)
		return ;
	push_front(st_a, &tmp);
	push_front(st_a, &ptr);
	push_front(&tmp, st_a);
	push_front(&ptr, st_a);
	write(1, "sa\n", 3);
}

void	rra(t_list **st_a)
{
	t_list	*tmp;
	t_list	*befor_last;

	if (!(*st_a) || !(*st_a)->link)
		return ;
	tmp = NULL;
	befor_last = NULL;
	while ((*st_a)->link)
		push_front(st_a, &tmp);
	push_front(st_a, &befor_last);
	while (tmp)
		push_front(&tmp, st_a);
	push_front(&befor_last, st_a);
	write(1, "rra\n", 4);
}
