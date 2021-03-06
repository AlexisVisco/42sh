/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   readline_raw.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ggranjon <ggranjon@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/21 10:16:16 by aviscogl     #+#   ##    ##    #+#       */
/*   Updated: 2018/04/14 13:45:45 by ggranjon    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "editor.h"

/*
** This function calls the line editing function editor() using.
** the STDIN file descriptor set in raw mode.
*/

int		readline_raw(char *buf, char *prompt, t_options *e)
{
	int count;

	if (EDITOR_MAX_LINE <= 0 || enable_terminal(STDIN_FILENO) == -1)
		return (-1);
	count = editor(buf, prompt, e);
	disable_terminal(STDIN_FILENO);
	ft_putchar_fd(STDOUT_FILENO, '\n');
	return (count);
}
