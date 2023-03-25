/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hait-hsa <hait-hsa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 17:09:57 by hait-hsa          #+#    #+#             */
/*   Updated: 2023/02/19 22:21:35 by hait-hsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_BONUS_H
# define CHECKER_BONUS_H

# include <stdlib.h>
# include <unistd.h>
# include "get_next_line_bonus.h"

typedef struct node
{
	long long	data;
	struct node	*link;
}	t_list;

typedef struct var
{
	char		**result;
	char		*arr;
	long long	*numbs;
	int			lent;
	int			i;
	int			j;
	int			size;
	char		*buffer;
	long long	*numb;
}	t_var;

void		print_result(int j, t_list **st_b, t_list **st_a);
void		ss(t_list **st_a, t_list **st_b);
int			if_sorted(t_list *st_a);
void		handel_prs(t_list **st_a, t_list **st_b, t_var *tmp);
long long	*ft_string_to_digits(char **arr, int lent);
void		ft_handler(t_var *tmp, t_list **st_a, t_list **st_b);
char		*ft_strjoin(char const *s1, char const *s2);
void		rr(t_list **st_a, t_list **st_b);
void		rrr(t_list **st_a, t_list **st_b);
int			check_duplicate(long long *numb, int lent);
long long	ft_atoi(const char *str);
void		*ft_memcpy(void *dst, const void *src, size_t n);
char		**ft_split(char *s, char c);
char		*ft_strdup(char *s1);
int			check_argv(char *str);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
char		*ft_substr(char *s, unsigned int start, size_t len);
void		memory_free(t_list **list, char **arr, long long *numb, int flag);
void		nodepush(t_list **head, long long *result, int lent);
size_t		ft_strlen_g(char *str);
int			size_counter(char *str);
void		ra(t_list **st_a);
void		pa(t_list **st_b, t_list **st_a);
void		sa(t_list **st_a);
void		rra(t_list **st_a);
void		rrb(t_list **st_b);
void		rb(t_list **st_b);
void		pb(t_list **st_a, t_list **st_b);
void		sb(t_list **st_b);
int			if_valid(char c);
int			if_digit(char c);
int			ft_check_str(char *str);
void		push_front(t_list **st_x, t_list **st_y);

#endif