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
	char	old_pwd[PATH_MAX];
	char	pwd[PATH_MAX];
	char	*new_path;

	//	1 - Verificar quantidade de argumentos
	//	2 - Verificar se o path é nulo
	//		2.1 - Se for nulo, pegar o valor da variável HOME
	//		2.1.1 - Se não existir a variável HOME, retornar erro
	//	3 - Verificar se o path é igual a ~
	//		3.1 - Se for igual a ~, pegar o valor da variável HOME
	//		3.1.1 - Se não existir a variável HOME, retornar erro
	//	4 - Verificar se o path é igual a -
	//		4.1 - Se for igual a -, pegar o valor da variável OLDPWD
	//		4.1.1 - Se não existir a variável OLDPWD, retornar erro
	//	5 - Verificar se o path é um diretório válido
	//		5.1 - Se não for um diretório válido, retornar erro
	//	6 - Pegar o valor da variável OLDPWD
	//	7 - Mudar o diretório
	//		7.1 - Se não conseguir mudar o diretório, retornar erro
	//	8 - Pegar o valor do diretório atual
	//	9 - Atualizar as variáveis OLDPWD e PWD
	//	10 - Retornar 0

	new_path = *path;
	if (*path == NULL)
		new_path = ft_getenv("HOME", *env_list);
	else if (ft_strcmp(path[0], "~") == 0)
		new_path = ft_getenv("HOME", *env_list);
	else if (ft_strcmp(path[0], "-") == 0)
		new_path = ft_getenv("OLDPWD", *env_list);
	if (check_path(new_path, path) == 1)
		return (1);
	getcwd(old_pwd, PATH_MAX);
	if (chdir(new_path) == -1)
	{
		perror(new_path);
		return (1);
	}
	getcwd(pwd, PATH_MAX);
	update_pwd(env_list, old_pwd, pwd);
	return (0);
}

void	update_pwd(t_envp **env_list, char *old_pwd, char *pwd)
{
	if (old_pwd)
	{
		change_env_value("OLDPWD", old_pwd, env_list);
		// free(old_pwd);
	}
	if (pwd)
	{
		change_env_value("PWD", pwd, env_list);
		// free(pwd);
	}
}

int	check_path(char *new_path, char **path)
{
	if (new_path == NULL)
	{
		ft_printf_fd(STDERR_FILENO,
			"cd: %s: Missing file or directory\n", new_path);
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
