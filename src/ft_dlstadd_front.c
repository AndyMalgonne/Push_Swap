/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstadd_front.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalgonn <amalgonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 11:01:39 by amalgonn          #+#    #+#             */
/*   Updated: 2024/01/17 12:38:02 by amalgonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_dlstadd_front(t_stack **lst, t_stack *new)
{
	t_stack	*tmp;
	
	tmp = *lst;
	new->next = tmp;
	new->prev = NULL;
	if(tmp)
		tmp->prev = new;
	*lst = new;
}