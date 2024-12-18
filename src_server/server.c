/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhenin <mhenin@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 10:14:01 by mhenin            #+#    #+#             */
/*   Updated: 2024/12/18 10:36:30 by mhenin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

int	end_char(int *index, int *max_index, char **buffer, siginfo_t *info)
{
	if ((*buffer)[*index] == 0)
	{
		ft_printf("1");
		ft_printf("%s", *buffer);
		ft_printf("2");
		free(*buffer);
		ft_printf("3");
		*buffer = NULL;
		ft_printf("4");
		*index = 0;
		ft_printf("5");
		*max_index = 256;
		ft_printf("6");
		if (kill(info->si_pid, SIGUSR1) == -1)
			exit(1);
		ft_printf("8");
		return (7);
	}
	ft_printf("-1");
	*index = *index + 1;
	ft_printf("0");
	return (7);
}

char	*memory_buffer(char *buffer, int *max_index)
{
	int		i;
	char	*tmp;

	i = 0;
	tmp = malloc(sizeof(char) * ((*max_index) * 2));
	if (!tmp)
	{
		free(buffer);
		exit(1);
	}
	ft_memset(tmp, 0, (*max_index) * 2);
	while (i < *max_index)
	{
		tmp[i] = buffer[i];
		i++;
	}
	*max_index *= 2;
	return (free(buffer), tmp);
}

void	handler(int signo, siginfo_t *info, void *context)
{
	static char	*buffer = NULL;
	static int	i = 7;
	static int	index = 0;
	static int	max_index = 256;

	(void)context;
	if (buffer == NULL)
	{
		buffer = malloc(sizeof(char) * max_index);
		if (!buffer)
			exit(1);
		buffer = ft_memset(buffer, 0, max_index);
	}
	else if (index == max_index)
		buffer = memory_buffer(buffer, &max_index);
	if (signo == SIGUSR1)
		buffer[index] |= (1 << i);
	else if (signo == SIGUSR2)
		buffer[index] &= ~(1 << i);
	i--;
	if (i < 0)
		i = end_char(&index, &max_index, &buffer, info);
	if (buffer != NULL)
		verif_kill(info, &buffer);
}

void	init(void)
{
	struct sigaction	action;

	ft_memset(&action, 0, sizeof(action));
	action.sa_sigaction = handler;
	action.sa_flags = SA_SIGINFO;
	if (sigaction(SIGUSR1, &action, NULL) == -1)
		exit(1);
	if (sigaction(SIGUSR2, &action, NULL) == -1)
		exit(1);
}

int	main(void)
{
	ft_printf("Server PID : %i \n", getpid());
	init();
	while (1)
		pause();
}
