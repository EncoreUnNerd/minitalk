/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhenin <mhenin@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 16:33:59 by mhenin            #+#    #+#             */
/*   Updated: 2024/12/18 10:01:48 by mhenin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

int	g_can_send;

void	send_letter(char c, int pid)
{
	int	e;
	int	j;

	j = 8;
	while (j--)
	{
		e = c >> j & 1;
		g_can_send = 0;
		if (e == 1)
		{
			if (kill(pid, SIGUSR1) == -1)
				exit(1);
		}
		else
		{
			if (kill(pid, SIGUSR2) == -1)
				exit(1);
		}
		while (g_can_send == 0)
			usleep(500);
	}
}

void	send(char *str, int pid)
{
	int	i;

	i = 0;
	while (str[i])
	{
		send_letter(str[i], pid);
		i++;
	}
	send_letter(str[i], pid);
}

void	handler(int signo)
{
	if (signo == SIGUSR2)
		g_can_send = 1;
	else if (signo == SIGUSR1)
	{
		ft_printf("Message bien reçu\n");
		exit(0);
	}
}

void	init(void)
{
	struct sigaction	action;

	ft_memset(&action, 0, sizeof(action));
	action.sa_handler = handler;
	if (sigaction(SIGUSR1, &action, NULL) == -1)
		exit(1);
	if (sigaction(SIGUSR2, &action, NULL) == -1)
		exit(1);
}

int	main(int ac, char **av)
{
	if (ac == 3 && is_pid(av[1]) && ft_atoi(av[1]) > 0)
	{
		g_can_send = 1;
		init();
		send(av[2], ft_atoi(av[1]));
	}
}
