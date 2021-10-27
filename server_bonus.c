/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmerlene <gmerlene@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 15:07:36 by gmerlene          #+#    #+#             */
/*   Updated: 2021/10/27 20:21:29 by gmerlene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

static void	create_pid(void)
{
	pid_t	pid;

	pid = getpid();
	ft_putstr_fd("PID: ", 1);
	ft_putnbr_fd(pid, 1);
	ft_putchar_fd('\n', 1);
}

static void	sig_handler(int signal, siginfo_t *siginfo, void *context)
{
	static char	character;
	static int	bits_written;

	(void)context;
	if (signal == SIGUSR1)
		character |= 1 << bits_written;
	bits_written++;
	if (bits_written == 8)
	{
		ft_putchar_fd(character, 1);
		character = 0;
		bits_written = 0;
	}
	if (kill(siginfo->si_pid, SIGUSR1))
	{
		ft_putstr_fd(SIG_ERROR, 1);
		exit(0);
	}
}

int	main(void)
{
	struct sigaction	sigac;

	create_pid();
	sigac.sa_flags = SA_SIGINFO;
	sigac.sa_sigaction = sig_handler;
	sigaction(SIGUSR1, &sigac, NULL);
	sigaction(SIGUSR2, &sigac, NULL);
	while (1)
		pause();
	return (0);
}
