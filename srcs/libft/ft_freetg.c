/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_freetg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtacos <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 23:26:51 by rtacos            #+#    #+#             */
/*   Updated: 2019/09/19 17:49:01 by rtacos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_freetg(char **tg, size_t w)
{
	size_t	i;

	i = 0;
	while (i < w)
		ft_strdel(&tg[i++]);
	free(tg);
	tg = NULL;
}