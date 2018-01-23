/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ef_move_left.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aviscogl <aviscogl@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/23 20:31:56 by aviscogl     #+#   ##    ##    #+#       */
/*   Updated: 2018/01/23 20:45:58 by aviscogl    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "editor.h"

void	ef_move_left(t_editor *l)
{
	if (l->pos > 0)
    {
        l->pos--;
        refresh_line(l);
    }
}