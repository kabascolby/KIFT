/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brightness.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkaba <lkaba@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/13 21:25:29 by ttran             #+#    #+#             */
/*   Updated: 2020/03/11 08:40:40 by lkaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../client/client.h"

/*
** int system(const char *command) allows for the execution of shell commands
** system("command");
** Should this be int main(int argc, char **argv) or any function?
** Backslash to handle ""
** brew install brightness
*/

// int brightness(char *brightness_value)
// {
// 	if (strcmp("zero", "brightness_value") == 0)
// 		system("sh brightness.script 0");
// 	else if (strcmp("one", "brightness_value") == 0)
// 		system("sh brightness.script 0.1");
// 	else if (strcmp("two", "brightness_value") == 0)
// 		system("sh brightness.script 0.2");
// 	else if (strcmp("third", "brightness_value") == 0)
// 		system("sh brightness.script 0.3");
// 	else if (strcmp("four", "brightness_value") == 0)
// 		system("sh brightness.script 0.4");
// 	else if (strcmp("five", "brightness_value") == 0)
// 		system("sh brightness.script 0.5");
// 	else if (strcmp("six", "brightness_value") == 0)
// 		system("sh brightness.script 0.6");
// 	else if (strcmp("seven", "brightness_value") == 0)
// 		system("sh brightness.script 0.7");
// 	else if (strcmp("eight", "brightness_value") == 0)
// 		system("sh brightness.script 0.8");
// 	else if (strcmp("nine", "brightness_value") == 0)
// 		system("sh brightness.script 0.9");
// 	else if (strcmp("ten", "brightness_value") == 0)
// 		system("sh brightness.script 1");
// 	else
// 		system("say \"Value between 0 and 10\"");
// 	return (0);
// }

int light(char *argv)
{
	int count = 16;

	if(!strcmp(argv, "on"))
	{
		// while(--count)
		// 	system("osascript -e \'tell application \"System Events\" key code 144 end tell\'");
		system("say -v Light on");
	}
	else
	{
		// while(--count)
		// 	system("osascript -e \'tell application \"System Events\" key code 145 end tell\'");
		system("say -v It's always better to save the energy");
	}
	return (0);
}

