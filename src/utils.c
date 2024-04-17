/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalgonn <amalgonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 15:22:28 by andymalgonn       #+#    #+#             */
/*   Updated: 2024/04/17 14:25:46 by amalgonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_list(t_stack *x)
{
	t_stack	*tmp;

	if (!x)
		return ;
	while (x)
	{
		tmp = x->next;
		free(x);
		x = tmp;
	}
}

void	print(t_stack *x)
{
	t_stack	*tmp;

	tmp = x;
	while (tmp)
	{
		ft_printf("%d ", tmp->content);
		tmp = tmp->next;
	}
	ft_putchar_fd('\n', 1);
}

int	stack_size(t_stack *a)
{
	int	count;

	count = 0;
	while (a)
	{
		count++;
		a = a->next;
	}
	return (count);
}

t_stack	*dlstlast(t_stack *lst)
{
	if (!lst)
		return (lst);
	while (lst->next)
		lst = lst ->next;
	return (lst);
}

void	dlstadd_front(t_stack **lst, t_stack *new)
{
	t_stack	*tmp;

	tmp = *lst;
	new->next = tmp;
	new->prev = NULL;
	if (tmp)
		tmp->prev = new;
	*lst = new;
}
