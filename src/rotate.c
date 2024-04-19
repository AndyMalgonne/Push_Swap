/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalgonn <amalgonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 13:54:15 by amalgonn          #+#    #+#             */
/*   Updated: 2024/04/19 15:01:39 by amalgonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_stack **a)
{
	t_stack	*tmp;
	t_stack	*last;

	if (!(*a))
		return ;
	tmp = (*a)->next;
	last = dlstlast(*a);
	tmp->prev = NULL;
	(*a)->next = NULL;
	(*a)->prev = last;
	last->next = (*a);
	(*a) = tmp;
	ft_printf("ra\n");
}

void	rb(t_stack **b)
{
	t_stack	*tmp;
	t_stack	*last;

	if (!(*b))
		return ;
	tmp = (*b)->next;
	last = dlstlast(*b);
	tmp->prev = NULL;
	(*b)->next = NULL;
	(*b)->prev = last;
	last->next = (*b);
	(*b) = tmp;
	ft_printf("rb\n");
}

void	rr(t_stack **a, t_stack **b)
{
	ra(a);
	rb(b);
	ft_printf("rr\n");
}
