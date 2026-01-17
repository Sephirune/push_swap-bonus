/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rrr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarogarc <aarogarc@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 16:15:53 by aarogarc          #+#    #+#             */
/*   Updated: 2026/01/12 16:15:54 by aarogarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	ft_rrr(t_data *data)
{
	ft_reverse_a(data, 0);
	ft_reverse_b(data, 0);
	ft_print_ints("rrr\n", &data->moves);
}
