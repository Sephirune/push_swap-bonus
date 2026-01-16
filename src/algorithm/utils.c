/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarogarc <aarogarc@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 09:58:14 by aarogarc          #+#    #+#             */
/*   Updated: 2025/12/17 09:58:19 by aarogarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

int	ft_print_ints(char *str, int *count)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
		(*count)++;
	}
	return (*count);
}

void	ft_index(t_data *data)
{
	t_list	*current;
	t_list	*cmp;
	int		index;

	current = data->a;
	while (current)
	{
		index = 0;
		cmp = data->a;
		while (cmp)
		{
			if (cmp->nb < current->nb)
				index++;
			cmp = cmp->next;
		}
		current->index = index;
		current = current->next;
	}
}

int	is_sorted(t_list *pack)
{
	t_list	*current;

	current = pack;
	while (current && current->next)
	{
		if (current->nb > current->next->nb)
			return (0);
		current = current->next;
	}
	return (1);
}

int	check_duplicate(t_data *data, int vatoi)
{
	t_list	*current;

	current = data->a;
	while (current)
	{
		if (current->nb == vatoi)
			return (1);
		current = current->next;
	}
	return (0);
}

void	parse_args(t_data *data, int argc, char **argv)
{
	int		i;
	char	**split;

	i = 1;
	while (i < argc)
	{
		split = ft_split(argv[i], ' ');
		if (!split || !split[0])
		{
			free_split(split);
			check_error_free(data);
		}
		aux_split(data, split);
		free_split(split);
		i++;
	}
}
