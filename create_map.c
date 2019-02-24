/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelikia <amelikia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 13:47:22 by amelikia          #+#    #+#             */
/*   Updated: 2018/10/24 13:47:52 by amelikia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char		**create_map(int size)
{
	char	**map;
	int		i;
	int		j;

	map = (char **)malloc(sizeof(char *) * (size + 1));
	i = 0;
	while (i < size)
	{
		map[i] = (char *)malloc(sizeof(char) * (size + 1));
		j = 0;
		while (j < size)
		{
			map[i][j] = '.';
			++j;
		}
		map[i][j] = '\0';
		++i;
	}
	map[i] = NULL;
	return (map);
}
