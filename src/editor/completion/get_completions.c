/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_completions.c                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ggranjon <ggranjon@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/01 10:01:06 by aviscogl     #+#   ##    ##    #+#       */
/*   Updated: 2018/04/14 13:45:45 by ggranjon    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "shell.h"

/*
** This method insert all completions according to the type of the completion
** There is two types:
**  - TYPE_PATH
**  - TYPE_ENV
*/

void	get_completions(t_editor *e)
{
	t_word_info	info;

	info.begin = 0;
	info.end = 0;
	set_word_info(&info, e);
	if (info.current_word == NULL)
		info.current_word = ft_strdup("\0");
	if (info.type == TYPE_COMMAND)
		get_completions_bin(&info, e->options->completion_data->heap);
	else if (info.type == TYPE_PATH)
		get_completions_path(&info, e->options->completion_data->heap);
	else
		get_completions_env(&info, e->options->completion_data->heap);
	if (e->options->completion_data->origin[0] == '\0')
		ft_copy_str(e->options->completion_data->origin, info.current_word);
	if (info.current_word)
		ft_memdel((void **)&(info.current_word));
}
