/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarogarc <aarogarc@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 18:40:51 by aarogarc          #+#    #+#             */
/*   Updated: 2025/11/14 19:05:01 by aarogarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_hexnbr(unsigned long hex, int capdecimal)
{
	size_t	len;
	char	*str;

	len = 0;
	if (capdecimal)
		str = "0123456789ABCDEF";
	else
		str = "0123456789abcdef";
	if (hex >= 16)
		len += ft_hexnbr(hex / 16, capdecimal);
	len += ft_putchar(str[hex % 16]);
	return (len);
}
