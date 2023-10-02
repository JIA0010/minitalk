/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjia <cjia@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 07:59:41 by yoshimurahi       #+#    #+#             */
/*   Updated: 2023/10/02 12:52:54 by cjia             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	client_error(const char *msg)
{
	ft_printf("Error: %s", msg);
	exit(1);
}

static void	send_bit(const pid_t pid, const int bit)
{
	int	sig;

	sig = 0;
	if (bit)
		sig = SIGUSR1;
	else
		sig = SIGUSR2;
	if (kill(pid, sig) == -1)
		client_error("Failed to send signal\n");
	if (usleep(700) == -1)
		client_error("usleep failed\n");
}

static void	send_char(const pid_t pid, const char c)
{
	int	bit;

	bit = 7;
	while (bit >= 0)
	{
		send_bit(pid, (c >> bit) & 1);
		bit--;
	}
}

static void	send_str(const pid_t pid, const char *str)
{
	while (*str)
		send_char(pid, *str++);
	send_char(pid, '\n');
}

int	main(int argc, char *argv[])
{
	pid_t	pid;

	if (argc != 3)
	{
		client_error("Usage: ./client <pid_number> <message>\n");
		return (1);
	}
	pid = ft_atoi(argv[1]);
	if (pid == -1 || pid == 0)
		client_error("Usage: ./client <pid_number> <message>\n");
	send_str(pid, argv[2]);
	return (0);
}
