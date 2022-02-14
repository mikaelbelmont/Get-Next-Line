#ifndef	GET_NEXT_LINE_H
#define	GET_NEXT_LINE_H

#ifndef BUFFER_SIZE
#define	BUFFER_SIZE 32

#endif

#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

void get_next_line(int fd);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlcat(char *dst, const char *src, size_t n);
int	ft_strlen(const char *str);

#endif