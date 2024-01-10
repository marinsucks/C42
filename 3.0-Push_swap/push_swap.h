/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbecker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 15:11:12 by mbecker           #+#    #+#             */
/*   Updated: 2024/01/10 16:37:55 by mbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"

//ft_stack
t_list	*ft_getstack(int argc, char const *argv[]);

//ft_swap
void    ft_lstswap(t_list **node);
void    sa(t_list **stack_a);
void    sb(t_list **stack_b);
void    ss(t_list **stack_a, t_list **stack_b);

//test functions
void	printList(t_list *list);
void	printBoth(t_list *list_a, t_list *list_b);


#endif
