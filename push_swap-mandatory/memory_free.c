/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_free.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hait-hsa <hait-hsa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 20:35:25 by hait-hsa          #+#    #+#             */
/*   Updated: 2023/02/18 17:23:45 by hait-hsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	memory_free(t_list **list, char **arr, long long *numb, int flag)
{
	int	i;

	i = 0;
	if (flag == 0)
	{
		while (*list)
		{
			free(*list);
			*list = (*list)->link;
		}
	}
	else if (flag == 1)
	{
		while (arr[i])
			free(arr[i++]);
		free(arr);
	}
	else if (flag == 2)
		free(*arr);
	else
		free(numb);
}
