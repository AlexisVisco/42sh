/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   b_env.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ggranjon <ggranjon@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/05 18:56:46 by aviscogl     #+#   ##    ##    #+#       */
/*   Updated: 2018/02/17 11:26:34 by aviscogl    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "shell.h"

static void		print_env(const t_heap *heap, size_t j)
{
	t_node *n;

	n = (t_node *)heap->list[j];
	if (n->key && n->value)
		ft_printf("%s=%s\n", n->key, n->value);
}

/*
** List all environments variables
** Take no arguments
*/

int				b_env(char **args, t_shell *shell)
{
	t_heap	*heap;
	size_t	i;
	size_t	j;

	i = 0;
	(void)args;
	while (i < shell->env->size)
	{
		heap = shell->env->heaps[i];
		j = 0;
		while (heap && heap->elements > 0 && j < heap->size)
		{
			if (heap->list[j])
				print_env(heap, j);
			j++;
		}
		i++;
	}
	return (1);
}
