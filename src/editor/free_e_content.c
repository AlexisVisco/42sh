/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   free_e_content.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ggranjon <ggranjon@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/31 14:35:39 by aviscogl     #+#   ##    ##    #+#       */
/*   Updated: 2018/04/14 13:45:45 by ggranjon    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "editor.h"

/*
** Free type of t_e_content used in autocompletion or in history
*/

void	free_e_content(t_e_content *h)
{
	if (h)
	{
		heap_free(h->heap);
		ft_memdel((void **)&h);
	}
}
