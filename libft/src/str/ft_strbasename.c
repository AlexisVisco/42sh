/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strbasename.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aviscogl <aviscogl@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/02 09:46:41 by aviscogl     #+#   ##    ##    #+#       */
/*   Updated: 2018/02/17 11:26:34 by aviscogl    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strbasename(const char *filename)
{
	char *p;

	p = ft_strrchr(filename, '/');
	return (p ? p + 1 : (char *)filename);
}
