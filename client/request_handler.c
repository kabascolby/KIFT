/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   request_handler.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkaba <lkaba@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 20:05:20 by lkaba             #+#    #+#             */
/*   Updated: 2020/03/11 08:39:31 by lkaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

static int8_t		get_index(char *cmd, char *builtins)
{
	uint8_t	i;
	uint8_t ftpr_size;
	char	*tmp;

	i = 0;
	while ((tmp = strtok_r(builtins, " ", &builtins)))
	{
		if (cmd && !strcmp(cmd, tmp))
			break ;
		i++;
	}

	ftpr_size = sizeof(cmd_fptr) / sizeof(*cmd_fptr);

	/* Bondry checking for security purpose */
	printf("index = %d  | ptr_size = %d\n", i, ftpr_size);
	return (tmp ? i : ftpr_size - 1);
}

static void		split_input(char **args, char *input)
{
	uint8_t	i;
	char	*tmp;

	i = 0;
	while ((tmp = strtok_r(input, " ", &input)))
		args[i++] = tmp;
}

/* The higher index will be invalide commad */

void			server_request_handler(char *request)
{
	char *args[3];

	// args = (char *[3]){0};

	split_input(args, request);

	if (cmd_fptr[get_index(args[0], strdup(BUILTINS))](args[1]))
	{
		printf("invalide command\n");
	}
}
