/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gilee <gilee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 01:55:38 by gilee             #+#    #+#             */
/*   Updated: 2021/11/30 04:57:02 by gilee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

t_LinkedStack	*createLinkedStack(void)
{
	return ((t_LinkedStack *)createArrayList(1));
}

int	pushLS(t_LinkedStack *pStack, t_StackNode element)
{
	if (addALElement((t_ArrayList *)pStack, 0, element))
		return (TRUE);
	return (FALSE);
}

t_StackNode	*popLS(t_LinkedStack	*pStack)
{
	t_StackNode	*tmp;

	tmp = (t_StackNode *)calloc(1, sizeof(t_StackNode));
	if (pStack->currentElementCount)
	{
		tmp->data = pStack->pTopElement->data;
		removeALElement((t_ArrayList *)pStack, 0);
	}
	return (tmp);
}

t_StackNode	*peekLS(t_LinkedStack *pStack)
{
	return (pStack->pTopElement);
}

int	isLinkedStackEmpty(t_LinkedStack *pStack)
{
	if (pStack->currentElementCount)
		return (FALSE);
	return (TRUE);
}
