/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   st_b_actions_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hait-hsa <hait-hsa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 15:47:47 by hait-hsa          #+#    #+#             */
/*   Updated: 2023/02/16 21:19:02 by hait-hsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	rrr(t_list **st_a, t_list **st_b)
{
	rra(st_a);
	rrb(st_b);
}

void	rrb(t_list **st_b)
{
	t_list	*tmp;
	t_list	*befor_last;

	if (!(*st_b) || !(*st_b)->link)
		return ;
	tmp = NULL;
	befor_last = NULL;
	while ((*st_b)->link)
		push_front(st_b, &tmp);
	push_front(st_b, &befor_last);
	while (tmp)
		push_front(&tmp, st_b);
	push_front(&befor_last, st_b);
}

void	rb(t_list **st_b)
{
	t_list	*tmp;
	t_list	*last;

	if (!(*st_b) || !(*st_b)->link)
		return ;
	tmp = NULL;
	last = NULL;
	push_front(st_b, &tmp);
	while (*st_b)
		push_front(st_b, &last);
	push_front(&tmp, st_b);
	while (last)
		push_front(&last, st_b);
}

void	pb(t_list **st_a, t_list **st_b)
{
	t_list	*tmp;

	if (!*st_a)
		return ;
	tmp = *st_a;
	*st_a = (*st_a)->link;
	tmp->link = *st_b;
	*st_b = tmp;
	return ;
}

void	sb(t_list **st_b)
{
	t_list	*ptr;
	t_list	*tmp;

	if (!(*st_b) || !(*st_b)->link)
		return ;
	ptr = (*st_b)->link;
	tmp = (*st_b);
	tmp = (*st_b)->link->link;
	ptr->link = *st_b;
	(*st_b)->link = tmp;
	*st_b = ptr;
}
