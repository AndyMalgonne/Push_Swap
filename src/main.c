/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalgonn <amalgonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 13:55:25 by amalgonn          #+#    #+#             */
/*   Updated: 2024/01/17 14:49:37 by amalgonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	init_stack(int content, t_stack **a)
{
	t_stack	*tmp;
	t_stack	*last;

	tmp = ft_calloc(1, sizeof(t_stack));
	if (!tmp)
		return (0);
	tmp->content = content;
	tmp->next = NULL;
	tmp->prev = NULL;
	if (!*a)
		return (*a = tmp, 1);
	last = (*a);
	while (last->next)
		last = last->next;
	last->next = tmp;
	return (tmp->prev = last, 1);
}

int	check_arg(char *av, t_stack **a)
{
	char	*tmp;
	int		x;

	x = ft_atoi(av);
	tmp = ft_itoa(x);
	if (!tmp)
		return (0);
	if (ft_strncmp(tmp, av, ft_strlen(av)))
		return (free(tmp), 0);
	if (!init_stack(x, a))
		return (free(tmp), 0);
	return (free(tmp), 1);
}

void	free_list(t_stack *x)
{
	t_stack	*tmp;

	while (x)
	{
		tmp = x->next;
		free(x);
		x = tmp;
	}
}

void	print(t_stack *x)
{
	while(x)
	{
		ft_printf("%d ", x->content);
		x = x->next;
	}
	ft_putchar_fd('\n', 1);
}

int	main(int ac, char *av[])
{
	t_stack	*a;
	t_stack	*b;
	int i;

	a = NULL;
	b = NULL;
	i = 0;
	if(ac < 2)
		return 0;
	while(++i < ac)
		if (!check_arg(av[i], &a))
			return (1);
	rra(&a);
	(print(a), print(b));
	pb(&a, &b);
	(print(a), print(b));
	pb(&a, &b);
	(print(a), print(b));
	rrb(&a);
	(print(a), print(b));
	rrr(&a, &b);
	(print(a), print(b));
	(free_list(a), free_list(b));
	return (0);
}
