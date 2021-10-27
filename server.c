/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmerlene <gmerlene@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 15:07:36 by gmerlene          #+#    #+#             */
/*   Updated: 2021/10/27 16:09:50 by gmerlene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

t_char	*g_char;

static void	display_pid(void)
{
	pid_t	pid;

	pid = getpid();
	ft_putstr_fd("PID: ", 1);
	ft_putnbr_fd(pid, 1);
	ft_putchar_fd('\n', 1);
}

static void	sig_handler(int signal, siginfo_t *siginfo, void *context)
{
	(void)context;
	if (signal == SIGUSR1)
		g_char->c |= 1 << g_char->bits_written;
	g_char->bits_written++;
	if (g_char->bits_written == 8)
	{
		ft_putchar_fd(g_char->c, 1);
		g_char->c = 0;
		g_char->bits_written = 0;
	}
	kill(siginfo->si_pid, SIGUSR1);
}

static t_char	*create_char(void)
{
	t_char	*c;

	c = malloc(sizeof(t_char));
	if (!c)
		return (NULL);
	c->c = 0;
	c->bits_written = 0;
	return (c);
}

int	main(void)
{
	struct sigaction	sigac;

	display_pid();
	sigac.sa_flags = SA_SIGINFO;
	g_char = create_char();
	sigac.sa_sigaction = sig_handler;
	sigaction(SIGUSR1, &sigac, NULL);
	sigaction(SIGUSR2, &sigac, NULL);
	while (1)
		pause();
	return (0);
}
