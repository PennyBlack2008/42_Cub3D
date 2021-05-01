/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikang <jikang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 09:54:53 by jikang            #+#    #+#             */
/*   Updated: 2020/04/14 13:31:58 by jikang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_head;
	t_list	*curr;
	t_list	*temp;

	if (lst == 0 || !(new_head = ft_lstnew(f(lst->content))))
		return (0);
	curr = new_head;
	temp = lst->next;
	while (temp)
	{
		if (!(curr->next = ft_lstnew(f(temp->content))))
		{
			ft_lstclear(&new_head, del);
			return (0);
		}
		curr = curr->next;
		temp = temp->next;
	}
	return (new_head);
}
