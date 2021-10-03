/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dteixeir <dteixeir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 01:07:52 by dteixeir          #+#    #+#             */
/*   Updated: 2021/10/03 17:41:59 by dteixeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include <sys/types.h>
# include <unistd.h>

int	g_msg_received;

/**
* SERVER
**/

void	print_id(pid_t id);
int		setup_handlers(void);
void	sig_action(int signum, siginfo_t *info, void *ucontext);
void	receive_message(int num_bit, pid_t id_client);

/**
* CLIENT
**/

pid_t	get_numid(char *arg);
int		send_message(char *arg, pid_t num_id);
void	check_message(int signum);

#endif
