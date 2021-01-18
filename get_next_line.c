/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoh <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 09:28:57 by hnoh              #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2021/01/18 10:53:15 by hnoh             ###   ########.fr       */
=======
/*   Updated: 2021/01/18 10:41:46 by hnoh             ###   ########.fr       */
>>>>>>> 772feded2024ef1efa7e4db457dd832bc4145808
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

<<<<<<< HEAD
int		is_newline(char *backup)
{
	int				i;

	i = 0;
	while (backup[i])
	{
		if (backup[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

int		split(char **backup, char **line, int cut)
{
	char			*temp;
	int				len;

	(*backup)[cut] = '\0';
	*line = ft_strdup(*backup);
	len = ft_strlen(*backup + cut + 1);
	if (len == 0)
	{
		free(*backup);
		*backup = 0;
		return (1);
	}
	temp = ft_strdup(*backup + cut + 1);
	free(*backup);
	*backup = temp;
	return (1);
}

int		return_all(char **backup, char **line, int read_size)
{
	int				cut;

	if (read_size < 0)
		return (-1);
	if (*backup && (cut = is_newline(*backup)) >= 0)
		return (split(backup, line , cut));
	else if (*backup)
	{
		*line = *backup;
		*backup = 0;
		return (0);
	}
	*line = ft_strdup("");
	return (0);
}

=======
>>>>>>> 772feded2024ef1efa7e4db457dd832bc4145808
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
<<<<<<< HEAD
			return (split(&backup[fd], line, cut));
=======
			return (split_line(&backup[fd], line, cut));
>>>>>>> 772feded2024ef1efa7e4db457dd832bc4145808
	}
	return (return_all(&backup[fd], line, read_size));
}
