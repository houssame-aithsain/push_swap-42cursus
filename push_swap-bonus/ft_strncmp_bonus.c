/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hait-hsa <hait-hsa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 12:41:26 by hait-hsa          #+#    #+#             */
/*   Updated: 2023/02/16 21:18:34 by hait-hsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

size_t	check_lent(const char *s1, size_t n)
{
	size_t	i;

	i = 0;
	while (s1[i])
		i++;
	if (i - 1 != n)
		return (0);
	return (1);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (!check_lent(s1, n))
		return (0);
	while (s1 && s2 && i < n)
	{
		if (((unsigned char *)s1)[i] == 0 && ((unsigned char *)s2)[i] != 0)
			return (0);
		if (((unsigned char *)s1)[i] != 0 && ((unsigned char *)s2)[i] == 0)
			return (0);
		if (((unsigned char *)s1)[i] - ((unsigned char *)s2)[i] != 0)
			return (0);
		i++;
	}
	return (1);
}
