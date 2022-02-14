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

// char *new_line(char *s)
// {
// 	int i;
// 	char *line;

// 	i = - 1;
// 	while (s[++i] != '\n')
// 		i++;
	
// 	line = malloc(sizeof(char) * i + 1);
// 	i = -1;
// 	while (s[++i] != '\n')
// 		line[i] = s[i];

// 	line[i] = '\0';
// 	return (line);
// }



void	get_next_line(int fd)
{
	static	char	*cpyfile = NULL;
	char		buff[BUFFER_SIZE + 1];
	int			i;
	int size = 0;
	int cont = 0;

	if (!cpyfile)
	{
		cpyfile = malloc(sizeof(char) * 4097);
		while ((i = read(fd, buff, BUFFER_SIZE)))
		{
			buff[i] = '\0';
			size += ft_strlen(buff);
			ft_strlcat(cpyfile, buff, size + 1);
		}
	}
	while (*cpyfile != '\n')
	{
		cpyfile++;
		cont++;
	}
	int cpycont = cont;
	char *line = malloc(sizeof(char) * cont + 1);
	while (cpycont--)
		cpyfile--;
	i = 0;
	while (i < cont)
	{
		line[i] = *cpyfile++;
		i++;
	}
	line[i] = '\0';
	cpyfile++;
	printf("%s", line);

}
