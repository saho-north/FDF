/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakitaha <sakitaha@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 17:45:00 by sakitaha          #+#    #+#             */
/*   Updated: 2023/12/21 16:28:09 by sakitaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H

# define ERR_ARG "Usage: ./fdf <file_name>.fdf"
# define ERR_FILE_OPEN "Error: Failed to open file"
# define ERR_READ_LINE "Error: Failed to read line"
# define ERR_MAP "Error: Invalid map"
# define ERR_MALLOC "Error: Failed to allocate memory"

// Below are not edited yet
# define ERR_MAP_READING "Reading error"
# define ERR_MAP_INIT "Map initialization error"
# define ERR_FDF_INIT "FdF initialization error"
# define ERR_CONV_TO_ARR "Conversion to array"
# define ERR_CAMERA_INIT "Camera initialization error"

void	print_error_exit(char *message);
void	perror_exit(char *message);

#endif
