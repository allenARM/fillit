/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knaumov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/21 14:08:48 by knaumov           #+#    #+#             */
/*   Updated: 2018/10/03 16:54:21 by knaumov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_abs(int nb)
{
	if (nb < 0)
		nb = -nb;
	return (nb);
}

static char		*itoa_filler(char *tab, int value, int flag)
{
	int			tmp;
	int			size;
	char		*str;

	size = 0;
	tmp = ft_abs(value);
	while (tmp /= 10)
		size++;
	size = size + flag + 1;
	str = (char *)malloc(sizeof(char) * size + 1);
	if (str == NULL)
		return (NULL);
	str[size] = '\0';
	if (flag == 1)
		str[0] = '-';
	while (size > flag)
	{
		str[size - 1] = tab[ft_abs(value % 10)];
		size--;
		value = value / 10;
	}
	return (str);
}

char			*ft_itoa(int value)
{
	char		*str;
	char		*tab;
	int			flag;

	flag = 0;
	tab = "0123456789abcdef";
	if (value < 0)
		flag = 1;
	str = itoa_filler(tab, value, flag);
	return (str);
}
