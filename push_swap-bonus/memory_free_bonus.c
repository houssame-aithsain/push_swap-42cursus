/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_free_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hait-hsa <hait-hsa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 20:35:25 by hait-hsa          #+#    #+#             */
/*   Updated: 2023/02/19 19:33:11 by hait-hsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	double_free(char **arr, long long *numb)
{
	int	i;

	i = 0;
	while (arr[i])
		free(arr[i++]);
	free(arr);
	free(numb);
}

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
	else if (flag == 3)
		free(numb);
	else if (flag == -1)
		double_free(arr, numb);
}
