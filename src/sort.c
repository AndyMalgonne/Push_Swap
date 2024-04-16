/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalgonn <amalgonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 15:28:31 by andymalgonn       #+#    #+#             */
/*   Updated: 2024/04/16 13:42:30 by amalgonn         ###   ########.fr       */
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

void	litle_sort(t_stack **a)
{
	size_t	size;

	size = stack_size(*a);
	if (size == 2)
		sort_two(a);
	else if (size == 3)
		sort_three(a);
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


void check_and_rra(t_stack **a)
{
    t_stack *tmp = *a;
    int smallest = tmp->index;
    int last;

    while (tmp != NULL)
    {
        if (tmp->index < smallest)
        {
            smallest = tmp->index;
        }
        tmp = tmp->next;
    }
    tmp = *a;
    while (tmp->next != NULL)
    {
        tmp = tmp->next;
    }
    last = tmp->index;
    if (last == smallest)
    {
        rra(a);
    }
}

void  repush(t_stack **a, t_stack **b)
{
    int first_b = (*b)->index;
	int biggest = 0;
    t_stack *tmp = *a;
    while (tmp) 
	{
        if (tmp->index > (*b)->index && (first_b == (*b)->index || tmp->index < first_b)) 
            first_b = tmp->index;
        tmp = tmp->next;
    }
	if (first_b == (*b)->index)
	{
		biggest = 1;
		tmp = *a;
		first_b = (*a)->index;
		while (tmp) 
		{
    	    if (tmp->index > first_b) 
			    first_b = tmp->index;
     	  	tmp = tmp->next;
  		}
	}
    tmp = *a;
    while (tmp && tmp->index != first_b) 
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
	check_and_rra(a);
}
