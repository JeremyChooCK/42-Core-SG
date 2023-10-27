/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jechoo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 21:42:18 by jechoo            #+#    #+#             */
/*   Updated: 2023/09/23 21:42:22 by jechoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strdup(const char *s)
{
	int		i;
	char	*dupe;

	dupe = malloc((sizeof(char) * ft_strlen(s)) + 1);
	if (dupe == NULL)
		return (NULL);
	i = 0;
	while (s[i] != '\0')
	{
		dupe[i] = s[i];
		i++;
	}
	dupe[i] = '\0';
	return (dupe);
}

char	*ft_strjoin( char const *s1, char const *s2)
{
	size_t	s2len;
	size_t	s1len;
	char	*result;

	s1len = ft_strlen(s1);
	s2len = ft_strlen(s2);
	result = malloc((sizeof(char) * (s1len + s2len)) + 1);
	if (result == NULL)
		return (NULL);
	while (*s1)
		*result++ = *s1++;
	while (*s2)
		*result++ = *s2++;
	*result = '\0';
	return (result - s1len - s2len);
}

char	*readline(int fd, char *buffer, char *stat)
{
	int		check;
	int		i;
	char	*temp;

	check = 1;
	if (!stat)
		stat = ft_strdup("");
	while (check)
	{
		i = 0;
		check = read(fd, buffer, BUFFER_SIZE);
		if (check == -1)
			break ;
		buffer[check] = '\0';
		temp = stat;
		stat = ft_strjoin(temp, buffer);
		free(temp);
		while (stat[i])
		{
			if (stat[i] == '\n')
				return (stat);
			i++;
		}
	}
	return (stat);
}

char	*store_excess(char *line)
{
	int		i;
	int		j;
	char	*excess;

	i = 0;
	j = 0;
	excess = NULL;
	while (line[i] && line[i] != '\n')
		i++;
	if (line[i] == '\0')
		return (NULL);
	excess = malloc(sizeof(char) * (ft_strlen(line) - i));
	if (!excess)
		return (NULL);
	i++;
	while (line[i + j])
	{
		excess[j] = line[i + j];
		j++;
	}
	excess[j] = '\0';
	line[i] = '\0';
	return (excess);
}
