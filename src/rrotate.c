/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrotate.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andymalgonne <andymalgonne@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 14:36:14 by amalgonn          #+#    #+#             */
/*   Updated: 2024/03/23 15:35:49 by andymalgonn      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_stack **a)
{
	t_stack	*tmp;
	t_stack	*last;

	if (!(*a))
		return ;
	last = dlstlast(*a);
	tmp = last->prev;
	last->prev = NULL;
	last->next = (*a);
	tmp->next = NULL;
	(*a)->prev = last;
	(*a) = last;
	ft_printf("rra\n");
}

void	rrb(t_stack **b)
{
	t_stack	*tmp;
	t_stack	*last;

	if (!(*b))
		return ;
	printf("ptr %p\n", *b);
	last = dlstlast(*b);
	tmp = last->prev;
	last->prev = NULL;
	last->next = (*b);
	tmp->next = NULL;
	(*b)->prev = last;
	(*b) = last;
	ft_printf("rrb\n");
}

void	rrr(t_stack **a, t_stack **b)
{
	rra(a);
	rrb(b);
	ft_printf("rrr\n");
}
