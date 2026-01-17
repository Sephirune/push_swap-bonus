/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse_b.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarogarc <aarogarc@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 11:07:25 by aarogarc          #+#    #+#             */
/*   Updated: 2025/12/17 11:07:30 by aarogarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	ft_reverse_b(t_data *data, int check)
{
	t_list	*blast;
	t_list	*last;

	if (!data->b || !data->b->next)
		return ;
	last = ft_lstlast(data->b);
	blast = last->previous;
	blast->next = NULL;
	last->next = data->b;
	last->previous = NULL;
	data->b->previous = last;
	data->b = last;
	if (check)
		ft_print_ints("rrb\n", &data->moves);
}
