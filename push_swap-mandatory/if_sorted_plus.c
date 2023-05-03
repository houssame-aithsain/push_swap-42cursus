/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   if_sorted_plus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hait-hsa <hait-hsa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 18:57:36 by hait-hsa          #+#    #+#             */
/*   Updated: 2023/02/15 17:46:14 by hait-hsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_push_rotate_b(t_list **st_a, t_list **st_b)
{
	int	j;

	j = 0;
	while (j < 20)
	{
		pb(st_a, st_b);
		rb(st_b);
		j++;
	}
}

void	if_sorted_plus(t_list **st_a, t_list **st_b)
{
	int		i;
	int		counter;
	t_list	*tmp;

	tmp = *st_a;
	counter = 0;
	i = tmp->data;
	while (tmp->link)
	{
		if (counter > 20)
		{
			ft_push_rotate_b(st_a, st_b);
			counter = 0;
		}
		tmp = tmp->link;
		if (i > tmp->data)
		{
			i = tmp->data;
			counter++;
		}
	}
}
