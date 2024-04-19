/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andymalgonne <andymalgonne@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 15:28:31 by andymalgonn       #+#    #+#             */
/*   Updated: 2024/04/19 13:24:15 by andymalgonn      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	assign_index(t_stack *a)
{
	size_t	size;
	int		min;
	t_stack	*highest;
	t_stack	*nbr;

	size = stack_size(a);
	while (--size)
	{
		min = -2147483648;
		highest = NULL;
		nbr = a;
		while (nbr)
		{
			if (min < nbr->content && !nbr->index)
			{
				min = nbr->content;
				highest = nbr;
			}
			nbr = nbr->next;
		}
		highest->index = size;
	}
}

void	pre_sort(t_stack **a, t_stack **b)
{
	size_t	size;
	size_t	i;

	i = 0;
	size = stack_size(*a);
	assign_index(*a);
	litle_sort(a);
	if (size > 3)
	{
		while (size - i > 3 && i < size / 2)
		{
			if ((*a)->index < (int)size / 2)
			{
				i++;
				pb(a, b);
			}
			else
				ra(a);
		}
		while (++i <= size - 3)
			pb(a, b);
		sort_three(a);
	}
}

void	ra_or_rra(t_stack **a, int first_b)
{
	t_stack	*tmp;
	int		up;
	int		down;

	up = 0;
	down = 0;
	tmp = *a;
	while (tmp->next)
	{
		if (tmp->index == first_b)
			break ;
		up++;
		tmp = tmp->next;
	}
	while (tmp->next)
		tmp = tmp->next;	
	while(tmp->prev)
	{
		if(tmp->index == first_b)
			break ;
		down++;
		tmp = tmp->prev;
	}
	if (up >= down)
	{
		while (up--)
			ra(a);
	}
	else
	{
		while (down--)
			rra(a);		
	}

}

int	find_location(t_stack **a, t_stack **b, int *biggest)
{
	t_stack	*tmp;
	int		first_b;

	tmp = *a;
	first_b = (*b)->index;
	while (tmp)
	{
		if (tmp->index > (*b)->index && (first_b == (*b)->index
				|| tmp->index < first_b))
			first_b = tmp->index;
		tmp = tmp->next;
	}
	if (first_b == (*b)->index)
	{
		*biggest = 1;
		tmp = *a;
		first_b = (*a)->index;
		while (tmp)
		{
			if (tmp->index > first_b)
				first_b = tmp->index;
			tmp = tmp->next;
		}
	}
	return (first_b);
}

void	repush(t_stack **a, t_stack **b)
{
	int		first_b;
	int		biggest;
	int		size;
	t_stack	*tmp;

	first_b = (*b)->index;
	biggest = 0;
	size = stack_size(*a);
	tmp = *a;
	first_b = find_location(a, b, &biggest);
	tmp = *a;
	ra_or_rra(a, first_b);
	if (biggest == 1)
		ra(a);
	if (tmp)
		pa(a, b);
	if (biggest == 1)
		ra(a);
	if (size > 3)
		check_and_rra(a);
}
