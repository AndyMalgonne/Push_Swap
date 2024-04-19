/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andymalgonne <andymalgonne@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 13:55:25 by amalgonn          #+#    #+#             */
/*   Updated: 2024/04/19 13:21:53 by andymalgonn      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	init_stack(int content, t_stack **a)
{
	t_stack	*tmp;
	t_stack	*last;

	tmp = ft_calloc(1, sizeof(t_stack));
	if (!tmp)
		return (0);
	tmp->content = content;
	tmp->next = NULL;
	tmp->prev = NULL;
	if (!*a)
		return (*a = tmp, 1);
	last = (*a);
	while (last->next)
		last = last->next;
	last->next = tmp;
	return (tmp->prev = last, 1);
}

int	check_arg(char *av, t_stack **a)
{
	char	*tmp;
	int		x;
	char	**split;
	int		i;

	split = ft_split(av, ' ');
	if (!split || !split[0])
		return (ft_fsplit(split), 0);
	i = 0;
	while (split[i])
	{
		x = ft_atoi(split[i]);
		tmp = ft_itoa(x);
		if (!tmp)
			return (0);
		if (ft_strncmp(tmp, split[i], ft_strlen(split[i])))
			return (free(tmp), ft_fsplit(split), 0);
		if (!init_stack(x, a))
			return (free(tmp), ft_fsplit(split), 0);
		free(tmp);
		i++;
	}
	ft_fsplit(split);
	return (1);
}

void	sort_in_position(t_stack **a)
{
	t_stack		*tmp;
	size_t		smallest_pos;
	size_t		len;

	tmp = *a;
	len = 0;
	smallest_pos = 0;
	while (tmp)
	{
		if (tmp->index == 0)
			smallest_pos = len;
		len++;
		tmp = tmp->next;
	}
	if ((len + 1) / 2 < smallest_pos)
		while (smallest_pos++ < len)
			rra(a);
	else
		while (smallest_pos-- > 0)
			ra(a);
}

void	push_swap(int ac, char *av[], t_stack **a, t_stack **b)
{
	int	i;

	i = 0;
	if (ac < 2)
		return ;
	while (++i < ac)
	{
		if (!check_arg(av[i], a))
			(free_list(*a), error_arg());
	}
	if (check_dup(*a))
		return (free_list(*a), free_list(*b), error_arg());
	if (check_sorted(*a))
		return (free_list(*a), free_list(*b));
	if (check_sorted(*a))
		return (free_list(*a));
	pre_sort(a, b);
	while (*b)
		repush(a, b);
	if (!check_sorted(*a))
		sort_in_position(a);
	(print(*a), print(*b));
	(free_list(*a), free_list(*b));
}

int	main(int ac, char *av[])
{
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	push_swap (ac, av, &a, &b);
	return (0);
}
