/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nodepush_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hait-hsa <hait-hsa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 18:49:57 by hait-hsa          #+#    #+#             */
/*   Updated: 2023/02/16 21:18:52 by hait-hsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	push_front(t_list **st_x, t_list **st_y)
{
	t_list	*tmp;

	if (!*st_x)
		return ;
	tmp = *st_x;
	*st_x = (*st_x)->link;
	tmp->link = *st_y;
	*st_y = tmp;
	return ;
}

t_list	*get_last(t_list *ptr)
{
	while (ptr->link)
		ptr = ptr->link;
	return (ptr);
}

t_list	*get_new(t_list *new)
{
	new = malloc(sizeof(t_list));
	if (!new)
		return (0);
	new->data = 0;
	new->link = NULL;
	return (new);
}

void	newnode(t_list **new, long long numb)
{
	t_list	*current;
	t_list	*ptr;

	current = NULL;
	current = get_new(current);
	current->data = numb;
	if (*new == NULL)
	{
		*new = current;
		return ;
	}
	ptr = get_last(*new);
	ptr->link = current;
}

void	nodepush(t_list **head, long long *result, int lent)
{
	int	i;

	i = 0;
	while (i < lent)
		newnode(&(*head), result[i++]);
}
