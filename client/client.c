/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkaba <lkaba@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 15:46:52 by lkaba             #+#    #+#             */
/*   Updated: 2020/03/07 16:58:19 by lkaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "client.h"

int main(int argc,char **argv)
{
    int     socket_fd,n;
    int     status;
    char    sendline[BUFSIZE];
    char    recvline[BUFSIZE];

    if (argc != 2 || (argc == 2 && (atoi(argv[1]) < 1024 || atoi(argv[1]) > 65535)))
    {
        fprintf(stderr, "Invalid port, enter (1024 - 65535.)\n");
        return (-1);
    }

	/*Create a socker fd*/
    socket_fd = socket(AF_INET,SOCK_STREAM,0);

    bzero(&server_address,sizeof server_address);
    server_address.sin_family=AF_INET;
    server_address.sin_port=htons(atoi(argv[1]));
	inet_aton("10.113.100.129", &server_address.sin_addr);
    // server_address.sin_addr.s_addr = INADDR_ANY;

    status = connect(socket_fd,(struct sockaddr *)&server_address,sizeof(server_address));
    if (status == -1)
    {
        fprintf(stderr, "Connection error\n");
        return 0;
    }
    while(1)
    {
        bzero(sendline, BUFSIZE);
        bzero(recvline, BUFSIZE);
        fgets(sendline, BUFSIZE, stdin);
        write(socket_fd, sendline, strlen(sendline)+1);
        read(socket_fd, recvline, 100);
        printf("%s",recvline);
    }
    return (0);
}
