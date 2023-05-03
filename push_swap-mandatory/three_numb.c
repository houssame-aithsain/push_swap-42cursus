/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   three_numb.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hait-hsa <hait-hsa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 20:15:39 by hait-hsa          #+#    #+#             */
/*   Updated: 2023/02/15 17:44:52 by hait-hsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	three_numbs_plus(t_list **st_a)
{
	if ((*st_a)->data > (*st_a)->link->data
		&& (*st_a)->link->data > (*st_a)->link->link->data)
	{
		ra(st_a);
		sa(st_a);
	}
	else if ((*st_a)->data > (*st_a)->link->data
		&& (*st_a)->link->data < (*st_a)->link->link->data)
	{
		if ((*st_a)->data < (*st_a)->link->link->data)
			sa(st_a);
		else
			ra(st_a);
	}	
}

void	three_numb(t_list **st_a)
{
	if (!(*st_a)->link)
		return ;
	else if (!(*st_a)->link->link)
	{
		if ((*st_a)->data > (*st_a)->link->data)
			sa(st_a);
	}
	else if ((*st_a)->data < (*st_a)->link->data
		&& (*st_a)->link->link->data < (*st_a)->data)
		rra(st_a);
	else if ((*st_a)->data < (*st_a)->link->data
		&& (*st_a)->link->link->data < (*st_a)->link->data)
	{
		sa(st_a);
		ra(st_a);
	}
	three_numbs_plus(st_a);
}
