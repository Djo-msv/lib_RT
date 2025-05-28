/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrolland <nrolland@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 17:46:21 by nrolland          #+#    #+#             */
/*   Updated: 2025/05/28 18:51:23 by nrolland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_rt.h"

int	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*current;

	if (!lst || !new)
		return (1);
	if (!*lst)
	{
		*lst = new;
		return (0);
	}
	current = *lst;
	current = ft_lstlast(current);
	current->next = new;
	return (0);
}
