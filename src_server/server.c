/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhenin <mhenin@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 10:14:01 by mhenin            #+#    #+#             */
/*   Updated: 2024/12/10 17:50:18 by mhenin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

int	end_char(int *index, char **buffer, siginfo_t *info)
{
	if ((*buffer)[*index] == '\0')
	{
		ft_printf("\n%s", *buffer);
		free(*buffer);
		*index = 0;
		*buffer = NULL;
		kill(info->si_pid, SIGUSR1);
		return (7);
	}
	*index = *index + 1;
	return (7);
}

void	handler(int signo, siginfo_t *info, void *context)
{
	static char	*buffer = NULL;
	static int	i = 7;
	static int	index = 0;

	(void)context;
	(void)info;
	if (i == 7)
		buffer = ft_strjoin(buffer, "i");
	if (signo == SIGUSR1)
		buffer[index] |= (1 << i);
	else if (signo == SIGUSR2)
		buffer[index] &= ~(1 << i);
	i--;
	if (i < 0)
		i = end_char(&index, &buffer, info);
}

void	init(void)
{
	struct sigaction	action;

	action.sa_sigaction = handler;
	action.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &action, NULL);
	sigaction(SIGUSR2, &action, NULL);
}

int	main(void)
{
	ft_printf("%i", getpid());
	init();
	while (1)
		continue ;
}
