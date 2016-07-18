/* ************************************************************************** */
/*                                                                            */
/*   main.c                                                                   */
/*                                                                            */
/*   By: baalbane <marvin@42.fr>                                              */
/*                                                                            */
/*   Created: 2016/07/12                                                      */
/*                                                                            */
/* ************************************************************************** */

# include <stdio.h>
# include <fcntl.h>

#include "get_next_line.h"

int	main(int ac, char **av)
{
	char	*str;
	int fd = open(av[1], O_RDONLY);
	while(get_next_line(fd, &str))
		printf("%s\n", str);

}
