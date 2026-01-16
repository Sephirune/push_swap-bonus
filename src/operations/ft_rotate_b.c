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

	if (!data->a || !data->a->next)
		return ;
	first = data->b;
	second = data->a->next;
	last = data->b;
	while (last->next)
		last = last->next;
	data->b = second;
	second->previous = NULL;
	last->next = first;
	first->previous = last;
	first->next = NULL;
	if (check)
		ft_print_ints("rb\n", &data->moves);
}
