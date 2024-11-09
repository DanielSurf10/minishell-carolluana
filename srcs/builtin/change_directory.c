/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_directory.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshingai <cshingai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 17:47:17 by cshingai          #+#    #+#             */
/*   Updated: 2024/11/09 15:57:06 by cshingai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	change_directory(t_envp **env_list, char *path)
{
	char	*old_pwd;
	char	*pwd;

	old_pwd = NULL;
	pwd = NULL;
	if (path == NULL || ft_strcmp(path, "~") == 0)
		path = ft_getenv("HOME", *env_list);
	if (path == NULL)
	{
		printf("cd: %s: Missing file or directory\n", path);
		return (1);
	}
	if (check_path(path) == 1)
	{
		printf("cd: Too many arguments\n");
		return (1);
	}
	old_pwd = getcwd(old_pwd, PATH_MAX);
	chdir(path);
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

int	check_path(char *path)
{
	int	i;

	i = 0;
	while(path[i])
	{
		if ((ft_isascii(path[i]) && !ft_is_space(path[i])) && ft_is_space(path[i + 1]))
		{
			i++;
			while(ft_is_space(path[i]))
				i++;
			if (!ft_is_space(path[i]))
				return (1);
		}
		i++;
	}
	return (0);
}
