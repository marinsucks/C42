/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbecker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 11:01:23 by mbecker           #+#    #+#             */
/*   Updated: 2024/01/29 14:49:50 by mbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft/libft.h"
# include "minilibx-linux/mlx.h"

/**
 * @brief Structure for mlx connection and window.
*/
typedef struct s_mlx
{
	void	*cnx;
	void	*wdw;
}			t_mlx;

#endif
