/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   st_a_actions_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hait-hsa <hait-hsa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 15:45:11 by hait-hsa          #+#    #+#             */
/*   Updated: 2023/02/16 21:18:59 by hait-hsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	rr(t_list **st_a, t_list **st_b)
{
	ra(st_a);
	rb(st_b);
}

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
}
