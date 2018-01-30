/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ef_clear_screen.c                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aviscogl <aviscogl@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/23 20:31:56 by aviscogl     #+#   ##    ##    #+#       */
/*   Updated: 2018/01/25 13:58:00 by aviscogl    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "editor.h"

/*
** Clear the screen
*/

void	ef_clear_screen(t_editor *l)
{
	(void)l;
	write(STDOUT_FILENO, "\x1b[H\x1b[2J", 7);
}