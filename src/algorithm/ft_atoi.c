/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarogarc <aarogarc@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 11:07:58 by aarogarc          #+#    #+#             */
/*   Updated: 2025/12/17 11:08:10 by aarogarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	is_space(const char *str, int *i)
{
	while (str[*i] == 32 || (str[*i] >= 9 && str[*i] <= 13))
		(*i)++;
}

int	check_sign(const char *str, int *i)
{
	int	sign;

	sign = 1;
	if (str[*i] == '+' || str[*i] == '-')
	{
		if (str[*i] == '-')
			sign *= -1;
		(*i)++;
	}
	return (sign);
}

void	check_overflow(long number, int sign)
{
	if (number * sign > __INT_MAX__ || (number * sign < -2147483648))
		check_error();
}

int	check_args(const char *str)
{
	int	i;
	int	digit;

	i = 0;
	digit = 0;
	is_space(str, &i);
	if (str[i] == '+' || str[i] == '-')
		i++;
	if (str[i] < '0' || str[i] > '9')
		return (0);
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
			digit = 1;
		else if (str[i] != ' ' && !(str[i] >= 9 && str[i] <= 13))
			return (0);
		else if (digit && (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13)))
			return (0);
		i++;
	}
	return (digit);
}

int	ft_atoi(const char *str)
{
	long	number;
	int		sign;
	int		i;

	i = 0;
	number = 0;
	if (!check_args(str))
		check_error();
	is_space(str, &i);
	sign = check_sign(str, &i);
	while (str[i] >= '0' && str[i] <= '9')
	{
		number = (number * 10) + (str[i] - '0');
		check_overflow(number, sign);
		i++;
	}
	return (number * sign);
}
