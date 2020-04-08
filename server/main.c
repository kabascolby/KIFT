#include "server.h"

int main(int argc, char **argv)
{
	t_config	config;
	t_header	h;
	fd_set		current_sockets;
	fd_set		ready_sockets;
	int16_t		tmp_socket;
	int16_t		max_socket_size = 0;

	config.length = sizeof(struct sockaddr_in);
	if (argc < 2)
	{
		fprintf(stderr, "Error: Port number has to be specified\n");
		return (1);
	}

	if (create_server(&config, atoi(argv[1])) < 0)
	{
		fprintf(stderr, "Error Serveur configuration\n");
		return (1);
	}

	//initialize my list sockets fd to listeen
	FD_ZERO(&current_sockets);
	FD_SET(config.socket_fd, &current_sockets);

	max_socket_size = config.socket_fd;
	while (config.socket_fd)
	{	//Saving the current set of socket
		//Select overide each time the current set of sockets;
		ready_sockets = current_sockets;

		if(select(FD_SETSIZE, &ready_sockets, NULL, NULL, NULL) < 0)
		{
			perror("select error");
			exit(1);
		}

		int i = -1;
		while(++i <= max_socket_size)
		{
			if(FD_ISSET(i, &ready_sockets))
			{
				if(i == config.socket_fd)
				{
					tmp_socket = accept(config.socket_fd,
					(struct sockaddr *)&(config.cli_addr),&config.length);
					FD_SET(tmp_socket, &current_sockets);
					if (tmp_socket > max_socket_size)
						max_socket_size = tmp_socket;
				}
				else
				{
					config.client_sock = i;
					print_client_info(config.cli_addr, config.client_sock);
					request_handler(&config);
					upload_file(&config);
					close(config.client_sock);
					config.client_sock = -1;
					FD_CLR(i, &current_sockets);
				}
			}
		}
	}
	close(config.socket_fd);
	return (0);
}
