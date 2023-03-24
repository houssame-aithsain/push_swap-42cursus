/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_duplicate_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hait-hsa <hait-hsa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 16:42:19 by hait-hsa          #+#    #+#             */
/*   Updated: 2023/02/19 17:30:41 by hait-hsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

int	check_duplicate(long long *numb, int lent)
{
	int	i;
	int	j;

	i = 0;
	while (i <= lent)
	{
		j = i + 1;
		while (j <= lent)
		{
			if (numb[i] == numb[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
