/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_or.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hait-hsa <hait-hsa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 18:00:06 by hait-hsa          #+#    #+#             */
/*   Updated: 2023/02/17 19:37:57 by hait-hsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*ft_strjoin_y(char const *s1, char const *s2)
{
	size_t	j;
	size_t	i;
	size_t	b;
	char	*arr;

	i = 0;
	j = ft_strlen(s1) + ft_strlen(s2);
	b = ft_strlen(s1);
	arr = malloc(j + 2);
	if (! arr)
		return (0);
	arr = ft_memcpy(arr, s1, b);
	while (b < j)
	{
		arr[b++] = s2[i++];
	}
	arr[b++] = ' ';
	arr[b] = 0;
	free((char *)s1);
	return (arr);
}
