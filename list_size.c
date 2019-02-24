/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_size.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelikia <amelikia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 13:40:32 by amelikia          #+#    #+#             */
/*   Updated: 2018/10/24 13:41:28 by amelikia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		list_size(t_tetrimino *list)
{
	int			i;
	t_tetrimino	*temp;

	i = 0;
	temp = list;
	while (temp)
	{
		temp = temp->next;
		++i;
	}
	return (i);
}
