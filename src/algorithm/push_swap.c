/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarogarc <aarogarc@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 12:22:32 by aarogarc          #+#    #+#             */
/*   Updated: 2025/11/21 12:22:34 by aarogarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	aux_main(t_data *data, int size)
{
	if (size == 2)
		size_2(data);
	else if (size == 3)
		size_3(data);
	else if (size == 4)
		size_4(data);
	else if (size == 5)
		size_5(data);
	else
		radix_sort(data);
}

int	main(int argc, char **argv)
{
	t_data	data;
	int		size;

	data.a = NULL;
	data.b = NULL;
	data.moves = 0;
	if (argc >= 2)
	{
		parse_args(&data, argc, argv);
		if (!data.a)
			return (0);
		if (is_sorted(data.a))
			return (free_list(&data.a), 0);
		size = ft_lstsize(data.a);
		aux_main(&data, size);
		free_list(&data.a);
		free_list(&data.b);
	}
	return (0);
}
