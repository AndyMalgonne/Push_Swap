/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalgonn <amalgonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 14:29:25 by andymalgonn       #+#    #+#             */
/*   Updated: 2024/04/17 14:42:07 by amalgonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_dup(t_stack *a)
{
	t_stack	*tmp;

	while (a)
	{
		tmp = a->next;
		while (tmp)
		{
			if (a->content == tmp->content)
				return (1);
			tmp = tmp->next;
		}
		a = a->next;
	}
	return (0);
}

int	check_sorted(t_stack *a)
{
	int	i;

	i = a->content;
	while (a)
	{
		if (i > a->content)
			return (0);
		i = a->content;
		a = a->next;
	}
	return (1);
}

void	check_and_rra(t_stack **a)
{
	t_stack	*tmp;
	int		smallest;
	int		last;

	tmp = *a;
	smallest = tmp->index;
	last = 0;
	while (tmp != NULL)
	{
		if (tmp->index < smallest)
			smallest = tmp->index;
		tmp = tmp->next;
	}
	tmp = *a;
	while (tmp->next != NULL)
		tmp = tmp->next;
	last = tmp->index;
	if (last == smallest)
		rra(a);
}

void	error_arg(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

void	print_stack(t_stack *a)
{
	while (a)
	{
		printf("Content: %d, Index: %d\n", a->content, a->index);
		a = a->next;
	}
}
