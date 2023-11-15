/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jechoo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 14:58:57 by jechoo            #+#    #+#             */
/*   Updated: 2023/10/30 14:58:59 by jechoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include <sys/wait.h>
# define BUFSIZE 10000

typedef struct s_list
{
	int		id;
	char	**strarr;
	char	**strarr2;
	char	*command[3];
	char	*command2[3];
	int		infile;
	int		midfile;
	int		outfile;
	int		fd[2];
	char	*path;
	char	*cmd;
	char	*access;
	char	*joinedpath;
	int		stdoutfd;
	int		stdinfd;
}		t_list;

size_t	ft_strlen(const char *str);
char	*ft_strjoin( char const *s1, char const *s2);
char	**ft_split(char const *s, char c);
char	*ft_strdup(const char *s);
int		createpipe(t_list *data);
char	*findpath(t_list *data);
void	setpath(char *envp[], t_list *data);
void	freesplit(char **s);

#endif
