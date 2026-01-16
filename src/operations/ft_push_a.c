/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_a.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarogarc <aarogarc@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 14:59:29 by aarogarc          #+#    #+#             */
/*   Updated: 2025/12/10 10:59:08 by aarogarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	ft_push_a(t_data *data, int check)
{
	t_list	*head;

	if (!data->b)
		return ;
	head = data->b;
	data->b = data->b->next;
	if (data->b)
		data->b->previous = NULL;
	head->next = data->a;
	head->previous = NULL;
	if (data->a)
		data->a->previous = head;
	data->a = head;
	if (check)
		ft_print_ints("pa\n", &data->moves);
}
