/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarreto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 16:23:42 by mbarreto          #+#    #+#             */
/*   Updated: 2022/02/14 16:23:55 by mbarreto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <string.h>

typedef struct s_hack
{
	int flag;
	char *strcpy;
	int cont;
	int size;

} t_hack;

char	*get_next_line(int fd)
{
	static t_hack h;

	char str[4096];
	char		buff[BUFFER_SIZE + 1];
	int			i = 1;
	int			j = 1;

	h.size = 0;
	h.cont = 0;
	h.flag += 1;


	if (h.flag == 1)
	{
		while (j < 4096)
			str[j++] = 0; 
		while (i > 0)
		{
			i = read(fd, buff, BUFFER_SIZE);
			buff[i] = '\0';
			h.size += ft_strlen(buff);
			ft_strlcat(str, buff, h.size);
		}
		h.strcpy = str;
	}
	while (*(h.strcpy + h.cont) != '\n')
		h.cont++;
	char *line = malloc(h.cont + 2);
	for (int i = 0; i < h.cont + 2; i++)
		line[i] = 0;
	i = 0;
	while (i < h.cont)
		line[i++] = *h.strcpy++;
	line[i++] = '\n';
	line[i] = '\0';
	h.strcpy++;
	return (line);
}
