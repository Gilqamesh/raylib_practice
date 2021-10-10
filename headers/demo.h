#ifndef DEMO_H
# define DEMO_H

# include <stdio.h>
# include <stdlib.h>
# include "raylib.h"
# include "../library/mylib/mylib.h"
# include <fcntl.h>
# include "structs.h"
# include "defines.h"

extern int grid_size;

// Parsing functions
void	parse_map(t_mystruct *mystruct, char *mapPath);

// Initializing / Destroy functions
void	initialize_mystruct(t_mystruct *mystruct, char *mapPath);
void	load_images(t_mystruct *mystruct);
void	init_envItems(t_mystruct *mystruct);
void	init_player(t_mystruct *mystruct);
void	init_camera(t_mystruct *mystruct);
void	destroy_mystruct(t_mystruct *mystruct);

// Updating functions
void	update_camera(t_mystruct *mystruct);
void	update_player(t_mystruct *mystruct);
void	update_delta(t_mystruct *mystruct);

// Drawing functions
void	draw_background(t_mystruct *mystruct);
void	draw_map(t_mystruct *mystruct);
void	draw_abilities(t_mystruct *mystruct);
void	draw_gui(t_mystruct *mystruct);

// Utils functions
EnvItem	*createEnvItem(Rectangle rect, int blocking, Color color);

#endif
