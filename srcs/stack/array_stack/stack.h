/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gilee <gilee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 01:51:35 by gilee             #+#    #+#             */
/*   Updated: 2021/11/30 02:01:33 by gilee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H
# include "../array_list/arraylist.h"
typedef t_ArrayListNode	t_StackNode;
typedef struct s_LinkedStackType
{
	int			currentElementCount;
	int			maxElementCount;
	t_StackNode	*pTopElement;
}	t_LinkedStack;

t_LinkedStack	*createLinkedStack(void);
int				pushLS(t_LinkedStack *pStack, t_StackNode element);
t_StackNode		*popLS(t_LinkedStack *pStack);
t_StackNode		*peekLS(t_LinkedStack *pStack);
int				isLinkedStackFull(t_LinkedStack *pStack);
int				isLinkedStackEmpty(t_LinkedStack *pStack);
#endif
