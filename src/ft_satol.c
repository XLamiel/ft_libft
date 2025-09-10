/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_satol.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlamiel- <xlamiel-@student.42barcelona.com>+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 20:17:55 by xlamiel-          #+#    #+#             */
/*   Updated: 2025/09/10 21:52:43 by xlamiel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>

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


/* Definición de códigos de error
#define ATOL_SUCCESS 0
#define ATOL_OVERFLOW 1
#define ATOL_INVALID_CHAR 2
#define ATOL_NO_DIGITS 3
#define ATOL_EMPTY_STRING 4
*/

typedef struct s_atol
{
	long	value;
	int		error;
}	t_atol;

// Función optimizada para verificar espacios
int	ft_isspace(char c)
{
	return (c == ' ' || c == '\t' || c == '\n' ||
			c == '\v' || c == '\f' || c == '\r');
}

// Función para verificar overflow
static int	check_overflow(long current, char next_digit, long sign)
{
	int	digit_value;

	digit_value = next_digit - '0';

	if (sign == 1)
	{
		if (current > LONG_MAX / 10)
			return (1);
		if (current == LONG_MAX / 10 && digit_value > LONG_MAX % 10)
			return (1);
	}
	else
	{
		if (current > -(LONG_MIN / 10))
			return (1);
		if (current == -(LONG_MIN / 10) && digit_value > -(LONG_MIN % 10))
			return (1);
	}
	return (0);
}

// Función principal modo estricto
t_atol	ft_satol_strict(const char *str)
{
	t_atol	result;
	long	sign;
	size_t	i;
	int		has_digits;

	result.value = 0;
	result.error = ATOL_SUCCESS;
	sign = 1;
	i = 0;
	has_digits = 0;

	// Verificar string vacía
	if (str[i] == '\0')
	{
		result.error = ATOL_EMPTY_STRING;
		return (result);
	}

	// Saltar espacios iniciales
	while (ft_isspace(str[i]))
		i++;

	// Procesar signo
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}

	// Verificar que hay al menos un dígito después del signo
	if (!ft_isdigit(str[i]))
	{
		result.error = ATOL_NO_DIGITS;
		return (result);
	}

	// Convertir dígitos
	while (ft_isdigit(str[i]))
	{
		has_digits = 1;

		// Verificar overflow
		if (check_overflow(result.value, str[i], sign))
		{
			result.error = ATOL_OVERFLOW;
			result.value = (sign == 1) ? LONG_MAX : LONG_MIN;
			return (result);
		}

		result.value = result.value * 10 + (str[i] - '0');
		i++;
	}

	// Modo ESTRICTO: después de los dígitos debe ser el final
	if (str[i] != '\0')
	{
		result.error = ATOL_INVALID_CHAR;
		result.value = 0;
		return (result);
	}

	// Verificar que al menos hubo un dígito (por si acaso)
	if (!has_digits)
	{
		result.error = ATOL_NO_DIGITS;
		return (result);
	}

	result.value *= sign;
	return (result);
}
