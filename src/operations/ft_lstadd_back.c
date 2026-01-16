/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarogarc <aarogarc@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 16:11:45 by aarogarc          #+#    #+#             */
/*   Updated: 2026/01/12 16:11:47 by aarogarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*temp;

	if (!lst || !new)
		return ;
	new->previous = NULL;
	new->next = NULL;
	if (*lst != NULL)
	{
		temp = ft_lstlast(*lst);
		temp->next = new;
		new->previous = temp;
	}
	else
		*lst = new;
}
