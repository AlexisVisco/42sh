/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   env_to_array.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ggranjon <ggranjon@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/30 11:45:37 by ggranjon     #+#   ##    ##    #+#       */
/*   Updated: 2018/04/14 13:45:45 by ggranjon    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "shell.h"

static void		put_in_array(char **env, int *k, t_hashtable *x)
{
	t_hashtable	*t;
	size_t		i;
	int64_t		j;
	char		*str;

	i = 0;
	t = x;
	while (i < t->size)
	{
		if (t->heaps[i])
		{
			j = -1;
			while (++j < (int64_t)t->heaps[i]->size)
			{
				if (t->heaps[i]->list[j])
				{
					str = ft_sprintf("%s=%s", ((t_node *)
t->heaps[i]->list[j])->key, (char *)((t_node *)t->heaps[i]->list[j])->value);
					env[(*k)++] = str;
				}
			}
		}
		i++;
	}
}

size_t			env_size(t_hashtable *map)
{
	t_hashtable	*t;
	size_t		i;
	size_t		size;

	i = 0;
	t = map;
	size = 0;
	while (i < t->size)
	{
		if (t->heaps[i])
			size += t->heaps[i]->elements;
		i++;
	}
	return (size);
}

/*
** From the g_shell.env convert the hashtable in a array of string,
** each string take the form: key=value.
*/

char			**env_to_array(t_hashtable *envx)
{
	char		**env;
	size_t		size;
	int			k;

	size = env_size(envx);
	env = (char **)ft_memalloc((size + 1) * sizeof(char *));
	env[size] = 0;
	k = 0;
	put_in_array(env, &k, envx);
	return (env);
}
