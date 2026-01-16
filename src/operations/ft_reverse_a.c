/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarogarc <aarogarc@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 19:10:07 by aarogarc          #+#    #+#             */
/*   Updated: 2025/12/10 19:17:05 by aarogarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	ft_reverse_a(t_data *data, int check)
{
	t_list	*blast;
	t_list	*last;

	if (!data->a || !data->a->next)
		return ;
	last = ft_lstlast(data->a);
	blast = last->previous;
	if (blast)
		blast->next = NULL;
	last->next = data->a;
	last->previous = NULL;
	data->a->previous = last;
	data->a = last;
	if (check)
		ft_print_ints("rra\n", &data->moves);
}
