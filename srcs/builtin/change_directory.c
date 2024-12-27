/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_directory.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshingai <cshingai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 17:47:17 by cshingai          #+#    #+#             */
/*   Updated: 2024/12/27 17:14:51 by cshingai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	change_directory(t_envp **env_list, char **path)
{
	char	*old_pwd;
	char	*pwd;

	old_pwd = NULL;
	pwd = NULL;
	if (*path == NULL)
		*path = ft_getenv("HOME", *env_list);
	else if (ft_strcmp(path[0], "~") == 0)
		*path = ft_getenv("HOME", *env_list);
	if (check_path(path) == 1)
		return (1);
	old_pwd = getcwd(old_pwd, PATH_MAX);
	if (chdir(*path) == -1)
	{
		perror(*path);
		return (1);
	}
	pwd = getcwd(pwd, PATH_MAX);
	update_pwd(env_list, old_pwd, pwd);
	return (0);
}

void	update_pwd(t_envp **env_list, char *old_pwd, char *pwd)
{
	if (old_pwd)
	{
		change_env_value("OLDPWD", old_pwd, env_list);
		free(old_pwd);
	}
	if (pwd)
	{
		change_env_value("PWD", pwd, env_list);
		free(pwd);
	}
}

int	check_path(char **path)
{
	if (path == NULL)
	{
		ft_printf_fd(STDERR_FILENO,
			"cd: %s: Missing file or directory\n", *path);
		return (1);
	}
	if (check_num_path(path) == 1)
	{
		ft_printf_fd(STDERR_FILENO, "cd: Too many arguments\n");
		return (1);
	}
	return (0);
}

int	check_num_path(char **path)
{
	int	idx1;

	idx1 = 0;
	while (path[idx1])
		idx1++;
	if (idx1 > 1)
		return (1);
	return (0);
}
