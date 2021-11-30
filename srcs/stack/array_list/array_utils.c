/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gilee <gilee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 01:37:38 by gilee             #+#    #+#             */
/*   Updated: 2021/11/30 01:50:16 by gilee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arraylist.h"

void	clearArrayList(t_ArrayList *pList)
{
	free(pList->pElement);
	pList->pElement = NULL;
	pList->currentElementCount = 0;
}

int	getArrayListLength(t_ArrayList *pList)
{
	return (pList->currentElementCount);
}

int	isArrayListFull(t_ArrayList *pList)
{
	return (pList->maxElementCount == pList->currentElementCount);
}
