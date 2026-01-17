/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap_ab.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarogarc <aarogarc@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 17:44:52 by aarogarc          #+#    #+#             */
/*   Updated: 2025/12/08 20:57:05 by aarogarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	ft_swap_ab(t_data *data)
{
	ft_swap_a(data, 0);
	ft_swap_b(data, 0);
	ft_print_ints("ss\n", &data->moves);
}
