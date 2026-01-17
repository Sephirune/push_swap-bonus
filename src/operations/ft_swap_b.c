/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarogarc <aarogarc@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 17:42:13 by aarogarc          #+#    #+#             */
/*   Updated: 2025/12/08 17:44:40 by aarogarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	ft_swap_b(t_data *data, int check)
{
	t_list	*first;
	t_list	*second;
	t_list	*third;

	if (!data->b || !data->b->next)
		return ;
	first = data->b;
	second = data->b->next;
	third = second->next;
	data->b = second;
	second->previous = NULL;
	second->next = first;
	first->previous = second;
	first->next = third;
	if (third)
		third->previous = first;
	if (check)
		ft_print_ints("sb\n", &data->moves);
}
