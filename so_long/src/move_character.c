/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_character.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtripodi <mtripodi@student.42adel.o>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 06:59:50 by mtripodi          #+#    #+#             */
/*   Updated: 2025/01/28 14:40:07 by mtripodi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/**
 * @brief both move_duck_img and move_duck_exit are called after checking
 * if the duck is able to move to the coordinates. It will put a grass tile
 * where the duck used to be, and place the duck img at the new tile.
 *
 * Vicotry = 1 is set in the event of duck being on the exit. It is set here
 * as its the last action in the loop before other calculations have been done.
 * If i set it anywhere else, it would call the victory too soon.
*/
void	move_duck_exit(t_data *app, t_duck duck_next, t_duck duck_past)
{
	mlx_put_image_to_window(app->mlx, app->win, app->textures[4],
		duck_next.x * 64, duck_next.y * 64);
	mlx_put_image_to_window(app->mlx, app->win, app->textures[0],
		duck_past.x * 64, duck_past.y * 64);
	place_win(app, app->map);
	app->victory = 1;
}

void	move_duck_img(t_data *app, t_duck duck_next, t_duck duck_past)
{
	mlx_put_image_to_window(app->mlx, app->win, app->textures[4],
		duck_next.x * 64, duck_next.y * 64);
	mlx_put_image_to_window(app->mlx, app->win, app->textures[0],
		duck_past.x * 64, duck_past.y * 64);
}
