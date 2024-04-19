/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andymalgonne <andymalgonne@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 10:32:21 by andymalgonn       #+#    #+#             */
/*   Updated: 2024/04/18 10:34:42 by andymalgonn      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_two(t_stack **a)
{
	int	one;
	int	two;

	one = (*a)->content;
	two = (*a)->next->content;
	if (two < one)
		sa(a);
}

void	sort_three(t_stack	**a)
{
	int	one;
	int	two;
	int	three;

	if (!(*a) || !(*a)->next || !(*a)->next->next)
		return ;
	one = (*a)->content;
	two = (*a)->next->content;
	three = (*a)->next->next->content;
	if (one > two && one > three)
	{
		ra(a);
		sort_two(a);
	}
	else if (two > one && two > three)
	{
		rra(a);
		sort_two(a);
	}
	else if (three > one && three > two)
		sort_two(a);
}

void	litle_sort(t_stack **a)
{
	size_t	size;

	size = stack_size(*a);
	if (size == 2)
		sort_two(a);
	else if (size == 3)
		sort_three(a);
}
