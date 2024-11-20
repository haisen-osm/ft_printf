/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okhourss <okhourss@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 12:30:58 by okhourss          #+#    #+#             */
/*   Updated: 2024/11/20 16:46:50 by okhourss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *str, ...)
{
	int		i;
	va_list	args;
	int		count;

	count = 0;
	i = 0;
	if (str == NULL || write(1, 0, 0) == -1)
		return (-1);
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			count += ft_check_specifier(str[i], args);
		}
		else
			count += ft_putchar(str[i]);
		i++;
	}
	va_end(args);
	if (count < 0)
		return (-1);
	return (count);
}
