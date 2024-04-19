/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrotate.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalgonn <amalgonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 14:36:14 by amalgonn          #+#    #+#             */
/*   Updated: 2024/04/19 15:01:27 by amalgonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_stack **a)
{
	t_stack	*tmp;
	t_stack	*last;

	if (!(*a))
		return ;
	if ((*a) && (*a)->next)
	{
		last = dlstlast(*a);
		tmp = last->prev;
		last->prev = NULL;
		last->next = (*a);
		tmp->next = NULL;
		(*a)->prev = last;
		(*a) = last;
		ft_printf("rra\n");
	}
}

void	rrb(t_stack **b)
{
	t_stack	*tmp;
	t_stack	*last;

	if (!(*b))
		return ;
	if ((*b) && (*b)->next)
	{
		last = dlstlast(*b);
		tmp = last->prev;
		last->prev = NULL;
		last->next = (*b);
		tmp->next = NULL;
		(*b)->prev = last;
		(*b) = last;
		ft_printf("rrb\n");
	}
}

void	rrr(t_stack **a, t_stack **b)
{
	rra(a);
	rrb(b);
	ft_printf("rrr\n");
}
