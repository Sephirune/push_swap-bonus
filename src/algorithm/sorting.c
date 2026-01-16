/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarogarc <aarogarc@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 12:00:00 by aarogarc          #+#    #+#             */
/*   Updated: 2025/01/15 12:00:00 by aarogarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	size_2(t_data *data)
{
	if (!data->a || !data->a->next)
		return ;
	if ((data->a->nb) > (data->a->next->nb))
		ft_swap_a(data, 1);
}

void	size_3(t_data *data)
{
	long	a;
	long	b;
	long	c;

	if (!data->a || !data->a->next || !data->a->next->next)
		return ;
	a = data->a->nb;
	b = data->a->next->nb;
	c = data->a->next->next->nb;
	if (a > b && b < c && a < c)
		ft_swap_a(data, 1);
	else if (a > b && b < c && a > c)
		ft_rotate_a(data, 1);
	else if (a > b && b > c)
	{
		ft_swap_a(data, 1);
		ft_reverse_a(data, 1);
	}
	else if (a < b && b > c && a < c)
	{
		ft_swap_a(data, 1);
		ft_rotate_a(data, 1);
	}
	else if (a < b && b > c && a > c)
		ft_reverse_a(data, 1);
}

void	size_4(t_data *data)
{
	ft_index(data);
	push_min(data);
	if (!is_sorted(data->a))
		size_3(data);
	ft_push_a(data, 1);
}

void	size_5(t_data *data)
{
	ft_index(data);
	push_min(data);
	ft_index(data);
	push_min(data);
	if (!is_sorted(data->a))
		size_3(data);
	ft_push_a(data, 1);
	ft_push_a(data, 1);
}

void	radix_sort(t_data *data)
{
	int	i;
	int	j;
	int	size;
	int	max_bits;

	ft_index(data);
	max_bits = get_bits(data);
	i = 0;
	while (i < max_bits)
	{
		size = ft_lstsize(data->a);
		j = 0;
		while (j < size)
		{
			if (((data->a->index >> i) & 1) == 0)
				ft_push_b(data, 1);
			else
				ft_rotate_a(data, 1);
			j++;
		}
		while (data->b)
			ft_push_a(data, 1);
		i++;
	}
}
