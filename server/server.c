/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkaba <lkaba@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 13:14:16 by lkaba             #+#    #+#             */
/*   Updated: 2020/03/15 06:29:51 by lkaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

static int check_port(uint16_t port)
{
	if (port < 1024 || port > 65535)
	{
		fprintf(stderr, "Invalid port, enter (1024 - 65535.)\n");
		return (1);
	}
	return (0);
}

uint8_t create_server(t_config *config, int port)
{
	struct sockaddr_in server_address;
	struct hostent *host_entry;

	if (check_port(port))
		return (1);

	if ((config->socket_fd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
	{
		fprintf(stderr, "can't open socket");
		return (1);
	}
	bzero(&server_address, sizeof(server_address));

	/* put host's address in socket structure */
	server_address.sin_addr.s_addr = htons(INADDR_ANY);

	/* put host's address family and the port in socket structure */
	server_address.sin_family = AF_INET;
	server_address.sin_port = htons(port);

	/* After the socket descriptor is created, a bind() function gets a */
	/* unique name for the socket*/

	if ((bind(config->socket_fd, (struct sockaddr *)&server_address, sizeof(server_address))) < 0)
	{
		perror("bind() failed");
		return (1);
	}

	listen(config->socket_fd, 10);

	if ((config->status = accept(config->socket_fd, (struct sockaddr *)NULL, NULL)) < 0)
	{
		perror("bind() failed");
		return (1);
	}
	return (0);
}