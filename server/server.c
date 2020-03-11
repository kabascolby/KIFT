/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkaba <lkaba@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 13:14:16 by lkaba             #+#    #+#             */
/*   Updated: 2020/03/11 08:00:14 by lkaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

int	main(int argc, char **argv)
{
	char	str[BUFSIZE];
	int		listen_fd;
	int 	status;
    if (argc != 2 || (argc == 2 && (atoi(argv[1]) < 1024 || atoi(argv[1]) > 65535)))
    {
        fprintf(stderr, "Invalid port, enter (1024 - 65535.)\n");
        return (-1);
    }
	listen_fd = socket(AF_INET, SOCK_STREAM, 0);
	bzero(&server_address, sizeof(server_address));
	server_address.sin_family = AF_INET;
	server_address.sin_addr.s_addr = htons(INADDR_ANY);
	server_address.sin_port = htons(atoi(argv[1]));
	bind(listen_fd, (struct sockaddr *) &server_address, sizeof(server_address));
	listen(listen_fd, 10);
	status = accept(listen_fd, (struct sockaddr*) NULL, NULL);
	char *cmd1 = "light of";
	while (1)
	{
		bzero(str, BUFSIZE);
		read(status,str,BUFSIZE);
		if (status)
		{
			fprintf(stdout,"\033[1;34mClient ->\033[m %s", str);
			// write(status, str, strlen(str)+1);
			write(status, cmd1, strlen(cmd1)+1);
		}
	}
	return (0);
}
