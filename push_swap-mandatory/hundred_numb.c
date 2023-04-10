/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hundred_numb.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hait-hsa <hait-hsa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 19:56:30 by hait-hsa          #+#    #+#             */
/*   Updated: 2023/02/16 19:17:20 by hait-hsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_end_plus(int lent)
{
	int	i;
	int	j;

	if (lent <= 100)
		j = 7;
	else
		j = 17;
	if (lent % j != 0)
		i = (lent / j) + 1;
	else
		return (lent / j);
	return (i);
}

void	if_range(t_list **st_a, t_list **st_b, t_var *ptr)
{
	if (ptr->counter >= ptr->start_a && ptr->counter <= ptr->end_a)
	{
		pb(st_a, st_b);
		ptr->start_a += 1;
		ptr->end_a += 1;
	}
	else if (ptr->counter < ptr->start_a)
	{
		pb(st_a, st_b);
		rb(st_b);
		ptr->start_a += 1;
		ptr->end_a += 1;
	}
	else if (ptr->counter > ptr->end_a)
		ra(st_a);
}

int	*bubble_sort(int *arr, int lent)
{
	int	i;
	int	j;
	int	index;

	i = 0;
	while (i < lent)
	{
		j = 0;
		while (j < lent - i - 1)
		{
			if (arr[j] > arr[j + 1])
			{
				index = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = index;
			}
			j++;
		}
		i++;
	}
	return (arr);
}

int	*get_sorted_array(t_list *st_a, int lent)
{
	int		*arr;
	int		i;

	i = 0;
	arr = malloc(sizeof(int) * lent);
	if (!arr)
		return (0);
	while (st_a)
	{
		arr[i] = st_a->data;
		st_a = st_a->link;
		i++;
	}
	arr = bubble_sort(arr, lent);
	return (arr);
}

void	hundred_numb(t_list **st_a, t_list **st_b, int lent)
{
	t_var	ptr;
	int		*arr;

	if (!if_sorted(*st_a))
		return ;
	ptr.start_a = 0;
	ptr.end_a = get_end_plus(lent);
	arr = get_sorted_array(*st_a, lent);
	if_sorted_plus(st_a, st_b);
	while (*st_a)
	{
		ptr.counter = 0;
		while (ptr.counter < lent)
		{
			if (arr[ptr.counter] == (*st_a)->data)
			{
				if_range(st_a, st_b, &ptr);
				break ;
			}
			ptr.counter++;
		}
	}
	push_st_b(st_a, st_b, arr, lent);
	free(arr);
}
