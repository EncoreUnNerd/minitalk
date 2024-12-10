/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhenin <mhenin@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 16:33:59 by mhenin            #+#    #+#             */
/*   Updated: 2024/12/10 17:30:33 by mhenin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

void	send_letter(char c, int pid)
{
	int	e;
	int	j;

	j = 8;
	while (j--)
	{
		e = c >> j & 1;
		if (e == 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(150);
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
	printf("%i", str[i]);
}

void	handler(int signo, siginfo_t *info, void *context)
{
	(void)info;
	(void)context;
	if (signo == SIGUSR1)
	{
		ft_printf("Message bien reçu\n");
		exit(0);
	}
}

void	init(void)
{
	struct sigaction	action;

	action.sa_sigaction = handler;
	action.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &action, NULL);
}

int	main(int ac, char **av)
{
	if (ac == 3 && is_pid(av[1]) && ft_atoi(av[1]) > 0)
	{
		init();
		send(av[2], ft_atoi(av[1]));
		while (1)
			continue ;
	}
}
