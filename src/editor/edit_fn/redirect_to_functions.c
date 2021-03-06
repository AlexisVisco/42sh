/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   redirect_to_functions.c                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ggranjon <ggranjon@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/23 20:04:51 by aviscogl     #+#   ##    ##    #+#       */
/*   Updated: 2018/04/14 13:45:45 by ggranjon    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <builtins.h>
#include "editor.h"

#define ISK(k) (k == c)

static t_redirect_fn	*ctrl_fn(char c)
{
	if (ISK(CTRL_T))
		return (ef_swap_char);
	if (ISK(CTRL_U))
		return (ef_delete_entire_line);
	if (ISK(CTRL_K))
		return (ef_delete_curr_to_end);
	if (ISK(CTRL_A))
		return (ef_go_home);
	if (ISK(CTRL_E))
		return (ef_go_end);
	if (ISK(CTRL_L))
		return (ef_clear_screen);
	if (ISK(CTRL_B))
		return (ef_move_left);
	if (ISK(CTRL_F))
		return (ef_move_right);
	if (ISK(CTRL_W))
		return (ef_del_prev_word);
	if (ISK(CTRL_I))
		return (ef_move_down);
	if (ISK(CTRL_O))
		return (ef_move_up);
	return (0);
}

static t_redirect_fn	*extra_fn(t_editor *l, char *seq)
{
	if ((seq[1] >= '0' && seq[1] <= '9') && read(l->ifd, seq + 2, 1) != -1)
	{
		if (seq[2] == '~' && seq[1] == '3')
			return (ef_del_simple);
		if (read(l->ifd, seq + 3, 1) == -1 || read(l->ifd, seq + 4, 1) == -1)
			return (NULL);
		else if (ft_strequ("[1;2A", seq))
			return (ef_move_up);
		else if (ft_strequ("[1;2B", seq))
			return (ef_move_down);
		else if (ft_strequ("[1;2D", seq))
			return (ef_move_word_left);
		else if (ft_strequ("[1;2C", seq))
			return (ef_move_word_right);
	}
	return (NULL);
}

static t_redirect_fn	*normal_fn(char c, t_editor *e)
{
	if (c == 'C')
		return (ef_move_right);
	if (c == 'D')
		return (ef_move_left);
	if (c == 'A' && e->options->has_history)
		return (history_up);
	if (c == 'B' && e->options->has_history)
		return (history_down);
	if (c == 'H')
		return (ef_go_home);
	if (c == 'F')
		return (ef_go_end);
	return (NULL);
}

static t_redirect_fn	*esc_fn(t_editor *l, char *seq)
{
	t_redirect_fn	*fn;

	if (read(l->ifd, seq, 1) == -1 || read(l->ifd, seq + 1, 1) == -1)
		return (NULL);
	if (seq[0] == '[')
	{
		if ((fn = extra_fn(l, seq)))
			return (fn);
		else if ((fn = normal_fn(seq[1], l)))
			return (fn);
	}
	else if (seq[0] == '0')
		if ((fn = normal_fn(seq[1], l)))
			return (fn);
	return (0);
}

/*
** This function redirect keys entered to edit functions.
** An edit function take a (t_ediror *) in parameter and
** return nothing.
*/

void					redirect_key_fn(t_editor *e, char c, char *seq)
{
	t_redirect_fn *func;

	if (ISK(CTRL_H))
	{
		prepare_history(e);
		history_search(e);
	}
	else if (!redirect_control_key(e, c) && e->mode == COMPLETION)
		completion_delete(e);
	if ((ISK(ESC) && (func = esc_fn(e, seq))) ||
		(func = ctrl_fn(c)) ||
		(ISK(BACKSPACE) && (func = ef_del_backspace)))
	{
		func(e);
		refresh_line(e);
	}
	else if (ft_isprint(c))
		editor_insert(e, c);
}
