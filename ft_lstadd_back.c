/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotomas- <jotomas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 15:08:15 by jotomas-          #+#    #+#             */
/*   Updated: 2023/11/15 11:38:36 by jotomas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last_node;

	if (*lst)
	{
		last_node = ft_lstlast(*lst);
		last_node->next = new;
	}
	else
	{
		*lst = new;
	}
}
