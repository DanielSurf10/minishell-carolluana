/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshingai <cshingai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 17:27:57 by cshingai          #+#    #+#             */
/*   Updated: 2024/12/27 20:13:28 by cshingai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	init_signals(void)
{
	signal(SIGINT, sig_handler_sigint);
	signal(SIGQUIT, SIG_IGN);
}

void	signals_for_command(void)
{
	signal(SIGQUIT, sig_handler_execute);
	signal(SIGINT, sig_handler_execute);
}

void	sig_handler_execute(int signal)
{
	if (signal == SIGQUIT || signal == SIGINT)
	{
		if (signal == SIGQUIT)
			ft_putstr_fd("Quit", STDOUT_FILENO);
		ft_putstr_fd("\n", STDOUT_FILENO);
		g_signal = 128 + signal;
	}
}

void	sig_handler_sigint(int signal)
{
	ft_putstr_fd("\n", STDOUT_FILENO);
	rl_on_new_line();
	rl_replace_line("", STDIN_FILENO);
	rl_redisplay();
	g_signal = signal + 128;
}

void	sig_handler_heredoc(int signal)
{
	if (signal == SIGINT)
	{
		ft_putstr_fd("\n", STDOUT_FILENO);
		rl_replace_line("", STDIN_FILENO);
		close(STDIN_FILENO);
		g_signal = signal + 128;
	}
}
