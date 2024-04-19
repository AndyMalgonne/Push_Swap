/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalgonn <amalgonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 15:28:31 by andymalgonn       #+#    #+#             */
/*   Updated: 2024/04/19 15:33:22 by amalgonn         ###   ########.fr       */
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

void	ra_or_rra(t_stack *x, t_dir *dir_x, int index)
{
	t_dir	tmp;

	dir_x->up = 0;
	dir_x->move = 0;
	tmp.up = 1;
	tmp.move = 1;
	tmp.biggest = dir_x->biggest;
	while (x->next)
	{
		if (x->index == index)
			break ;
		dir_x->move++;
		x = x->next;
	}
	while (x->next)
		x = x->next;
	while (x->prev)
	{
		if (x->index == index)
			break ;
		tmp.move++;
		x = x->prev;
	}
	if (dir_x->move > tmp.move)
		*dir_x = tmp;
}

void	shift_list(t_stack **x, t_dir *dir, int is_a)
{
	if (!dir->up)
	{
		while (dir->move--)
		{
			if (is_a)
				ra(x);
			else
				rb(x);
		}
	}
	else
	{
		while (dir->move--)
		{
			if (is_a)
				rra(x);
			else
				rrb(x);
		}
	}
}

int	find_location(t_stack *a, int index, int *biggest)
{
	t_stack	*tmp;
	int		first_b;

	tmp = a;
	first_b = -1;
	while (a)
	{
		if (a->index > index && (first_b == -1 || first_b > a->index))
			first_b = a->index;
		a = a->next;
	}
	*biggest = 0;
	if (first_b == -1)
		*biggest = 1;
	if (*biggest == 0)
		return (first_b);
	first_b = tmp->index;
	while (tmp)
	{
		if (tmp->index > first_b)
			first_b = tmp->index;
		tmp = tmp->next;
	}
	return (first_b);
}

void	lower_cost(t_stack *a, t_stack *b, t_dir *dir_a, t_dir *dir_b)
{
	t_stack	*tmp;
	t_dir	lower;
	int		index;

	tmp = b;
	lower.move = -1;
	while (b)
	{
		ra_or_rra(tmp, dir_b, b->index);
		ra_or_rra(a, dir_a, find_location(a, b->index, &dir_a->biggest));
		if (lower.move == -1 || dir_b->move + dir_a->move < lower.move)
		{
			lower.move = dir_b->move + dir_a->move;
			index = b->index;
		}
		b = b->next;
	}
	ra_or_rra(tmp, dir_b, index);
	ra_or_rra(a, dir_a, find_location(a, index, &dir_a->biggest));
}

void	repush(t_stack **a, t_stack **b)
{
	t_dir	dir_a;
	t_dir	dir_b;

	while (*b)
	{
		dir_a.biggest = 0;
		dir_b.biggest = 0;
		lower_cost(*a, *b, &dir_a, &dir_b);
		shift_list(a, &dir_a, 1);
		shift_list(b, &dir_b, 0);
		pa(a, b);
		if (dir_a.biggest)
			sa(a);
	}
}
