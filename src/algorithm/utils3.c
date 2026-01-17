/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarogarc <aarogarc@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 16:09:14 by aarogarc          #+#    #+#             */
/*   Updated: 2026/01/12 16:09:17 by aarogarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	aux_split(t_data *data, char **split)
{
	int		j;
	int		value;
	t_list	*node;

	j = 0;
	while (split[j])
	{
		value = ft_atoi(split[j]);
		if (check_duplicate(data, value))
			check_error_free(data);
		node = ft_lstnew(value);
		if (!node)
			check_error_free(data);
		ft_lstadd_back(&data->a, node);
		j++;
	}
}

void	free_list(t_list **lst)
{
	t_list	*current;
	t_list	*next;

	if (!lst || !*lst)
		return ;
	current = *lst;
	while (current)
	{
		next = current->next;
		free(current);
		current = next;
	}
	*lst = NULL;
}

void	check_error_free(t_data *data)
{
	free_list(&data->a);
	free_list(&data->b);
	write(2, "Error\n", 6);
	exit (1);
}
