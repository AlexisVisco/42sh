/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   lst_add.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aviscogl <aviscogl@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/12 17:19:00 by aviscogl     #+#   ##    ##    #+#       */
/*   Updated: 2018/02/17 11:26:34 by aviscogl    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	lst_add(t_list **list, t_list *new)
{
	if (!*list)
		*list = new;
	else
	{
		new->next = *list;
		*list = new;
	}
}
