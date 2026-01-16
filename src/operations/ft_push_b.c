/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarogarc <aarogarc@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 10:59:29 by aarogarc          #+#    #+#             */
/*   Updated: 2025/12/10 11:01:18 by aarogarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	ft_push_b(t_data *data, int check)
{
	t_list	*head;

	if (!data->a)
		return ;
	head = data->a;
	data->a = data->a->next;
	if (data->a)
		data->a->previous = NULL;
	head->next = data->b;
	head->previous = NULL;
	if (data->b)
		data->b->previous = head;
	data->b = head;
	if (check)
		ft_print_ints("pb\n", &data->moves);
}
