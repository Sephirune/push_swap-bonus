/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptrnull.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarogarc <aarogarc@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 09:41:59 by aarogarc          #+#    #+#             */
/*   Updated: 2025/11/17 10:04:06 by aarogarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_putptrnull(void *ptr)
{
	int				len;
	unsigned long	ptro;

	if (!ptr)
		return (ft_putstr("(nil)"));
	len = 0;
	ptro = (unsigned long)ptr;
	len += ft_putstr("0x");
	len += ft_hexnbr(ptro, 0);
	return (len);
}
