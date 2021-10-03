/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dteixeir <dteixeir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 01:10:56 by dteixeir          #+#    #+#             */
/*   Updated: 2021/10/03 20:31:53 by dteixeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

00001010 << 1 = 00010100
			 |  00000001
				00010101
#include "../include/minitalk.h"

static int	send_signal(pid_t num_id, int bit, char c)
{
	if (c & (1 << bit))
	{
		if (kill(num_id, SIGUSR2) < 0)
			return (1);
	}
	else
	{
		if (kill(num_id, SIGUSR1) < 0)
			return (1);
	}
	return (0);
}

int	send_message(char *arg, pid_t num_id)
{
	int	i;
	int	bit;

	i = 0;
	while (1)
	{
		bit = 7;
		while (bit >= 0)
		{
			if (send_signal(num_id, bit, arg[i]) == 1)
				return (1);
			if (usleep(100) == -1)
				return (1);
			bit--;
		}
		if (arg[i] == '\0')
			break ;
		i++;
	}
	return (0);
}

void	check_message(int signum)
{
	(void)signum;
	g_msg_received = 1;
	write(1, "Message sent! =)\n", 17);
}

pid_t	get_numid(char *arg)
{
	int	num;

	num = 0;
	while (*arg)
	{
		if (*arg >= '0' && *arg <= '9')
			num = (num * 10) + *arg - '0';
		else
			return (-1);
		arg++;
	}
	return (num);
}

int	main(int argc, char **argv)
{
	pid_t	num_id;

	if (argc != 3)
	{
		write(1, "Error! Invalid number of arguments.\n", 36);
		write(1, "Try: ./client + server ID number + 'your message'\n", 50);
		return (1);
	}
	num_id = get_numid(argv[1]);
	if (num_id <= 1)
	{
		write(1, "Error! Invalid server ID number.\n", 33);
		return (2);
	}
	g_msg_received = 0;
	if (signal(SIGUSR1, check_message) == SIG_ERR
		|| send_message(argv[2], num_id) != 0)
		return (1);
	if (g_msg_received == 0)
		sleep(5);
	if (g_msg_received == 1)
		return (0);
	write(1, "Error! Unable to connect with server.\n", 38);
	return (1);
}
