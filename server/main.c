#include "server.h"

void users_request_handler(t_config *config)
{
	char data[BUFSIZE] = {0};
	char str[INET_ADDRSTRLEN] = {0};
	int size;
	char *cmd1 = "HTTP/1.1 200 OK\r\n\r\nYoussouf is a genius";

	fflush(stdout);
	printf("Connection From: %s:%d (%d)\n",
		inet_ntop( AF_INET, &config->cli_addr.sin_addr, str, INET_ADDRSTRLEN ), //address as dotted quad
		ntohs(config->cli_addr.sin_port), //the port in host order
	config->client_sock);

	while((size = read(config->client_sock, data, BUFSIZE - 1)) > 0)
	{
		fprintf(stdout, "\033[1;34mClient -> \033[m %s", data);
		if(data[size -1] == '\n')
			break;
		memset(data, 0, BUFSIZE);
	}
	// write(config->client_sock, cmd1, strlen(cmd1) + 1);
	send(config->client_sock, cmd1, strlen(cmd1), 0);
	close(config->client_sock);
	config->client_sock = -1;
}


int main(int argc, char **argv)
{
	t_config	config;
	fd_set		current_sockets;
	fd_set		ready_sockets;
	int16_t		tmp_socket;


	config.length = sizeof(struct sockaddr_in);
	if (argc < 2) {
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

	while (config.socket_fd)
	{
		//Select overide each time the current set of sockets;
		ready_sockets = current_sockets;

		if(select(FD_SETSIZE, &ready_sockets, NULL, NULL, NULL) < 0)
		{
			perror("select error");
			exit(1);
		}

		int i = -1;
		while(++i < FD_SETSIZE)
		{
			if(FD_ISSET(i, &ready_sockets))
			{
				if(i == config.socket_fd)
				{
					tmp_socket = accept(config.socket_fd,
					(struct sockaddr *)&(config.cli_addr),&config.length);
					FD_SET(tmp_socket, &current_sockets);
				}
				else
				{
					config.client_sock = i;
					users_request_handler(&config);
					FD_CLR(i, &current_sockets);
				}
			}
		}
	}
	close(config.socket_fd);
	return (0);
}
