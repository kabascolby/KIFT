/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkaba <lkaba@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/07 10:34:31 by lkaba             #+#    #+#             */
/*   Updated: 2020/04/05 01:46:24 by lkaba            ###   ########.fr       */
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
#include <sys/stat.h>
#include <dirent.h>
#include <stdarg.h>
#include <stdint.h>
#include <string.h>
#define BUFSIZE 4096
#define BUFF_SIZE 1
#define WEBDIR "/home/lkaba/kift/server/www"
#define HTTP_VERSION "HTTP/1.1"
#define SERVER_NAME	"Mina"
#define VERSION "0.5"

#define BADHEADER "HTTP/1.1 403 Forbidden\nContent-Length: 114\nConnection: \
close\nContent-Type: text/html\n\n<html><head>\n<title>403 Forbidden</title>\n\
</head><body>\n<h1>Forbidden</h1>\nInvalide header format\n</body></html>\n\n"

#define RESP "HTTP/1.1 200 OK\nContent-Length: 213\nConnection: \
close\nContent-Type: text/html\n\n<html><head>\n<title>Welcome to Mina</title>\n\
<link rel=\"shortcut icon\" href=\"https://developer.cdn.mozilla.net/static/img/favicon32.e02854fdcf73.png\">\
</head><body>\n<h1>MINA</h1>\nYoussouf is a genius\n</body></html>\r\n\r\n"


typedef struct s_sconfig	t_config;

typedef struct s_myna		t_myna;
typedef struct s_header		t_header;
struct sockaddr_in			server_address;


struct s_header
{
	char method[10];
	char url[256];
	char domain[256];
	char proto[20];
	char port[10];
	char content_type[20];
	int	content_length;
};

struct		s_sconfig
{
	char				server_name[256];
	int16_t				socket_fd;
	int16_t				client_sock;
	struct sockaddr_in	cli_addr;
	socklen_t			length;
	t_header			header;
	char				*body;
};

struct s_myna
{
	uint8_t is_keyword;
	char **cmd;
	char *req_time;
	uint8_t status;
};

uint8_t create_server(t_config *config, int port);
void request_handler(t_config *config);
void print_client_info(struct sockaddr_in cli_addr, int client_sock);
void	upload_file(t_config *config);

/* Utility */
char	*ft_join_args(char *sep, ...);
#endif