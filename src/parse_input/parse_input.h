/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-alme <pde-alme@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/17 18:04:15 by pde-alme          #+#    #+#             */
/*   Updated: 2026/04/26 23:03:09 by pde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_INPUT_H
# define PARSE_INPUT_H

# include <unistd.h>
# include "../../libft/libft.h"

int	parse_input(int argc, char **argv);
int	parse_input_argc(int argc);
int	parse_input_file_extension(char **argv);
int	parse_input_valid_file(char **argv);
int	parse_input_line(int fd, int map_mode);
int	parse_input_orientation(int fd, char *element);
int	parse_input_color(int fd, char *element);
int	parse_input_map_found(int fd);
int	parse_input_map_whole(int fd);
int	parse_input_map_player(int fd);
size_t	parse_input_map_width(int fd);
size_t	parse_input_map_height(int fd);

/* Utils functions */
int	open_file(char **argv);
int	check_if_element(char *line);

#endif
