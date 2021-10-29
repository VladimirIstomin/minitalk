/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmerlene <gmerlene@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 15:15:06 by gmerlene          #+#    #+#             */
/*   Updated: 2021/10/28 18:46:20 by gmerlene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

static void	sig_handler(int signal)
{
	static int	i;

	(void)signal;
	ft_putstr_fd("Signal ", 1);
	ft_putnbr_fd(i++, 1);
	ft_putstr_fd(" received\n", 1);
}

static void	send_char(pid_t pid, char c)
{
	int		bits_sent;
	int		kill_res;

	bits_sent = 0;
	while (bits_sent < 8)
	{
		if (c & (1 << bits_sent))
			kill_res = kill(pid, SIGUSR1);
		else
			kill_res = kill(pid, SIGUSR2);
		if (kill_res)
		{
			ft_putstr_fd(SIG_ERROR, 1);
			exit(0);
		}
		pause();
		usleep(50);
		bits_sent++;
	}
}

int	main(int argc, char **argv)
{
	pid_t	pid;

	if (argc == 3)
	{
		pid = ft_atoi(argv[1]);
		signal(SIGUSR1, sig_handler);
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
