/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baalbane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/26 17:07:29 by baalbane          #+#    #+#             */
/*   Updated: 2016/07/18 18:35:29 by baalbane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include "libft/libft.h"
# include <stdlib.h>
# include <unistd.h>

#include <stdio.h> //serhaerhaesrhg

# define BUFF_SIZE 9

typedef	struct		s_buf
{
	char			**buffer;
	int				*tabid;
}					t_buf;

char	*newbuffer(int const fd, char *buffer, int *ret);
int		get_next_line(int const fd, char **line);
char	**tabmalloc(t_buf *data, int fd);
int		testbuffer(t_buf *data, int fd);

#endif
