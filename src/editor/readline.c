/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   readline.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ggranjon <ggranjon@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/02 23:16:33 by aviscogl     #+#   ##    ##    #+#       */
/*   Updated: 2018/04/14 13:45:45 by ggranjon    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "shell.h"

t_termios g_origin;

/*
** Check if the terminal in the env TERM is
** supported. If not return 1.
** Else if term is supported return 0.
*/

static int	unsupported_term(void)
{
	static char	*unsupported_term[] = {"dumb", "cons25", "emacs", NULL};
	char		*term;
	int			i;

	term = ht_get(g_shell.env, "TERM");
	if (!term)
		return (1);
	i = -1;
	while (unsupported_term[++i])
		if (ft_strequ(unsupported_term[i], term))
			return (1);
	return (0);
}

/*
** This function checks if the terminal has basic capabilities, just checking
** for a blacklist of fucking stupid terminals, and later either calls
** the line editing function.
**
** Then return the line typed in the terminal.
*/

char		*readline(char *prompt, t_options *e)
{
	char	buf[EDITOR_MAX_LINE + 1];
	int		count;

	ft_bzero(buf, sizeof(buf));
	if (unsupported_term())
	{
		message_err(ERR_UNRECOGNIZED_TERM);
		exit_shell();
		exit(2);
	}
	else
	{
		count = readline_raw(buf, prompt, e);
		if (count == -1)
			return (NULL);
		return (ft_strdup(buf));
	}
}
