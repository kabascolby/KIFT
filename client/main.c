/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkaba <lkaba@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/08 09:42:15 by lkaba             #+#    #+#             */
/*   Updated: 2020/03/11 08:26:20 by lkaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

int main(int argc, char **argv)
{
	t_config	config;
	char		sendline[BUFSIZE];
	char		recvline[BUFSIZE];

	if (argc < 2)
	{
		fprintf(stderr, "Error: Port number has to be specified\n");
		return (1);
	}

	bzero(&config, sizeof(t_config));

	/* Create a connection with the server */
	if (create_connection(&config, atoi(argv[1])) || config.status < 0)
	{
		fprintf(stderr, "Error connection\n");
		return (1);
	}
	printf("status: %d | Welcome to %s\nStart listeening:",config.status, config.server_name);

	/* Copy input to the server. */
	while (1)
	{
		bzero(sendline, BUFSIZE);
		bzero(recvline, BUFSIZE);
		fgets(sendline, BUFSIZE, stdin);
		dprintf(config.socket_fd, "%s", sendline);
		if (read(config.socket_fd, recvline, BUFSIZE))
		{
			server_request_handler(recvline);
			printf("\033[1;34mServer ->\033[m %s", recvline);
		}
	}
	close(config.socket_fd);
	return (0);
}
