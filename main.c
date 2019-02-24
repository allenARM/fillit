/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knaumov <knaumov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/19 09:10:42 by knaumov           #+#    #+#             */
/*   Updated: 2018/10/24 13:39:57 by amelikia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int				minimal_square(int n)
{
	int		size;

	n = n * 4;
	size = 2;
	while (size * size < n)
		size++;
	return (size);
}

t_tetrimino		*fillit_check(char *file)
{
	int			fd;
	t_tetrimino	*list;

	list = NULL;
	fd = open(file, O_RDWR);
	if (fd == -1)
		return (NULL);
	if ((list = input_check(fd, list)) == NULL)
		return (NULL);
	if (check_for_tetriminos(list) == -1)
		return (NULL);
	close(fd);
	return (list);
}

int				main(int argc, char **argv)
{
	t_tetrimino		*list;
	int				size;
	char			**map;

	if (argc == 2)
	{
		if ((list = fillit_check(argv[1])) == NULL)
		{
			ft_putstr("error\n");
			return (-1);
		}
		list = cleaning_launcher(list);
		size = minimal_square(list_size(list));
		map = create_map(size);
		while (algorithm(map, list) == 0)
			map = create_map(++size);
		display_solution(map);
	}
	else
		ft_putstr("usage: ./fillit [file]\n");
	return (0);
}
