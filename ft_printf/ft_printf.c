/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygoksu <ygoksu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 20:34:01 by ygoksu            #+#    #+#             */
/*   Updated: 2022/03/09 19:42:16 by ygoksu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_bas_say(unsigned int c)
{
	int	i;

	i = 1;
	while (c >= 10)
	{
		c /= 10;
		i++;
	}
	return (i);
}

int	array_print(char *str)
{
	int	len;

	len = 0;
	if (!str)
		return (array_print("(null)"));
	while (str[len])
		len += ft_putchar_v2(str[len]);
	return (len);
}

int	ft_uitoa(unsigned int a)
{
	int		len;
	char	*str;

	len = ft_bas_say(a);
	str = (char *)malloc(sizeof(char) * (len + 1));
	str[len] = '\0';
	while (len > 0)
	{
		str[len - 1] = a % 10 + 48;
		a /= 10;
		len--;
	}
	len = array_print(str);
	free(str);
	return (len);
}

int	ft_strchecker(va_list arg, int g)
{
	char	*a;
	int		len;

	len = 0;
	if (g == 'c')
		len += ft_putchar_v2(va_arg(arg, int));
	if (g == 's')
		len += array_print(va_arg(arg, char *));
	if (g == 'p')
		len += ptr_print(va_arg(arg, unsigned long));
	if (g == 'd' || g == 'i')
	{
		a = ft_itoa(va_arg(arg, int));
		len += array_print(a);
		free(a);
	}
	if (g == 'u')
		len += ft_uitoa(va_arg(arg, unsigned int));
	if (g == 'x' || g == 'X')
		len += hex_print(va_arg(arg, unsigned int), g);
	if (g == '%')
		len += ft_putchar_v2('%');
	return (len);
}

int	ft_printf(const char *str, ...)
{
	va_list	arg;
	int		len;
	int		i;

	va_start(arg, str);
	i = 0;
	len = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			len += ft_strchecker(arg, str[i]);
		}
		else
		{
			ft_putchar_fd(str[i], 1);
			len++;
		}
		i++;
	}
	va_end(arg);
	return (len);
}
