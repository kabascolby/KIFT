/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkaba <lkaba@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/07 10:34:31 by lkaba             #+#    #+#             */
/*   Updated: 2020/03/20 09:14:42 by lkaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_H
#define SERVER_H
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <time.h>
#include <stdarg.h>
#define BUFSIZE 4096

typedef struct s_sconfig t_config;

typedef struct s_myna t_myna;
struct sockaddr_in server_address;

struct		s_sconfig
{
	char				server_name[256];
	int16_t				socket_fd;
	int16_t				client_sock;
	struct sockaddr_in	cli_addr;
	socklen_t			length;
};

struct s_myna
{
	uint8_t is_keyword;
	char **cmd;
	char *req_time;
	uint8_t status;
};

uint8_t create_server(t_config *config, int port);

#endif