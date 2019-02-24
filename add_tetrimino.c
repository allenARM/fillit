/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_tetrimino.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelikia <amelikia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 14:07:55 by amelikia          #+#    #+#             */
/*   Updated: 2018/10/24 14:08:05 by amelikia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_tetrimino		*add_tetrimino(t_tetrimino *list, char *str)
{
	char		**data;
	t_tetrimino	*new;
	t_tetrimino	*temp;

	data = ft_strsplit(str, '\n');
	if (list == NULL)
	{
		list = malloc(sizeof(t_tetrimino));
		list->piece = data;
		list->next = NULL;
		list->symbol = 'A';
		return (list);
	}
	temp = list;
	new = malloc(sizeof(t_tetrimino));
	new->piece = data;
	new->next = NULL;
	while (temp->next)
		temp = temp->next;
	temp->next = new;
	new->symbol = temp->symbol + 1;
	return (list);
}
