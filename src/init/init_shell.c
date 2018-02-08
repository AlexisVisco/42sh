/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   init_shell.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aviscogl <aviscogl@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/31 18:49:36 by aviscogl     #+#   ##    ##    #+#       */
/*   Updated: 2018/02/08 11:30:04 by aviscogl    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "shell.h"
#include "f_colors.h"

/*
** Display a fun and cool message when shell start !
*/

static void		print_welcome_message(void)
{
	const char		*message = "Welcome";
	const size_t	len = ft_strlen(message);
	const size_t	len_tr = 54;

	ft_printf("\n╭───────────────────────────────────────────────────────╮\n");
	ft_printf("│%*s│\n", len_tr + 1, " ");
	ft_printf("│%s%*s%-*s%s│\n", CYAN,
	len + ((len_tr - len) / 2) + 1, message,
	((len_tr - len) / 2) + ((len % 2 == 0) ? 0 : 1), " ", RESET_ALL);
	ft_printf("│%*s│\n", len_tr + 1, " ");
	ft_printf("╰───────────────────────────────────────────────────────╯\n\n");
}

/*
** Here init the shell, get all environements variables, get all binaries
** and create a hashtable and create a trie data structure for autocompletion
** of binaries, set options for readline : line edition mode and history search
** mode.
** Set builtins names in the completion for binairy.
*/

void			init_shell(void)
{
	print_welcome_message();
	set_env();
	set_bin(&g_shell);
	set_options();
	set_builtins();
}
