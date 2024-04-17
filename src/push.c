/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalgonn <amalgonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 16:14:12 by amalgonn          #+#    #+#             */
/*   Updated: 2024/04/17 13:47:39 by amalgonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push(t_stack **a, t_stack **b)
{
	t_stack	*tmp;

	tmp = *b;
	*b = (*b)->next;
	dlstadd_front(a, tmp);
	if (*b)
		(*b)->prev = NULL;
}

void	pa(t_stack **a, t_stack **b)
{
	if (!*b)
		return ;
	push(a, b);
	ft_printf("pa\n");
}

void	pb(t_stack **a, t_stack **b)
{
	if (!*a)
		return ;
	push(b, a);
	ft_printf("pb\n");
}
