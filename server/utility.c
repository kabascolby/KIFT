/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkaba <lkaba@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/21 20:51:08 by lkaba             #+#    #+#             */
/*   Updated: 2020/04/02 06:38:49 by lkaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

void print_client_info(struct sockaddr_in cli_addr, int client_sock)
{
	char		str[INET_ADDRSTRLEN] = {0};

	fflush(stdout);
	printf("Connection From: %s:%d (%d)\n",
		inet_ntop( AF_INET, &cli_addr.sin_addr, str, INET_ADDRSTRLEN ), //address as dotted quad
		ntohs(cli_addr.sin_port), //the port in host order
	client_sock);
}

size_t	ft_strlen(const char *s)
{
	size_t i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	*ft_memalloc(size_t size)
{
	void *ptr;

	ptr = malloc(size);
	if (ptr == NULL)
		return (NULL);
	bzero(ptr, size);
	return (ptr);
}

char	*ft_strcpy(char *dst, const char *src)
{
	int i;

	if (!src || !dst)
		return (dst);
	i = 0;
	while (src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}


char	*ft_strnew(size_t size)
{
	return (ft_memalloc((size + 1) * sizeof(char)));
}

char	*ft_join_args(char *sep, ...)
{
	va_list		args;
	char		strdest[1024];
	char		*t;
	uint32_t	size;

	va_start(args, sep);
	memset(strdest, 0, 1024);
	while ((t = va_arg(args, char *)))
	{
		if (t && *t)
		{
			strcat(strdest, t);
			strdest[ft_strlen(strdest)] = *sep;
		}
	}
	if ((size = ft_strlen(strdest)))
		strdest[size] = 0;
	else
		return (NULL);
	va_end(args);
	return (strdup(strdest));
}
