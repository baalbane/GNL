/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baalbane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/26 17:07:29 by baalbane          #+#    #+#             */
/*   Updated: 2016/08/19 16:03:22 by baalbane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include "libft/libft.h"
# include <stdlib.h>
# include <unistd.h>

# define BUFF_SIZE 1

int		newbuffer(int const fd, char **buffer, int *ret);
int		get_next_line(int const fd, char **line);
char	**tabmalloc(char **buffer, int fd);
char	**testbuffer(char **buffer, int fd);

#endif
