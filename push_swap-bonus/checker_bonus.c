/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hait-hsa <hait-hsa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 17:09:53 by hait-hsa          #+#    #+#             */
/*   Updated: 2023/02/19 19:30:59 by hait-hsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

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
			memory_free(NULL, arr, numb, -1);
			write(2, "Error\n", 6);
			return (0);
		}
		i++;
	}
	memory_free(NULL, arr, NULL, 1);
	return (numb);
}

int	action(t_list **st_a, t_list **st_b, char *buffer)
{
	if (ft_strncmp(buffer, "sa", 2))
		sa(st_a);
	else if (ft_strncmp(buffer, "ra", 2))
		ra(st_a);
	else if (ft_strncmp(buffer, "rra", 3))
		rra(st_a);
	else if (ft_strncmp(buffer, "pa", 2))
		pa(st_b, st_a);
	else if (ft_strncmp(buffer, "sb", 2))
		sb(st_b);
	else if (ft_strncmp(buffer, "rb", 2))
		rb(st_b);
	else if (ft_strncmp(buffer, "rrb", 3))
		rrb(st_b);
	else if (ft_strncmp(buffer, "pb", 2))
		pb(st_a, st_b);
	else if (ft_strncmp(buffer, "rr", 2))
		rr(st_a, st_b);
	else if (ft_strncmp(buffer, "rrr", 3))
		rrr(st_a, st_b);
	else if (ft_strncmp(buffer, "ss", 2))
		ss(st_a, st_b);
	else
		return (0);
	return (1);
}

void	handel_prs(t_list **st_a, t_list **st_b, t_var *tmp)
{
	while (tmp->buffer || tmp->i)
	{
		tmp->i = 0;
		tmp->j = 1;
		tmp->buffer = get_next_line(0);
		if (tmp->buffer)
			tmp->j = action(st_a, st_b, tmp->buffer);
		free(tmp->buffer);
		if (!tmp->j)
		{
			write(2, "Error\n", 6);
			break ;
		}
	}
	print_result(tmp->j, st_b, st_a);
}

void	ft_handler(t_var *tmp, t_list **st_a, t_list **st_b)
{
	tmp->lent = size_counter(tmp->arr);
	tmp->result = ft_split(tmp->arr, ' ');
	tmp->numbs = ft_string_to_digits(tmp->result, tmp->lent);
	if (!tmp->numbs)
		return ;
	nodepush(st_a, tmp->numbs, tmp->lent);
	handel_prs(st_a, st_b, tmp);
	memory_free(st_a, NULL, NULL, 0);
	memory_free(st_b, NULL, NULL, 0);
	memory_free(NULL, NULL, tmp->numbs, 3);
}

int	main(int argc, char **argv)
{
	t_var	tmp;
	t_list	*st_a;
	t_list	*st_b;

	tmp.i = 1;
	tmp.arr = NULL;
	st_a = NULL;
	st_b = NULL;
	if (argc < 2)
		return (0);
	while (argv[tmp.i])
		tmp.arr = ft_strjoin(tmp.arr, argv[tmp.i++]);
	tmp.i = 1;
	while (argv[tmp.i])
	{
		if (!check_argv(argv[tmp.i++]))
		{
			free(tmp.arr);
			write(2, "Error\n", 6);
			return (0);
		}
	}
	ft_handler(&tmp, &st_a, &st_b);
	free(tmp.arr);
	return (0);
}
