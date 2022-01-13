/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_atoi.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbathe <bbathe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 18:26:15 by bbathe            #+#    #+#             */
/*   Updated: 2021/10/08 15:24:59 by bbathe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

int	if_number(char *s)
{
	int	i;

	i = 0;
	if (s[i] == '+' || s[i] == '-')
		i++;
	while (s[i] && s[i] != '.')
	{
		if ((s[i] < '0' || s[i] > '9') && s[i] != '.')
			return (0);
		i++;
	}
	if (s[i] == '.')
	{
		i++;
		if (s[i] < '0' || s[i] > '9')
			return (0);
	}
	while (s[i])
	{
		if (s[i] < '0' || s[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

int	ft_pow(int a, int n)
{
	int	i;
	int	res;

	i = 0;
	res = 1;
	while (i < n)
	{
		res = res * a;
		i++;
	}
	return (res);
}

double	double_atoi(char *str)
{
	int		i;
	double	res;
	int		sg;
	int		k;

	i = 0;
	res = 0;
	sg = 1;
	k = 1;
	if (str[i] == '+')
		i++;
	else if (str[i] == '-')
	{
		sg = -1;
		i++;
	}
	while (str[i] && str[i] != '.')
		res = res * 10 + str[i++] - 48;
	if (str[i] == '.')
		i++;
	while (str[i])
		res = res + (str[i++] - 48) / (double) ft_pow(10, k++);
	return (sg * res);
}
