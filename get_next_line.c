/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baalbane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/26 16:58:42 by baalbane          #+#    #+#             */
/*   Updated: 2016/08/19 16:31:47 by baalbane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft/libft.h"

char	**tabmalloc(char **buffer, int fd)
{
	int			i;
	char		**new;

	i = -1;
	new = (char **)malloc(sizeof(char *) * (fd + 2));
	while (buffer[++i] != NULL)
		new[i] = buffer[i];
	while (i <= fd)
	{
		new[i] = (char *)malloc(sizeof(char));
		new[i++][0] = '\0';
	}
	new[i] = NULL;
	free(buffer);
	return (new);
}

char	**testbuffer(char **buffer, int fd)
{
	int			i;

	i = 0;
	if (!buffer)
	{
		buffer = (char **)malloc(sizeof(char *));
		buffer[0] = NULL;
		buffer = tabmalloc(buffer, fd);
	}
	else
	{
		while (buffer[i] != NULL && i < fd)
			i++;
		if (i < fd || buffer[i] == NULL)
			buffer = tabmalloc(buffer, fd);
	}
	return (buffer);
}

int		newbuffer(int const fd, char **buffer, int *ret)
{
	char		new[BUFF_SIZE + 1];
	char		*ptr;
	//char		*new;

	//new = malloc(sizeof(char) * (BUFF_SIZE + 1));
	ptr = *buffer;
	*ret = read(fd, new, BUFF_SIZE);

	new[*ret] = '\0';
	*buffer = ft_strjoin(*buffer, new);
	free(ptr);
	//free(new);
	return (1);
}

int		saveline(int const fd, char **line, char **buffer, char *cursor)
{
	*cursor = '\0';
	*line = ft_strdup(buffer[fd]);
	ft_memmove(buffer[fd], (cursor + 1), (ft_strlen(cursor + 1) + 1));
	return (1);
}

int		get_next_line(int const fd, char **line)
{
	int			ret;
	static char	**buffer;
	char		*cursor;

	if (fd < 0 || !line)
		return (-1);
	ret = 1;
	buffer = testbuffer(buffer, fd);
	while (ret > 0)
	{
		if ((cursor = ft_strchr(buffer[fd], '\n')) != NULL)
			return (saveline(fd, line, buffer, cursor));
		newbuffer(fd, &buffer[fd], &ret);
	}
	if ((cursor = ft_strchr(buffer[fd], '\0')) != buffer[fd])
		return(saveline(fd, line, buffer, cursor));
	return (ret);
}
