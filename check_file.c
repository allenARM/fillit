/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelikia <amelikia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 14:17:42 by amelikia          #+#    #+#             */
/*   Updated: 2018/10/24 14:54:34 by amelikia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			check_number_of_hashtags(int *count_hashtags, char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] != '#' && line[i] != '.' && line[i] != '\n')
			return (-1);
		if (line[i] == '#')
			++*count_hashtags;
		if (*count_hashtags > 4)
			return (-1);
		++i;
	}
	return (0);
}

int			check_number_of_lines(int *count_lines,
	int *count_hashtags, char *line)
{
	if (*count_lines != 4)
	{
		if (ft_strlen(line) != 4)
			return (-1);
	}
	if (*count_lines == 4)
	{
		*count_lines = -1;
		*count_hashtags = 0;
		if (ft_strcmp(line, "") != 0)
			return (-1);
	}
	*count_lines = *count_lines + 1;
	return (0);
}

void		adding_to_list(char **input, char **line, int count_lines,
	t_tetrimino **list)
{
	char			*tmp;

	tmp = ft_strjoin(*input, *line);
	*input = tmp;
	if (ft_strcmp(*line, "") != 0)
	{
		tmp = ft_strjoin(*input, "\n");
		free(*input);
		*input = tmp;
	}
	if (count_lines == 4)
	{
		*list = add_tetrimino(*list, *input);
		ft_strdel(input);
		*input = ft_strnew(1);
	}
	ft_strdel(line);
}

t_tetrimino	*input_check(const int fd, t_tetrimino *list)
{
	char			*line;
	char			*input;
	int				count_lines;
	int				count_hashtags;

	count_lines = 0;
	count_hashtags = 0;
	input = ft_strnew(1);
	list = NULL;
	while (get_next_line(fd, &line) == 1)
	{
		if (check_number_of_lines(&count_lines, &count_hashtags, line) == -1 ||\
						check_number_of_hashtags(&count_hashtags, line) == -1)
			return (NULL);
		adding_to_list(&input, &line, count_lines, &list);
	}
	if (count_lines != 4)
		return (NULL);
	return (list);
}
