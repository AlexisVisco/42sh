/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   handle_keys.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aviscogl <aviscogl@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/22 10:47:39 by aviscogl     #+#   ##    ##    #+#       */
/*   Updated: 2018/01/22 13:21:41 by aviscogl    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "editor.h"

#define ISK(kecyode) (key == keycode)

static int	hook_keys(uint64_t key)
{
	
	return (1);
}

void		handle_keys(t_editor *e)
{
	char		*seq[10];

	ft_memset(seq, 0, 10);
	while (read(0, seq, 10) > 0 && hook_keys((uint64_t)*seq))
		ft_memset(seq, 0, 10);
	ft_putchar_fd(e->ofd, '\n');
}