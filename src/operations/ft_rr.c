/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rr.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarogarc <aarogarc@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 16:40:20 by aarogarc          #+#    #+#             */
/*   Updated: 2025/12/10 16:42:11 by aarogarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	ft_rr(t_data *data)
{
	ft_rotate_a(data, 0);
	ft_rotate_b(data, 0);
	ft_print_ints("rr\n", &data->moves);
}
