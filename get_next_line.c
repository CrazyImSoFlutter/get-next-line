/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoh <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 09:28:57 by hnoh              #+#    #+#             */
/*   Updated: 2021/01/18 10:41:46 by hnoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int 	get_next_line(int fd, char **line)
{
	static char		*backup_buf[OPEN_MAX];
	char			buf[BUFFERSIZE + 1];
	int				read_size;
	int				cut;

	if ((fd < 0) || (line == 0) || (BUFFER_SIZE <= 0) )
		return (-1);
	while ((read_size = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[read_size] = '\0';
		backup_buf[fd] = fd_strjoin(backup[fd], buf);
		if ((cut = is_newline(backup[fd]) >= 0))
			return (split_line(&backup[fd], line, cut));
	}
	return (return_all(&backup[fd], line, read_size));
}
