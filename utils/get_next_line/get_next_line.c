/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lliberal <lliberal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 14:45:03 by lliberal          #+#    #+#             */
/*   Updated: 2023/03/16 18:54:19 by lliberal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_read(int fd, char *buf, char *locker)
{
	char	*tmp;
	int		byte_read;

	byte_read = 1;
	while (byte_read != 0)
	{
		byte_read = read(fd, buf, BUFFER_SIZE);
		if (byte_read == 0)
			break ;
		if (byte_read == -1)
			return (0);
		buf[byte_read] = '\0';
		if (!locker)
			locker = ft_strdup("");
		tmp = locker;
		locker = ft_strjoin(tmp, buf);
		free(tmp);
		tmp = NULL;
		if (ft_strchr(buf, '\n'))
			break ;
	}
	return (locker);
}

char	*ft_put_locked(char *line)
{
	size_t	length;
	int		index_nl;
	char	*locker;

	index_nl = 0;
	length = ft_strlen(line);
	while (line[index_nl] != '\n' && line[index_nl] != '\0')
		index_nl++;
	if (line[index_nl] == '\0' || line[1] == '\0')
		return (0);
	locker = ft_substr(line, index_nl + 1, (length - index_nl));
	if (*locker == '\0')
	{
		free(locker);
		return (NULL);
	}
	line[index_nl + 1] = '\0';
	return (locker);
}

char	*get_next_line(int fd)
{
	static char	*locker;
	char		*buf;
	char		*line;

	if (fd < 0 || read(fd, 0, 0) < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	line = ft_read(fd, buf, locker);
	free(buf);
	buf = NULL;
	if (!line)
		return (NULL);
	locker = ft_put_locked(line);
	return (line);
}

// int	main(void)
// {
// 	int		fd;
// 	char	*gnl;

// 	fd = open("lorem.txt", O_RDONLY);
// 	if (fd == -1)
// 	{
// 		write(1, "Error\n", 1);
// 		return (1);
// 	}
// 	while (fd)
// 	{
// 		gnl = get_next_line(fd);
// 		if (!gnl)
// 			break;
// 		printf("-------MAIN: %s ", gnl);
// 		free(gnl);
// 	}
// 	return (0);
// }
