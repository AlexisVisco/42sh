/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   set_word_info.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ggranjon <ggranjon@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/12 12:37:32 by aviscogl     #+#   ##    ##    #+#       */
/*   Updated: 2018/04/14 13:45:45 by ggranjon    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "editor.h"

void		get_word_at(char *cmd, size_t position, t_word_info *w)
{
	int64_t i;
	size_t	j;

	if ((cmd[position] == ' ' && position == 0) ||
		(cmd[position] == ' ' && cmd[position - 1] == ' '))
	{
		w->current_word = NULL;
		return ;
	}
	if (cmd[position] == ' ' || (position > (ft_strlen(cmd) - 1)))
		position--;
	i = (int64_t)position + 1;
	while (i > 0 && cmd[--i] != ' ')
		;
	i = i <= 0 ? 0 : i + 1;
	j = (size_t)i;
	while (cmd[++j] != ' ' && cmd[j])
		;
	j--;
	w->begin = (size_t)i;
	w->end = j;
	w->current_word = (ft_strsub(cmd, (unsigned int)i, j - (i - 1)));
}

static int	modify_x(const t_word_info *i, const t_editor *e)
{
	int x;

	x = (int)i->begin;
	while (x > 0 && e->buf[--x] == ' ')
		;
	return (x);
}

/*
** Set all information about t_word_info, the word at cursor
** Define the end, the begin of the word and the type of the word
** Sample:
**  index 3 of 'hey im really happy' -> word = 'hey', start = 0, end = 2
**  index 9 of 'hey im really happy' -> word = 'really', start = 7, end = 11
** The types are set by this rule: if the word start with a '$' it's a env
** variable, else its a command or a path
*/

void		set_word_info(t_word_info *i, t_editor *e)
{
	t_word_info	prev;

	get_word_at(e->buf, e->pos, i);
	if (word_is_env(i))
		i->type = TYPE_ENV;
	else
	{
		prev.current_word = NULL;
		get_word_at(e->buf, (size_t)modify_x(i, e), &prev);
		if (word_is_command(i, &prev))
			i->type = TYPE_COMMAND;
		else
			i->type = TYPE_PATH;
		if (prev.current_word)
			ft_memdel((void **)&(prev.current_word));
	}
}
