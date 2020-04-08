/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   router.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkaba <lkaba@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/02 06:20:02 by lkaba             #+#    #+#             */
/*   Updated: 2020/04/06 07:27:55 by lkaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

void	upload_file(t_config *config)
{
	char		*abs_path;
	char		*filename;
	char		*response;
	char		*html;
	FILE		*file;
	int			fd;
	off_t		size;
	uint16_t	total_size;
	struct		stat buf;

	filename = !strcmp(config->header.url, "/") ? "/index.html" :
	strrchr(config->header.url, '/');
	abs_path = ft_join_args("", WEBDIR, filename, NULL);
	file = fopen(abs_path, "r");
	free(abs_path);
	// printf("--------here---------\n");
	if(file)
	{
		fd = fileno(file); //if you have a stream (e.g. from fopen), not a file descriptor.
		fstat(fd, &buf);
		size = buf.st_size;
		html = malloc(size);
		fread((char *)html, 1, size, file);
		response = malloc(size + 500);
		memset(response, 0, size + 500);
		sprintf(response, "%s 200 OK\nServer: %s/%s\nContent-Length: %ld\nConnection: close\nContent-Type: text/html\n\n%s\r\n\r\n",
		HTTP_VERSION, SERVER_NAME, VERSION, size, html);
		send(config->client_sock, response, strlen(response),0);
	}
	else
	{
		file = fopen("/home/lkaba/kift/server/www/404.html", "r");
		fd = fileno(file); //if you have a stream (e.g. from fopen), not a file descriptor.
		fstat(fd, &buf);
		size = buf.st_size;
		html = malloc(size);
		fread((char *)html, 1, size, file);
		response = malloc(size + 500);
		memset(response, 0, size + 500);
		sprintf(response, "%s 404 Not Found\nServer: %s/%s\nContent-Length: %ld\nConnection: close\nContent-Type: text/html\n\n%s\r\n\r\n",
		HTTP_VERSION, SERVER_NAME, VERSION, size, html);
		send(config->client_sock, response, strlen(response),0);

	}
	free(response);
	free(html);
	fclose(file);
}

//todo
//the shoub be no body when the content length is 0
