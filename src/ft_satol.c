/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_satol.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlamiel- <xlamiel-@student.42barcelona.com>+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 20:17:55 by xlamiel-          #+#    #+#             */
/*   Updated: 2025/09/10 21:19:15 by xlamiel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isspace(char c)
{
	if (c == ' ')
		return (c == ' ');
	if (c == '\t')
		return (c == '\t');
	if (c == '\n')
		return (c == '\n');
	if (c == '\v')
		return (c == '\v');
	if (c == '\f')
		return (c == '\f');
	if (c == '\r')
		return (c == '\r');
	return (0);
}
size_t	skip_spaces(const char *str)
{
	size_t	i;

	i = 0;
	while (ft_isspace(str[i]))
		i++;
	return (i);
}

// Función para procesar el signo
long	process_sign(const char *str, size_t *i)
{
	long	sign;

	sign = 1;
	if (str[*i] == '-' || str[*i] == '+')
	{
		if (str[*i] == '-')
			sign = -1;
		(*i)++;
	}
	return (sign);
}

// Función para convertir dígitos con verificación de overflow
t_atol	convert_digits(const char *str, size_t i, long sign)
{
	t_atol	result;
	int		digit_value;

	result.value = 0;
	result.error = 0;
	while (ft_isdigit(str[i]))
	{
		digit_value = str[i] - '0';
		if (sign == 1 && (result.value > LONG_MAX / 10 || 
			(result.value == LONG_MAX / 10 && digit_value > LONG_MAX % 10)))
		{
			result.error = 1;
			result.value = LONG_MAX;
			return (result);
		}
		if (sign == -1 && (result.value > -(LONG_MIN / 10) || 
			(result.value == -(LONG_MIN / 10) && digit_value > -(LONG_MIN % 10))))
		{
			result.error = 1;
			result.value = LONG_MIN;
			return (result);
		}
		result.value = result.value * 10 + digit_value;
		i++;
	}
	result.value *= sign;
	return (result);
}

// Función principal ft_satol
t_atol	ft_satol(const char *str)
{
	t_atol	result;
	size_t	i;
	long	sign;

	result.value = 0;
	result.error = 0;
	i = skip_spaces(str);
	sign = process_sign(str, &i);
	result = convert_digits(str, i, sign);
	return (result);
}
