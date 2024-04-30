/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfazaz <hfazaz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 02:44:10 by hfazaz            #+#    #+#             */
/*   Updated: 2024/04/29 18:37:56 by hfazaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

t_data	g_data = {0};

void	signal_handler(int signum, siginfo_t *info, void *context)
{
	(void)context;
	if (signum == SIGUSR1)
	{
		g_data.current_char <<= 1;
	}
	else if (signum == SIGUSR2)
	{
		g_data.current_char <<= 1;
		g_data.current_char |= 1;
	}
	g_data.bit_count++;
	if (g_data.bit_count == 8)
	{
		write(1, &g_data.current_char, 1);
		if (info && info->si_pid && g_data.current_char != '\n')
			kill(info->si_pid, SIGUSR1);
		g_data.bit_count = 0;
		g_data.current_char = 0;
	}
}

int	main(void)
{
	struct sigaction	sa;

	sa.sa_sigaction = signal_handler;
	sa.sa_flags = SA_SIGINFO;
	sigemptyset(&sa.sa_mask);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	printf("Server PID: %d\n", getpid());
	while (1)
		pause();
	return (0);
}
