/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fsplit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalgonn <amalgonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 15:12:06 by andymalgonn       #+#    #+#             */
/*   Updated: 2024/04/19 08:47:52 by amalgonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_fsplit(char **split)
{
	size_t	i;

	i = 0;
	if (split != NULL)
	{
		while (split[i])
			free(split[i++]);
		free (split);
	}
	return (NULL);
}
