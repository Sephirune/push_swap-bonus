/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarogarc <aarogarc@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/23 11:54:39 by aarogarc          #+#    #+#             */
/*   Updated: 2025/12/23 11:54:41 by aarogarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	free_split(char **split)
{
	int	i;

	if (!split)
		return ;
	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free (split);
}

void	check_error(void)
{
	write(2, "Error\n", 6);
	exit (1);
}

int	find_min(t_list *pack)
{
	t_list	*current;
	int		pos;
	int		min_pos;
	int		min_index;

	if (!pack)
		check_error();
	current = pack;
	pos = 0;
	min_pos = 0;
	min_index = current->index;
	while (current)
	{
		if (current->index < min_index)
		{
			min_index = current->index;
			min_pos = pos;
		}
		pos++;
		current = current->next;
	}
	return (min_pos);
}

void	push_min(t_data *data)
{
	int	pos;
	int	size;
	int	aux;

	pos = find_min(data->a);
	size = ft_lstsize(data->a);
	if (pos <= size / 2)
	{
		while (pos > 0)
		{
			ft_rotate_a(data, 1);
			pos--;
		}
	}
	else
	{
		aux = size - pos;
		while (aux > 0)
		{
			ft_reverse_a(data, 1);
			aux--;
		}
	}
	ft_push_b(data, 1);
}

int	get_bits(t_data *data)
{
	int		max_index;
	int		bits;
	t_list	*current;

	current = data->a;
	max_index = 0;
	bits = 0;
	while (current)
	{
		if (current->index > max_index)
			max_index = current->index;
		current = current->next;
	}
	while ((max_index >> bits) != 0)
		bits++;
	return (bits);
}
