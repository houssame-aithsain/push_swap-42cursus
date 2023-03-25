/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hait-hsa <hait-hsa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 18:51:58 by hait-hsa          #+#    #+#             */
/*   Updated: 2023/02/16 21:18:03 by hait-hsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

long long	ft_atoi(const char *str)
{
	long	i;
	long	x;
	long	size;

	size = 0;
	i = 0;
	x = 1;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			x = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		size = size * 10;
		size = size + str[i] - 48;
		i++;
	}
	return (size * x);
}
