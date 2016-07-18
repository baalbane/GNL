/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baalbane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/26 16:58:42 by baalbane          #+#    #+#             */
/*   Updated: 2016/07/18 19:35:20 by baalbane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	**addbuffer(t_buf *data)
{
	int			i;
	char		**new;

	i = 0;
	while(data->tabid[i] != -2)
		i++;
	new = (char **)malloc(sizeof(char *) * (i + 2));
	i = -1;
	while(data->tabid[++i] != -2)
		new[i] = data->buffer[i];
	new[i] = malloc(sizeof(char));
	new[i][0] = '\0';
	if (data->buffer)
		free(data->buffer);
	return(new);
}

int		testbuffer(t_buf *data, int fd)
{
	int			i;
	int			*newtab;

	i = 0;
	if (!data)
	{
		data = malloc(sizeof(t_list));
		data->buffer = NULL;
		data->tabid = malloc(sizeof(int));
		data->tabid[0] = -2;
	}
	while(data->tabid[i] != fd && data->tabid[i] >= 0)
		i++;
	if(data->tabid[i] == -2)
	{
		newtab = malloc(sizeof(int) * (i+2));
		i = -1;
		data->buffer = addbuffer(data);
		while(data->tabid[++i] != -2)
			newtab[i] = data->tabid[i];
		newtab[i] = fd;
		newtab[i+1] = -2;
		free(data->tabid);
		data->tabid = newtab;
	}

	return (i);
}

char	*newbuffer(int const fd, char *buffer, int *ret)
{
	char		new[BUFF_SIZE + 1];

	*ret = read(fd, new, BUFF_SIZE);
	new[*ret] = '\0';
	buffer = ft_strjoin(buffer, new);
	return (buffer);
}

int		saveline(int const fd, char **line, char *buffer, char *cursor)
{

	*cursor = '\0';
	*line = ft_strdup(buffer);
	ft_memmove(buffer, (cursor + 1), (ft_strlen(cursor + 1) + 1));
	return (1);
}

int		get_next_line(int const fd, char **line)
{
	int				ret;
	int				pos;
	static	t_buf	*data;
	char			*cursor;

	if (fd < 0 || line == NULL)
		return (-1);
	ret = 1;
	pos = testbuffer(data, fd);
	//printf("%d==%s\n", pos, data->buffer[pos]);
	while (ret > 0)
	{
	printf("7==\n");
		if ((cursor = ft_strchr(data->buffer[pos], '\n')) != NULL)
		{
	printf("8==\n");
			return (saveline(fd, line, data->buffer[pos], cursor));
		}
	printf("8==\n");
		data->buffer[pos] = newbuffer(fd, data->buffer[pos], &ret);
	printf("%d==\n", fd+1);
	}
	printf("%d==\n", fd);
	if ((cursor = ft_strchr(data->buffer[pos], '\0')) != data->buffer[pos] && ret >= 0)
		return (saveline(fd, line, data->buffer[pos], cursor));
	printf("%d==\n", fd);
	return (ret);
}
