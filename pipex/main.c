/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jechoo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 01:57:05 by jechoo            #+#    #+#             */
/*   Updated: 2023/10/30 01:57:06 by jechoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	childprocess(t_list *data, char *envp[])
{
	close(data->fd[0]);
	dup2(data->fd[1], 1);
	dup2(data->infile, 0);
	close(data->infile);
	close(data->fd[1]);
	data->command[0] = data->joinedpath;
	data->command[1] = data->strarr[1];
	data->command[2] = NULL;
	execve(data->command[0], data->command, envp);
	write(2, "zsh: command not found: ", 24);
	write(2, data->strarr[0], ft_strlen(data->strarr[0]));
	write(2, "\n", 1);
	free(data->command2[0]);
	freesplit(data->strarr);
	free(data);
	exit(EXIT_FAILURE);
}

void	outfile(t_list *data, char **av, char *envp[])
{
	data->outfile = open(av[4], O_RDWR | O_CREAT | O_TRUNC, 0666);
	close(data->fd[1]);
	dup2(data->fd[0], 0);
	dup2(data->outfile, 1);
	close(data->fd[0]);
	close(data->outfile);
	freesplit(data->strarr);
	data->strarr = ft_split(av[3], ' ');
	free(data->joinedpath);
	data->joinedpath = findpath(data);
	data->command2[0] = data->joinedpath;
	data->command2[1] = data->strarr[1];
	data->command2[2] = NULL;
	execve(data->command2[0], data->command2, envp);
	wait(NULL);
	write(2, "zsh: command not found: ", 24);
	write(2, data->strarr[0], ft_strlen(data->strarr[0]));
	write(2, "\n", 1);
	free(data->command2[0]);
	freesplit(data->strarr);
	free(data);
	exit(EXIT_FAILURE);
}

t_list	*assignvars(char *envp[])
{
	t_list	*data;

	data = malloc(sizeof(t_list));
	data->stdoutfd = dup(1);
	data->stdinfd = dup(0);
	setpath(envp, data);
	return (data);
}

void	forkprocess(t_list *data, char *envp[], char **av)
{
	data->id = fork();
	if (data->id == 0)
		childprocess(data, envp);
	else
	{
		outfile(data, av, envp);
		wait(NULL);
	}
}

int	main(int ac, char **av, char *envp[])
{
	t_list	*data;

	data = assignvars(envp);
	(void)ac;
	if (ac == 5)
	{
		if (createpipe(data) == 0)
			return (1);
		data->strarr = ft_split(av[2], ' ');
		data->joinedpath = findpath(data);
		data->infile = open(av[1], O_RDONLY);
		if (data->infile == -1)
		{
			perror(av[1]);
			freesplit(data->strarr);
			free(data->joinedpath);
			free(data->path);
			free(data);
			exit(EXIT_FAILURE);
		}
		forkprocess(data, envp, av);
	}
	free(data->path);
	free(data);
}
