/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalgonn <amalgonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 13:00:32 by amalgonn          #+#    #+#             */
/*   Updated: 2024/01/17 13:36:13 by amalgonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack **a)
{
	t_stack *tmp;

	tmp = (*a)->next;
	(*a)->prev = tmp;
	tmp->prev = NULL;
	(*a)->next = tmp->next;
	tmp->next = (*a);
	(*a) = tmp;
	ft_printf("sa\n");
}
void	sb(t_stack **b)
{
	t_stack *tmp;

	tmp = (*b)->next;
	(*b)->prev = tmp;
	tmp->prev = NULL;
	(*b)->next = tmp->next;
	tmp->next = (*b);
	(*b) = tmp;
	ft_printf("sb\n");
}

void	ss(t_stack **a, t_stack **b)
{
	sa(a);
	sb(b);
	ft_printf("ss\n");
}