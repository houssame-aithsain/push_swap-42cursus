/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hait-hsa <hait-hsa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 14:11:25 by hait-hsa          #+#    #+#             */
/*   Updated: 2023/02/19 18:30:27 by hait-hsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long long	*ft_string_to_digits(char **arr, int lent)
{
	long long	*numb;
	int			i;

	i = 0;
	numb = malloc(sizeof(long long) * lent);
	if (!numb)
		return (0);
	while (arr[i] && i < lent)
	{
		numb[i] = ft_atoi(arr[i]);
		if (numb[i] > 2147483647 || numb[i] < -2147483648
			|| !check_duplicate(numb, i))
		{
			memory_free(NULL, NULL, numb, 3);
			write(2, "Error\n", 6);
			return (0);
		}
		i++;
	}
	memory_free(NULL, arr, NULL, 1);
	return (numb);
}

void	push_swap(char *str, int lent)
{
	t_list		*st_a;
	t_list		*st_b;
	long long	*holder;
	char		**result;

	st_a = NULL;
	st_b = NULL;
	result = ft_split(str, ' ');
	holder = ft_string_to_digits(result, lent);
	if (!holder)
	{
		memory_free(NULL, result, NULL, 1);
		return ;
	}
	nodepush(&st_a, holder, lent);
	if (lent <= 3)
		three_numb(&st_a);
	else if (lent == 4 || lent == 5)
		five_numb(&st_a, &st_b);
	else
		hundred_numb(&st_a, &st_b, lent);
	memory_free(&st_a, NULL, 0, 0);
	memory_free(&st_b, NULL, 0, 0);
	memory_free(NULL, NULL, holder, 3);
}

int	main(int argc, char **argv)
{
	int		lent;
	char	*arr;
	int		i;

	i = 1;
	if (argc > 1)
	{
		while (argv[i])
			arr = ft_strjoin_y(arr, argv[i++]);
		i = 1;
		while (argv[i])
		{
			if (!check_argv(argv[i++]))
			{
				free(arr);
				write(2, "Error\n", 6);
				return (0);
			}
		}
		lent = size_counter(arr);
		push_swap(arr, lent);
		free(arr);
	}
	return (0);
}
