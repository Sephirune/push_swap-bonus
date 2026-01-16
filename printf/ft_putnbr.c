/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarogarc <aarogarc@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 18:23:42 by aarogarc          #+#    #+#             */
/*   Updated: 2025/11/18 10:50:58 by aarogarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_putnbr(int i)
{
	int			len;
	long int	nb;

	len = 0;
	nb = i;
	if (nb == -2147483648)
		return (ft_putstr("-2147483648"));
	if (nb == 0)
		return (ft_putchar('0'));
	if (nb < 0)
	{
		nb *= -1;
		len += ft_putchar('-');
	}
	if (nb > 9)
		len += ft_putnbr(nb / 10);
	len += ft_putchar((nb % 10) + '0');
	return (len);
}
