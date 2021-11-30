/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arraylist.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gilee <gilee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 01:19:30 by gilee             #+#    #+#             */
/*   Updated: 2021/11/30 01:50:19 by gilee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arraylist.h"

t_ArrayList	*createArrayList(int maxElementCount)
{
	t_ArrayList	*tmp;

	tmp = (t_ArrayList *)calloc(1, sizeof(t_ArrayList));
	tmp->maxElementCount = maxElementCount;
	tmp->currentElementCount = 0;
	tmp->pElement = (t_ArrayListNode *)calloc
		(maxElementCount, sizeof(t_ArrayListNode));
	return (tmp);
}

void	deleteArrayList(t_ArrayList *pList)
{
	free(pList->pElement);
	free(pList);
	pList = NULL;
}

int	addALElement(t_ArrayList *pList, int position, t_ArrayListNode element)
{
	t_ArrayListNode	*tmp;

	if (isArrayListFull(pList))
	{
		pList->maxElementCount *= 3;
		tmp = (t_ArrayListNode *)calloc(pList->maxElementCount,
				sizeof(t_ArrayListNode));
		memcpy(tmp, pList->pElement,
			pList->currentElementCount * sizeof(t_ArrayListNode));
		free(pList->pElement);
		pList->pElement = tmp;
	}
	if ((pList->currentElementCount && position > pList->currentElementCount))
		return (FALSE);
	memmove(pList->pElement + position + 1, pList->pElement + position,
		sizeof(t_ArrayListNode) * (pList->currentElementCount - position));
	*(pList->pElement + position) = element;
	(pList->currentElementCount)++;
	return (TRUE);
}

int	removeALElement(t_ArrayList *pList, int position)
{
	t_ArrayListNode	*tmp;

	if (position >= pList->currentElementCount
		|| pList->currentElementCount == 0)
		return (FALSE);
	memmove(pList->pElement + position, pList->pElement + position + 1,
		sizeof(t_ArrayListNode) * (pList->currentElementCount - position));
	(pList->currentElementCount)--;
	return (TRUE);
}

t_ArrayListNode	*getALElement(t_ArrayList *pList, int position)
{
	if (position < pList->maxElementCount)
		return (pList->pElement + position);
	return (NULL);
}
