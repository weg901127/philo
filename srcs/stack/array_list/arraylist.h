/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arraylist.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gilee <gilee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 01:38:40 by gilee             #+#    #+#             */
/*   Updated: 2021/11/30 04:56:25 by gilee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAYLIST_H
# define ARRAYLIST_H

# include <stdlib.h>
# include <string.h>
typedef struct s_ArrayListNodeType
{
	int	data;
}	t_ArrayListNode;

typedef struct s_ArrayListType
{
	int				currentElementCount;
	int				maxElementCount;
	t_ArrayListNode	*pElement;
}	t_ArrayList;

/* arraylist.c */
t_ArrayList		*createArrayList(int maxElementCount);
void			deleteArrayList(t_ArrayList *pList);
int				addALElement(t_ArrayList *pList,
					int position, t_ArrayListNode element);
int				removeALElement(t_ArrayList *pList, int position);
t_ArrayListNode	*getALElement(t_ArrayList *pList, int position);
/* array_utils.c */
void			clearArrayList(t_ArrayList *pList);
int				getArrayListLength(t_ArrayList *pList);
int				isArrayListFull(t_ArrayList *pList);

# ifndef _COMMON_LIST_DEF_
#  define _COMMON_LIST_DEF_

#  define TRUE		1
#  define FALSE		0

# endif
#endif
