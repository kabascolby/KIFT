/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   request_handler.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkaba <lkaba@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/20 10:50:29 by lkaba             #+#    #+#             */
/*   Updated: 2020/04/04 00:25:57 by lkaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

static void parse_header(t_header *header, char *buf)
{
	char *line;

	sscanf(buf, "%s%s%s", header->method, header->url, header->proto);
	//todo
	//check the type of the header

	if((line = strstr(buf,"Content-Type:")))
		sscanf(line, "Content-Type:%*c%[^;\n]", header->content_type);
	line = NULL;
	if((line = strstr(buf,"Host:")))
		sscanf(line, "Host:%*c%[^:]:%[0-9]", header->domain, header->port);
	line = NULL;
	if((line = strstr(buf,"Content-Length:")))
		sscanf(line, "Content-Length:%d", &header->content_length);
}

static uint32_t resize_buffer(char *buf, uint32_t prev_size, uint32_t size_to_add)
{
	buf = realloc(buf,	prev_size + size_to_add);
	memset(buf + prev_size, 0 , size_to_add);
	return (prev_size + size_to_add);
}

static void print_debug(t_config *config)
{
	fprintf(stdout, "method = %s\nurl = %s\nprotocol = %s\ndomain = %s\nport = %s\nCtype = %s\nClength = %d\nbody = %s\n",
	config->header.method, config->header.url, config->header.proto, config->header.domain,
	config->header.port, config->header.content_type, config->header.content_length, config->body);
	fprintf(stdout, "\033[1;34m------End ------- \033[m\n");
}

void request_handler(t_config *config)
{
	char		tmp[BUFSIZE];
	char		*tmp2;
	char		*buf;
	uint32_t	size;
	int32_t		len;
	uint32_t	rest;
	uint32_t	total;


	if (read(config->client_sock, buf, 0) < 0)
	{
		fprintf(stderr ,"Bad file descriptor\n");
		send(config->client_sock, BADHEADER, strlen(BADHEADER), 0);
		close(config->client_sock);
		return;
	}

	size = BUFSIZE;
	total = 0;
	buf = calloc(BUFSIZE, sizeof(char));

	// parsing the header
	while((len = recv(config->client_sock, tmp, BUFSIZE, 0)) > 0)
	{
		if(len + 1 >= BUFSIZE)
			size = resize_buffer(buf, size, BUFSIZE);
		memcpy(buf + total, tmp, len);
		total += len;
		if((tmp2 = strstr(buf, "\r\n\r\n")))
		{
			bzero(&config->header, sizeof(t_header));
			parse_header(&config->header, buf);
			break;
		}
	}
	//check if there is a body then grab it
	if(config->header.content_length)
	{
		rest =  config->header.content_length - strlen(tmp2 + 4);

		if(total + rest > size)
			resize_buffer(buf, size, BUFSIZE);
		recv(config->client_sock, buf + total, rest - 1, 0);
		config->body = calloc(config->header.content_length + 1, sizeof(char));
		memcpy(config->body, tmp2 + 4, config->header.content_length);
		free(buf);
	}
	else
		config->body = buf;
	print_debug(config);
}

