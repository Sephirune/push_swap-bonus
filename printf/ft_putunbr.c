/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarogarc <aarogarc@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 13:43:41 by aarogarc          #+#    #+#             */
/*   Updated: 2025/11/17 13:46:26 by aarogarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_putunbr(unsigned int n)
{
	int	len;

	len = 0;
	if (n > 9)
		len += ft_putunbr(n / 10);
	len += ft_putchar((n % 10) + '0');
	return (len);
}
