/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarogarc <aarogarc@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 16:37:34 by aarogarc          #+#    #+#             */
/*   Updated: 2025/12/10 16:39:45 by aarogarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	ft_rotate_b(t_data *data, int check)
{
	t_list	*first;
	t_list	*second;
	t_list	*last;

	if (!data->b || !data->b->next)
		return ;
	first = data->b;
	second = data->b->next;
	last = ft_lstlast(data->b);
	data->b = second;
	second->previous = NULL;
	last->next = first;
	first->previous = last;
	first->next = NULL;
	if (check)
		ft_print_ints("rb\n", &data->moves);
}
