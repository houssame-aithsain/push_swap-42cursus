/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   if_sorted_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hait-hsa <hait-hsa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 19:34:10 by hait-hsa          #+#    #+#             */
/*   Updated: 2023/02/19 16:51:23 by hait-hsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

int	if_sorted(t_list *st_a)
{
	long long	i;

	if (!st_a)
		return (0);
	i = st_a->data;
	while (st_a->link)
	{
		st_a = st_a->link;
		if (i < st_a->data)
			i = st_a->data;
		else
			return (0);
	}
	return (1);
}

void	ss(t_list **st_a, t_list **st_b)
{
	sa(st_a);
	sb(st_b);
}

void	print_result(int j, t_list **st_b, t_list **st_a)
{
	if (j)
	{
		if (*st_b)
		{
			write(1, "KO\n", 3);
			return ;
		}
		if (if_sorted(*st_a))
			write(1, "OK\n", 3);
		else
			write(1, "KO\n", 3);
	}
}
