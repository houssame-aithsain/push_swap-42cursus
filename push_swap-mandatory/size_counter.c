/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   size_counter.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hait-hsa <hait-hsa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 20:42:51 by hait-hsa          #+#    #+#             */
/*   Updated: 2023/02/14 16:23:37 by hait-hsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	size_counter(char *arr)
{
	int	i;
	int	lent;

	lent = 0;
	i = 0;
	while (arr[i])
	{
		if (if_digit(arr[i]) && !if_digit(arr[i + 1]))
			lent++;
		i++;
	}
	return (lent);
}
