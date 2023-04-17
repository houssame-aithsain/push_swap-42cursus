/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hait-hsa <hait-hsa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 18:44:43 by hait-hsa          #+#    #+#             */
/*   Updated: 2023/02/18 17:44:02 by hait-hsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	ft_strlen(const	char *s)
{
	size_t	i;

	i = 0;
	while (s && s[i])
		i++;
	return (i);
}

size_t	count_c(char *s, char c)
{
	size_t	i;

	i = 0;
	while (s[i] != c && s[i])
		i++;
	return (i);
}

size_t	count_argv(char const *s, char c)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (s[i])
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == 0))
			j++;
		i++;
	}
	return (j);
}

char	**ft_split(char const *s, char c)
{
	char	**arr;
	size_t	i;
	size_t	j;
	size_t	len;

	i = 0;
	j = count_argv((char *)s, c);
	arr = malloc(sizeof(char *) * (j + 1));
	if (!arr)
		return (0);
	while (*(char *)s)
	{
		if (*(char *)s != c)
		{
			len = count_c((char *)s, c);
			arr[i] = ft_substr((char *)s, 0, len);
			s += len;
			i++;
		}
		else
			s++;
	}
	arr[j] = NULL;
	return (arr);
}
