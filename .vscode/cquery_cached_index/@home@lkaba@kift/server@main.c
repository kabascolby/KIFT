#include "server.h"

int request_handler(	t_config *config)
{
	char data[BUFSIZE] = {0};
	char str[INET_ADDRSTRLEN] = {0};
	int size;
	char *cmd1 = "Youssouf is a Genius";


	if((size = read(config->client_sock, data, BUFSIZE)) > 0)
	{
		printf("Connection From: %s:%d (%d)\n",
			inet_ntop( AF_INET, &config->cli_addr.sin_addr, str, INET_ADDRSTRLEN ), //address as dotted quad
			ntohs(server_address.sin_port),     //the port in host order
		config->client_sock);

			fprintf(stdout, "\033[1;34mClient -> \033[m %s", data);
			send(config->client_sock, cmd1, strlen(cmd1) + 1, 0);
			bzero(data, BUFSIZE);
			close(config->client_sock);
	}
	return size;
}


int main(int argc, char **argv)
{
	t_config config;


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


	while (config.socket_fd)
	{
		if ((config.client_sock = accept(config.socket_fd, (struct sockaddr *)&config.cli_addr,
		&config.length)) < 0 && request_handler(&config) <= 0)
			continue;
		request_handler(&config);
	}
	close(config.socket_fd);
	return (0);
}
