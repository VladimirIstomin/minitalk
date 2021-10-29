/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmerlene <gmerlene@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 15:15:06 by gmerlene          #+#    #+#             */
/*   Updated: 2021/10/29 12:43:45 by gmerlene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	g_is_signal_received;

static void	await_signal(void)
{
	while (!g_is_signal_received)
		usleep(1);
}

static void	sig_handler(int signal, siginfo_t *siginfo, void *context)
{
	(void)signal;
	(void)siginfo;
	(void)context;
	g_is_signal_received = 1;
}

static void	send_char(pid_t pid, char c)
{
	int		bits_sent;
	int		kill_res;

	bits_sent = 0;
	while (bits_sent < 8)
	{
		g_is_signal_received = 0;
		if (c & (1 << bits_sent))
			kill_res = kill(pid, SIGUSR1);
		else
			kill_res = kill(pid, SIGUSR2);
		if (kill_res)
		{
			ft_putstr_fd(SIG_ERROR, 1);
			exit(0);
		}
		bits_sent++;
		await_signal();
	}
}

int	main(int argc, char **argv)
{
	pid_t				pid;
	struct sigaction	sigact;

	if (argc == 3)
	{
		pid = ft_atoi(argv[1]);
		sigact.sa_flags = SA_SIGINFO;
		sigact.sa_sigaction = sig_handler;
		sigaction(SIGUSR1, &sigact, NULL);
		while (*argv[2])
		{
			send_char(pid, *argv[2]);
			argv[2]++;
		}
	}
	else
		ft_putstr_fd(ARG_ERROR, 1);
	return (0);
}
