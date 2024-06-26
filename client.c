/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfazaz <hfazaz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 20:08:22 by hfazaz            #+#    #+#             */
/*   Updated: 2024/04/30 08:43:59 by hfazaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

t_data	g_data = {0};

void	ack(int signum)
{
	if (signum == SIGUSR1)
	{
		write(1, "char recieved \n", 15);
	}
}

void	to_binary(int pid, unsigned char c)
{
	int	i;
	int	pid_check;

	i = 7;
	while (i >= 0)
	{
		g_data.byte = (c >> i) & 1;
		if (g_data.byte)
			pid_check = kill(pid, SIGUSR2);
		else
			pid_check = kill(pid, SIGUSR1);
		if (pid_check == -1 && c != '\n')
		{
			write(1, "pid not found\n", 14);
			return ;
		}
		usleep(500);
		i--;
	}
}

int	main(int ac, char **av)
{
	int		pid;
	char	*msg;

	if (ac != 3)
	{
		write(1, "args error", 10);
		return (0);
	}
	msg = av[2];
	pid = ft_atoi(av[1]);
	if (pid == -1)
		return (0);
	while (*msg)
	{
		to_binary(pid, (unsigned char)*msg);
		msg++;
	}
	to_binary(pid, '\n');
	return (0);
}
