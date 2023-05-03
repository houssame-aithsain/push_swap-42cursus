/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hundred_numb_plus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hait-hsa <hait-hsa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 23:34:31 by hait-hsa          #+#    #+#             */
/*   Updated: 2023/02/16 19:19:35 by hait-hsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_end(int end)
{
	int	i;

	if ((end) % 2 != 0)
		i = (end / 2) + 1;
	else
		return (end / 2);
	return (i);
}

int	*st_to_pointer(t_list *counter, int *arr_b)
{
	int	i;

	i = 0;
	while (counter)
	{
		arr_b[i] = counter->data;
		(counter) = (counter)->link;
		i++;
	}
	return (arr_b);
}

void	push_st_a(int *arr, t_list **st_b, int w)
{
	t_var	ptr;
	int		*arr_b;

	if (!*st_b)
		return ;
	ptr.i = 0;
	ptr.ex = 0;
	ptr.start = 0;
	ptr.end = get_end(w);
	arr_b = malloc(sizeof(int) * w + 1);
	if (!arr_b)
		return ;
	arr_b = st_to_pointer(*st_b, arr_b);
	while (ptr.start <= ptr.end)
	{
		if (arr[w] == arr_b[ptr.start])
			ptr.ex = 1;
		ptr.start++;
	}
	while (arr[w] != (*st_b)->data && ptr.ex)
		rb(st_b);
	while (arr[w] != (*st_b)->data)
		rrb(st_b);
	free(arr_b);
}

void	push_st_b(t_list **st_a, t_list **st_b, int *arr, int lent)
{
	while (*st_b)
	{
		lent--;
		push_st_a(arr, st_b, lent);
		pa(st_b, st_a);
	}
}
