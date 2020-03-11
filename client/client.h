/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkaba <lkaba@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/07 10:34:14 by lkaba             #+#    #+#             */
/*   Updated: 2020/03/11 07:40:24 by lkaba            ###   ########.fr       */
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
# include <stdint.h>
# define BUFSIZE 200
# define SERVERIP "10.113.100.129"
# define BUILTINS "light invalide"

typedef struct s_sconfig	t_config;
typedef struct sockaddr_in	t_socket;

struct  s_sconfig
{
	char		server_name[256];
	int8_t		socket_fd;
	uint16_t	port;
	int8_t		status;
};

/*
**Function pointer of commands
**This will call each function at given index.
*/

// int (*connect_to_server)(int socket_fd, struct	sockaddr_in *);

uint8_t	create_connection(t_config *config, int server_port);
// int		send(char *subject, char *content, char *recipient);
int		light(char *argv);
int		invalide(char *argv);
void	server_request_handler(char *request);

/* Don't forget to update the index */
static int					(*cmd_fptr[])(char *args) =
{
	light,
	invalide,
};

#endif
