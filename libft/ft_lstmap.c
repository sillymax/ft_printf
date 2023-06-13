/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychng <ychng@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 18:22:20 by ychng             #+#    #+#             */
/*   Updated: 2023/05/08 18:57:21 by ychng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	void	has_node(t_list **head, t_list *newnode, t_list **temp)
{
	if (*head == 0)
	{
		*head = newnode;
		*temp = newnode;
	}
	else
	{
		(*temp)-> next = newnode;
		*temp = newnode;
	}
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*head;
	t_list	*newnode;
	t_list	*temp;

	if (!lst || !f || !del)
		return (NULL);
	head = 0;
	temp = 0;
	while (lst != 0)
	{
		newnode = malloc(sizeof(t_list));
		if (!newnode)
			return (NULL);
		newnode -> content = (*f)(lst -> content);
		newnode -> next = 0;
		has_node(&head, newnode, &temp);
		lst = lst -> next;
	}
	return (head);
}
