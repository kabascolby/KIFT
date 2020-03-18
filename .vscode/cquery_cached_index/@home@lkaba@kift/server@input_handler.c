/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkaba <lkaba@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 03:33:38 by lkaba             #+#    #+#             */
/*   Updated: 2020/03/11 04:01:55 by lkaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

static void		split_input(t_myna *myna, char *input)
{
	uint8_t	i;
	char	*tmp;

	i = 0;
	while ((tmp = strtok_r(input, " ", &input)))
		myna->cmd[i++] = tmp;
}

void input_handler(char *input)
{
	t_myna	*myna;
	myna = malloc(sizeof(t_myna));
	bzero(myna, sizeof(t_myna));
	if(strstr(input, "hey myna"))
		myna->is_keyword++;
}
