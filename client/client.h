/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkaba <lkaba@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/07 10:34:14 by lkaba             #+#    #+#             */
/*   Updated: 2020/03/10 19:59:44 by lkaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLIENT_H
# define CLIENT_H
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/types.h>
# include <sys/socket.h>
# include <netdb.h>
# include <netinet/in.h>
# include <arpa/inet.h>
# include <time.h>
# include <string.h>
# include <stdint.h>
# define BUFSIZE 200
# define SERVERIP "10.113.100.129"

typedef struct s_sconfig	t_config;
typedef struct sockaddr_in	t_socket;

struct  s_sconfig
{
	char		server_name[256];
	int8_t		socket_fd;
	uint16_t	port;
	int8_t		status;
};

	// char	message;
/*
**Function pointer of commands
**This will call each function at given index.
*/

// int (*connect_to_server)(int socket_fd, struct	sockaddr_in *);

uint8_t	create_connection(t_config *config, int server_port);
// int		send(char *subject, char *content, char *recipient);

// static int					(*const cmd_ptr[])(char *commads, ...) =
// {
// 	send,
// 	// cmd_cd,
// 	// cmd_env,
// 	// cmd_setenv,
// 	// cmd_unsetenv,
// 	// cmd_exit
// };

#endif