/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjia <cjia@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 07:59:49 by yoshimurahi       #+#    #+#             */
/*   Updated: 2023/10/02 12:53:22 by cjia             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int			g_char = 0;

static void	server_error(const char *msg)
{
	ft_printf("Error: %s\n", msg);
	exit(1);
}

static void	output(void)
{
	if (write(1, &g_char, 1) == -1)
		server_error("Failed to write character.\n");
	g_char = 0;
}

static void	signal_handler(int signum)
{
	static int	bit_count;

	bit_count = 0;
	g_char = g_char << 1;
	if (signum == SIGUSR1)
		g_char |= 1;
	else if (signum == SIGUSR2)
		;
	else
		server_error("Received an unexpected signal.\n");
	if (++bit_count == 8)
	{
		output();
		bit_count = 0;
	}
}

void	setup_signal_handlers(void)
{
	struct sigaction	sa;

	sa.sa_flags = 0;
	sa.sa_handler = signal_handler;
	sigemptyset(&sa.sa_mask);
	if (sigaction(SIGUSR1, &sa, NULL) == -1)
		server_error("Failed to set signal handler for SIGUSR1.\n");
	if (sigaction(SIGUSR2, &sa, NULL) == -1)
		server_error("Failed to set signal handler for SIGUSR2.\n");
}

int	main(void)
{
	setup_signal_handlers();
	ft_printf("Server pid: %d \n", getpid());
	while (1)
	{
		pause();
	}
	return (0);
}
