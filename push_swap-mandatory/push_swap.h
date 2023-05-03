/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hait-hsa <hait-hsa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 14:13:00 by hait-hsa          #+#    #+#             */
/*   Updated: 2023/02/19 22:21:22 by hait-hsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>

typedef struct node
{
	long long	data;
	struct node	*link;
}	t_list;

typedef struct var
{
	int	start_a;
	int	end_a;
	int	counter;
	int	start;
	int	end;
	int	i;
	int	ex;
}	t_var;

void	push_front(t_list **st_x, t_list **st_y);
void	pa_test(t_list **st_a, t_list **st_y);
int		ft_count_argv(char const *s, char c);
void	newnode(t_list **new, long long numb);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	**ft_split(char const *s, char c);
long	ft_atoi(const char *str);
size_t	ft_strlen(const	char *s);
char	*ft_strdup(const char *s1);
void	*ft_memcpy(void *dst, const void *src, size_t n);
void	nodepush(t_list **head, long long *result, int lent);
void	five_numb(t_list **st_a, t_list **st_b);
void	three_numb(t_list **st_a);
int		check_argv(char *str);
int		if_sorted(t_list *st_a);
int		get_second_smaller_numb(t_list *st_a, int first);
int		get_first_smaller_numb(t_list *st_a);
t_list	*get_new(t_list *new);
t_list	*get_last(t_list *ptr);
void	ra(t_list **st_a);
void	pa(t_list **st_b, t_list **st_a);
void	sa(t_list **st_a);
void	rra(t_list **st_a);
void	rrb(t_list **st_b);
void	rb(t_list **st_b);
void	pb(t_list **st_a, t_list **st_b);
void	sb(t_list **st_b);
void	three_numb(t_list **st_a);
void	hundred_numb(t_list **st_a, t_list **st_b, int lent);
int		get_first_smaller_numb(t_list *st_a);
int		size_counter(char *str);
void	rrr(t_list **st_a, t_list **st_b);
int		if_valid(char c);
int		ft_check_str(char *str);
int		if_digit(char c);
void	memory_free(t_list **list, char **arr, long long *numb, int flag);
void	push_st_b(t_list **st_a, t_list **st_b, int *arr, int lent);
int		check_duplicate(long long *numb, int lent);
void	if_sorted_plus(t_list **st_a, t_list **st_b);
char	*ft_strjoin_y(char const *s1, char const *s2);
#endif