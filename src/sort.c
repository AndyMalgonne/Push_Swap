/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andymalgonne <andymalgonne@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 15:28:31 by andymalgonn       #+#    #+#             */
/*   Updated: 2024/04/05 08:48:04 by andymalgonn      ###   ########.fr       */
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
        return;
	
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

static void	litle_sort(t_stack *a)
{
	size_t	size;

	size = stack_size(a);
	if (size == 2)
		sort_two(&a);
	else if (size == 3)
		sort_three(&a);
}

void	pre_sort(t_stack **a, t_stack **b)
{
	size_t	size;
	size_t	i;

	i = 0;
	size = stack_size(*a);
	assign_index(*a);
	litle_sort(*a);
	if(size > 3)
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

void  repush(t_stack **a, t_stack **b)
{
    int first_b = (*b)->content;
	int biggest = 0;
    t_stack *tmp = *a;
    while (tmp) 
	{
        if (tmp->content > (*b)->content && (first_b == (*b)->content || tmp->content < first_b)) 
            first_b = tmp->content;
        tmp = tmp->next;
    }
	if (first_b == (*b)->content)
	{
		biggest = 1;
		tmp = *a;
		first_b = (*a)->content;
		while (tmp) 
		{
    	    if (tmp->content > first_b) 
			    first_b = tmp->content;
     	  	tmp = tmp->next;
  		}
	}
    tmp = *a;
    while (tmp && tmp->content != first_b) 
	{
		ra(a);
        tmp = *a;
    }
	if (biggest == 1)
		ra(a);
    if (tmp)
		pa(a, b);
	if (biggest == 1)
		ra(a);
}
