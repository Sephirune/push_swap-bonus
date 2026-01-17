/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarogarc <aarogarc@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 12:35:52 by aarogarc          #+#    #+#             */
/*   Updated: 2026/01/15 12:35:54 by aarogarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}

void	check_operation(t_data *data, char *operation)
{
	if (ft_strcmp(operation, "sa\n") == 0)
		ft_swap_a(data, 0);
	else if (ft_strcmp(operation, "sb\n") == 0)
		ft_swap_b(data, 0);
	else if (ft_strcmp(operation, "ss\n") == 0)
		ft_swap_ab(data);
	else if (ft_strcmp(operation, "pa\n") == 0)
		ft_push_a(data, 0);
	else if (ft_strcmp(operation, "pb\n") == 0)
		ft_push_b(data, 0);
	else if (ft_strcmp(operation, "ra\n") == 0)
		ft_rotate_a(data, 0);
	else if (ft_strcmp(operation, "rb\n") == 0)
		ft_rotate_b(data, 0);
	else if (ft_strcmp(operation, "rr\n") == 0)
		ft_rr(data);
	else if (ft_strcmp(operation, "rra\n") == 0)
		ft_reverse_a(data, 0);
	else if (ft_strcmp(operation, "rrb\n") == 0)
		ft_reverse_b(data, 0);
	else if (ft_strcmp(operation, "rrr\n") == 0)
		ft_rrr(data);
	else
		check_error_free(data);
}

void	read_execute(t_data *data)
{
	char	*line;

	line = get_next_line(0);
	while (line)
	{
		check_operation(data, line);
		free(line);
		line = get_next_line(0);
	}
}

int	main(int argc, char **argv)
{
	t_data	data;

	data.a = NULL;
	data.b = NULL;
	data.moves = 0;
	parse_args(&data, argc, argv);
	if (!data.a)
		return (0);
	read_execute(&data);
	if (is_sorted(data.a) && !data.b)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	free_list(&data.a);
	free_list(&data.b);
	return (0);
}
