/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   usage_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npizzi <npizzi@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/14 13:16:27 by npizzi            #+#    #+#             */
/*   Updated: 2025/06/14 14:28:37 by npizzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	usage_print(void)
{
	printf("Welcome to miniRT!\n");
	printf("Usage: miniRT [options] <filename>\n\n");
	printf("Options:\n");
	printf("  -h              Display this help text and exit\n\n");
	printf("Render Commands:\n");
	printf("  r               Re-parse the scene file and render again\n");
	printf("  l               Enable/Disable light movement\n");
	printf("  Space           Enable/Disable antialiasing\n");
	printf("  TAB             Change the current light selected\n");
	printf("  Mouse Left      Move the selected light to the mouse click");
	printf(" location (if enabled)\n");
	printf("  +               Zoom in\n");
	printf("  -               Zoom out\n");
	printf("  Arrow Keys      Rotate the camera left/right - up/down\n");
	printf("  WASD            Move   the camera left/right - up/down\n");
	return (0);
}
