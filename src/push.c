/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalgonn <amalgonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 16:14:12 by amalgonn          #+#    #+#             */
/*   Updated: 2024/01/17 11:29:32 by amalgonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push(t_stack **a, t_stack **b)
{	
	t_stack	*tmp;

	if(!*b)
		return;
	tmp = *b;
	*b = (*b)->next;
	if(*b)
		(*b)->prev = NULL;
	ft_dlstadd_front(a, tmp);
}

void	pa(t_stack **a, t_stack **b)
{
	push(a, b);
	ft_printf("pa\n");
}

void	pb(t_stack **a, t_stack **b)
{
	push(b, a);
	ft_printf("pb\n");
}