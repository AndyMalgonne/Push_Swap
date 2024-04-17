/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalgonn <amalgonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 13:55:25 by amalgonn          #+#    #+#             */
/*   Updated: 2024/04/17 11:43:15 by amalgonn         ###   ########.fr       */
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
	if(!split || !split[0])
	return(ft_fsplit(split), 0);
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

void print_stack(t_stack *a) 
{
    while (a) 
	{
        printf("Content: %d, Index: %d\n", a->content, a->index);
        a = a->next;
    }
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

int	main(int ac, char *av[])
{
	t_stack	*a;
	t_stack	*b;
	int		i;

	a = NULL;
	b = NULL;
	i = 0;
	if (ac < 2)
		return(0);
	while (++i < ac)
	{
		if (!check_arg(av[i], &a))
		(free_list(a), error_arg());	
	}
	if (check_dup(a))
		error_arg();
	if (check_sorted(a))
		return (free_list(a), free_list(b), 0);
	if(check_sorted(a))
		return (free_list(a), 0);
	pre_sort(&a, &b);
	while (b)
		repush(&a, &b);
	if (!check_sorted(a))
		sort_in_position(&a);
	(print_stack(a), print_stack(b));
	(free_list(a), free_list(b));
	return (0);
}
