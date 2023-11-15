/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pathing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jechoo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 19:03:08 by jechoo            #+#    #+#             */
/*   Updated: 2023/11/03 19:03:09 by jechoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	createpipe(t_list *data)
{
	if (pipe(data->fd) == -1)
	{
		perror("pipe error");
		free(data->path);
		free(data);
		return (0);
	}
	return (1);
}

char	*findpath(t_list *data)
{
	char	**patharr;
	char	*temp;
	int		i;

	i = 0;
	patharr = ft_split(data->path, ':');
	while (patharr[i])
	{
		data->cmd = ft_strjoin("/", data->strarr[0]);
		data->access = ft_strjoin(patharr[i], data->cmd);
		if (access(data->access, R_OK) == 0)
		{
			temp = ft_strdup(data->access);
			free(data->cmd);
			free(data->access);
			freesplit(patharr);
			return (temp);
		}
		free(data->cmd);
		free(data->access);
		i++;
	}
	freesplit(patharr);
	return (ft_strjoin("/bin/", data->strarr[0]));
}

void	setpath(char *envp[], t_list *data)
{
	int	i;

	i = 0;
	while (envp[i])
	{
		if (envp[i][0] == 'P' && envp[i][1] == 'A'
			&& envp[i][2] == 'T' && envp[i][3] == 'H')
			data->path = ft_strdup(envp[i] + 5);
		i++;
	}
}

void	freesplit(char **s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		free(s[i]);
		i++;
	}
	free(s);
}
