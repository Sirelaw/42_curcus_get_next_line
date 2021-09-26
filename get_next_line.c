/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oipadeol <oipadeol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 13:30:38 by oipadeol          #+#    #+#             */
/*   Updated: 2021/09/26 11:54:32 by oipadeol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*get_next_line(int fd)
{
	char		*read_buf;		// Buffer allocated for reading with size of given buffer size. malloc
	char		*temp;			// Used to hold address of line_buf before freeing.
	static char	*temp_buf;		// Holds content of read_buff after /n is found. malloc
	char		*temp_add;		// Used to addresses of line_buf before freeing.
	char		*line_buf;		// Holds content of all calls to read until a \n is found.
	int			flag;			// Used to signify a /n has been found.

	if (BUFFER_SIZE == 0)
		return (NULL);
	read_buf = (char *)malloc(BUFFER_SIZE);
	if (read_buf == NULL)
		return (NULL);
	line_buf = (char *)malloc(1);
	if (line_buf == NULL)
		return (NULL);
	line_buf[0] = '\0';
	flag = 0;
	if (temp_buf != NULL)
	{
		temp = ft_memchr(temp_buf, '\n', ft_strlen(temp_buf));
		if (*temp)
		{
			line_buf = fp_strjoin(line_buf, temp_buf, (temp - temp_buf + 1));
			if (!line_buf)
				return (NULL);
			printf("%s:	%p\n", "Free temp_buff", temp_buf);
			free(temp_buf);
			temp_buf = ft_strdup(temp + 1);
			printf("%s:	%p\n", temp_buf, temp_buf);
			return (line_buf);
		}
		line_buf = fp_strjoin(line_buf, temp_buf, ft_strlen(temp_buf));
		free(temp_buf);
		temp_buf = NULL;
	}
	while (flag == 0)
	{			
		read(fd, read_buf, BUFFER_SIZE);
		if (read_buf == NULL)
			return (NULL);
		temp = ft_memchr(read_buf, '\n', BUFFER_SIZE);
		if (temp)
		{
			flag = 1;
			temp_buf = (char *)malloc(&(read_buf[BUFFER_SIZE]) - temp + 1);
			//printf("%s:	%p\n", "Allocate temp_buff", temp_buf);
			if (temp_buf == NULL)
				return (NULL);
			ft_strlcpy(temp_buf, temp + 1, (&(read_buf[BUFFER_SIZE]) - temp + 1));
		}
		temp_add = line_buf;
		if (flag == 1)
			line_buf = fp_strjoin(line_buf, read_buf, temp - read_buf + 1);
		if (flag == 0)
			line_buf = fp_strjoin(line_buf, read_buf, BUFFER_SIZE);
		if (line_buf == NULL)
			return (NULL);
		free(temp_add);
	}
	return (line_buf);
}
