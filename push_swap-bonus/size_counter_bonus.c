/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   size_counter_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hait-hsa <hait-hsa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 20:42:51 by hait-hsa          #+#    #+#             */
/*   Updated: 2023/02/16 21:18:55 by hait-hsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

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
