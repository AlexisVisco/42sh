/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   backquotes.h                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ggranjon <ggranjon@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/04/19 15:30:03 by ggranjon     #+#   ##    ##    #+#       */
/*   Updated: 2018/04/19 20:24:20 by ggranjon    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef BACKQUOTES_H
# define BACKQUOTES_H

# include "shell.h"

typedef struct	s_backquotes
{
	int				status;
	char			*str;
}				t_backquotes;

int				seek_backquotes(t_token **tokens);

char			*extract_backq(t_token **tokens, int i, int start);
int				is_backq_in(t_token **tokens, int i);

void			escape_useless_backquotes(char *s);

char			*ft_mine_strjoin(char const *s1, char const *s2);

t_backquotes	core_exec_backquotes(t_token **tokens,
				t_block *blocks, int num[2], t_backquotes *ret);
t_backquotes	exec_backquotes(char ***argv);

void			get_backq_string(const int *p, t_backquotes *ret);
t_backquotes	error_redir(t_backquotes *ret);
void			get_backq_status(int status, t_backquotes *ret);
int				backq_quotes(char **str);

#endif
