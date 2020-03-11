/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkaba <lkaba@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 15:46:52 by lkaba             #+#    #+#             */
/*   Updated: 2020/03/10 20:06:13 by lkaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "client.h"

static int	check_port(uint16_t port)
{
	if (port < 1024 || port > 65535)
	{
		fprintf(stderr, "Invalid port, enter (1024 - 65535.)\n");
		return (1);
	}
	return (0);
}

uint8_t		create_connection(t_config *config, int port)
{
	struct sockaddr_in	server_address;
	struct hostent		*host_entry;

	if(check_port(port) || !strlen(SERVERIP))
		return (1);

	bzero(&server_address, sizeof(server_address));

	/* put host's address in socket structure */
	// inet_aton(SERVERIP, &server_address.sin_addr);
	server_address.sin_addr.s_addr = inet_addr(SERVERIP);


	/* put host's address family and the port in socket structure */
	server_address.sin_family = AF_INET;
	server_address.sin_port = htons(port);

	/*Create a file descriptor by defining socket characteristique*/
	if ((config->socket_fd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
	{
		fprintf(stderr, "can't open socket");
		return (1);
	}
	/* Establish a connection */
	if((config->status = connect(config->socket_fd,
								(struct sockaddr *)&server_address,
								sizeof(server_address)))
	< 0)
	{
		fprintf(stderr, "can't connect to server");
		return (1);
	}
	config->port = port;
	strcpy(config->server_name, "Minaserver");
	return (0);
}
