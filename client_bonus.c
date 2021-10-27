/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmerlene <gmerlene@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 15:15:06 by gmerlene          #+#    #+#             */
/*   Updated: 2021/10/27 19:46:20 by gmerlene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

static void	sig_handler(int signal)
{
	(void)signal;
	ft_putstr_fd("Signal recieved\n", 1);
}

static void	send_char(pid_t pid, char c)
{
	int		n_bit;
	int		kill_res;

	n_bit = 0;
	while (n_bit < 8)
	{
		if (c & (1 << n_bit))
			kill_res = kill(pid, SIGUSR1);
		else
			kill_res = kill(pid, SIGUSR2);
		if (kill_res)
		{
			ft_putstr_fd(SIG_ERROR, 1);
			exit(0);
		}
		n_bit++;
		pause();
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
		ft_putstr_fd("Error: Incorrect number of arguments!\n", 1);
	return (0);
}
