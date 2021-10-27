/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmerlene <gmerlene@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 15:15:06 by gmerlene          #+#    #+#             */
/*   Updated: 2021/10/27 16:22:51 by gmerlene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	sig_handler(int signal)
{
	(void)signal;
	ft_putstr_fd("Signal recieved\n", 1);
}

static void	send_char(pid_t pid, char c)
{
	int		n_bit;

	n_bit = 0;
	while (n_bit < 8)
	{
		if (c & (1 << n_bit))
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
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
		ft_putstr_fd("Error: Incorrect number of arguments!", 1);
	return (0);
}
