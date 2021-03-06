/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   block.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ggranjon <ggranjon@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/23 14:07:56 by ggranjon     #+#   ##    ##    #+#       */
/*   Updated: 2018/04/14 17:23:49 by ggranjon    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "shell.h"

/*
** count sep to malloc extract blocks
*/

int			count_blocks(t_token **tokens)
{
	int	i;
	int	block;

	i = 0;
	block = 0;
	while (tokens[i])
	{
		while (tokens[i] && ft_strcmp(tokens[i]->value, "&") &&
		(tokens[i]->value[0] != ';' || tokens[i]->type == COMMAND) &&
		ft_strcmp(tokens[i]->value, "&;") && ft_strcmp(tokens[i]->value, "&|"))
			i++;
		block++;
		if (tokens[i] && (ft_strcmp(tokens[i]->value, "&") == 0 ||
		tokens[i]->value[0] == ';' || ft_strcmp(tokens[i]->value, "&|") == 0
		|| ft_strcmp(tokens[i]->value, "&;") == 0))
			i++;
	}
	return (block);
}

/*
** extract blocks, a block is separed by a &, ;, &| or &;
*/

t_block		*extract_blocks(t_token **tokens)
{
	int		i;
	int		j;
	t_block	*blocks;
	int		begin;

	blocks = ft_memalloc(sizeof(t_block) * (count_blocks(tokens) + 1));
	i = 0;
	j = 0;
	while (tokens[i])
	{
		ft_bzero(&(blocks[j]), sizeof(t_block));
		begin = i;
		while (tokens[i] && ft_strcmp(tokens[i]->value, "&") &&
		(tokens[i]->value[0] != ';' || tokens[i]->type == COMMAND) &&
		ft_strcmp(tokens[i]->value, "&;") && ft_strcmp(tokens[i]->value, "&|"))
			i++;
		blocks[j].start_tok = begin;
		blocks[j++].end_tok = i == 0 ? i : i - 1;
		if (tokens[i] && (ft_strcmp(tokens[i]->value, "&") == 0 ||
		tokens[i]->value[0] == ';' || ft_strcmp(tokens[i]->value, "&;") == 0
		|| ft_strcmp(tokens[i]->value, "&|") == 0))
			i++;
	}
	blocks[j].start_tok = -1;
	return (blocks);
}
