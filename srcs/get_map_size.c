/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_size.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakitaha <sakitaha@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 15:54:48 by sakitaha          #+#    #+#             */
/*   Updated: 2023/12/22 01:53:30 by sakitaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/**
 * Counts the number of elements in a line split by spaces.
 * Used to determine the number of columns (max_x) in the map.
 */

static size_t	count_max_x(char *line)
{
	char	**split_line;
	size_t	index;

	split_line = ft_split(line, ' ');
	if (!split_line)
	{
		return (0);
	}
	index = 0;
	while (split_line[index])
	{
		free(split_line[index]);
		index++;
	}
	free(split_line);
	return (index);
}

/**
 * Counts the number of valid lines in the file, using the count_max_x function
 * to ensure each line has the same number of elements.
 * Used to determine the number of rows (max_y) in the map.
 */

static size_t	count_max_y(t_gnl_res res, size_t max_x, int fd)
{
	size_t	index;

	index = 0;
	while (res.line && res.line_status != LINE_ERROR)
	{
		if (res.line[0] == '\n' || res.line[0] == '\0')
		{
			free(res.line);
			break ;
		}
		if (count_max_x(res.line) != max_x)
		{
			free(res.line);
			return (0);
		}
		index++;
		free(res.line);
		res = get_next_line(fd);
	}
	if (res.line_status == LINE_ERROR)
	{
		free(res.line);
		return (0);
	}
	return (index);
}

/**
 * Determines the size of the map by counting the number of rows and columns.
 * Opens the file, reads lines using get_next_line, and uses count_max_x and
 * count_max_y to set the max_x and max_y in the env structure.
 */

void	get_map_size(const char *filename, t_env *env)
{
	int			fd;
	t_gnl_res	res;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		perror_exit(ERR_FILE_OPEN);
	}
	res = get_next_line(fd);
	if (res.line_status == LINE_ERROR || res.line == NULL)
	{
		close(fd);
		print_error_exit(ERR_READ_LINE);
	}
	env->max_x = count_max_x(res.line);
	env->max_y = count_max_y(res, env->max_x, fd);
	close(fd);
	if (env->max_x == 0 || env->max_y == 0)
	{
		print_error_exit(ERR_MAP);
	}
}
