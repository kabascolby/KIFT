/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkaba <lkaba@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/07 10:34:31 by lkaba             #+#    #+#             */
/*   Updated: 2020/03/11 03:30:23 by lkaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_H
# define SERVER_H
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/types.h>
# include <sys/socket.h>
# include <netdb.h>
# include <netinet/in.h>
# include <arpa/inet.h>
# include <time.h>
# include <stdarg.h>
# define BUFSIZE 200

typedef struct s_req		t_req;

typedef struct s_myna		t_myna;
struct sockaddr_in server_address;

struct	s_myna
{
	uint8_t		is_keyword;
	char		**cmd;
	char		*req_time;
	uint8_t		status;
};

#endif