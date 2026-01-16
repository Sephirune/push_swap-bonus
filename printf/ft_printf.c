/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarogarc <aarogarc@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 13:28:01 by aarogarc          #+#    #+#             */
/*   Updated: 2025/11/14 13:41:13 by aarogarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

static int	parse_types(char type, va_list arg)
{
	if (type == 'c')
		return (ft_putchar(va_arg(arg, int)));
	else if (type == 's')
		return (ft_putstr(va_arg(arg, char *)));
	else if (type == 'p')
		return (ft_putptrnull(va_arg(arg, void *)));
	else if (type == 'd')
		return (ft_putnbr(va_arg(arg, int)));
	else if (type == 'i')
		return (ft_putnbr(va_arg(arg, int)));
	else if (type == 'u')
		return (ft_putunbr(va_arg(arg, unsigned int)));
	else if (type == 'x')
		return (ft_hexnbr(va_arg(arg, unsigned int), 0));
	else if (type == 'X')
		return (ft_hexnbr(va_arg(arg, unsigned int), 1));
	else if (type == '%')
		return (ft_putchar('%'));
	return (0);
}

int	ft_printf(const char *str, ...)
{
	size_t	i;
	size_t	len;
	va_list	args;

	va_start(args, str);
	i = 0;
	len = 0;
	while (str[i])
	{
		if (str[i] == '%')
			len += parse_types(str[++i], args);
		else
			len += ft_putchar(str[i]);
		i++;
	}
	va_end(args);
	return (len);
}

/* #include <stdio.h>
int main(void)
{
	int x = 0;
	int *p = &x;
	ft_printf("%c\n", 'a');
	printf("%c\n", 'a');
	ft_printf("%s\n", "pepe");
	printf("%s\n", "pepe");
	ft_printf("%d\n", 13);
	printf("%d\n", 13);
	ft_printf("%p\n", p);
	printf("%p\n", p);
	ft_printf("%i\n", -14);
	printf("%i\n", -14);
	ft_printf("%u\n", 15);
	printf("%u\n", 15);
	ft_printf("%x\n", 'd');
	printf("%x\n", 'd');
	ft_printf("%X\n", 'D');
	printf("%X\n", 'D');
	ft_printf("%%\n");
	printf("%%\n");
} */
