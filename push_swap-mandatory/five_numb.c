/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   five_numb.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hait-hsa <hait-hsa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 20:14:25 by hait-hsa          #+#    #+#             */
/*   Updated: 2023/02/15 17:44:29 by hait-hsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_second_smaller_numb(t_list *st_a, int first)
{
	int	second;

	if (st_a->data == first)
		second = st_a->link->data;
	else
		second = st_a->data;
	while (st_a)
	{
		if (st_a->data < second && st_a->data != first)
			second = st_a->data;
		st_a = st_a->link;
	}
	return (second);
}

int	get_first_smaller_numb(t_list *st_a)
{
	int	first;

	first = st_a->data;
	while (st_a)
	{
		if (st_a->data < first)
			first = st_a->data;
		st_a = st_a->link;
	}
	return (first);
}

int	if_sorted(t_list *st_a)
{
	int	i;

	i = st_a->data;
	while (st_a->link)
	{
		st_a = st_a->link;
		if (i < st_a->data)
			i = st_a->data;
		else
			return (1);
	}
	return (0);
}

void	push_back(t_list **st_a, t_list **st_b)
{
	three_numb(st_a);
	pa(st_b, st_a);
	pa(st_b, st_a);
	if ((*st_a)->link->data < (*st_a)->data)
		sa(st_a);
}

void	five_numb(t_list **st_a, t_list **st_b)
{
	int	count;
	int	first;
	int	second;

	count = 0;
	if (!if_sorted(*st_a))
		return ;
	first = get_first_smaller_numb(*st_a);
	second = get_second_smaller_numb(*st_a, first);
	while (if_sorted(*st_a) && count < 2)
	{
		if ((*st_a)->data == first || (*st_a)->data == second)
		{
			pb(st_a, st_b);
			count++;
		}
		else if ((*st_a)->link->data == first || (*st_a)->link->data == second)
			ra(st_a);
		else
			rra(st_a);
	}
	push_back(st_a, st_b);
}
