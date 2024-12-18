/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhenin <mhenin@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 10:59:31 by mhenin            #+#    #+#             */
/*   Updated: 2024/12/18 10:05:28 by mhenin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <stdlib.h>
# include <signal.h>

int		ft_atoi(const char *str);
size_t	ft_strlen(const char *str);
void	*ft_memset(void *ptr, int value, size_t n);
int		is_pid(char *str);
void	verif_kill(siginfo_t *info, char **buffer);

#endif