/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltimsit- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/13 14:32:22 by ltimsit-          #+#    #+#             */
/*   Updated: 2019/08/15 14:41:32 by ltimsit-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DISPLAY_H
# define DISPLAY_H

# include "lem_in.h"
# include "mlx.h"
# define WIN_LEN 1600
# define WIN_HGT 1080
# define TUBE_COLOR 0xFF009A
# define ROOM_COLOR 0xC8FFFF
# define START_COLOR 0x64E564
# define END_COLOR 0xFFFF9A
# define NAME_COLOR 0x000000
# define RAD M_PI / 180

typedef struct		s_roomlx
{
	int				index;
	int				x;
	int				y;
	char			*name;
}					t_roomlx;

typedef struct		s_bresen
{
	int				ax;
	int				bx;
	int				ay;
	int				by;
	int				dx;
	int				dy;
	int				sx;
	int				sy;
	int				delta;
	int				e2;
	int				color;
	double			angle;
	void			*img_rot;
	char			*data_rot;
	int				x_b;
	int				y_b;
}					t_bresen;

typedef	struct		s_coord
{
	int				x;
	int				y;
}					t_coord;

typedef struct		s_mlx
{
	void			*mlx;
	void			*win;
	void			*img;
	char			*data_img;
	char			*data_ant;
	int				mouse_room;
	int				of_x;
	int				of_y;
	int				div;
	int				play;
	int				speed;
	t_data			*data;
	void			*xpm_tab;
	void			*bg_xpm;
	char			*bg_data;
	t_bresen		**b_tab;
	int				cpt;
}					t_mlx;

/*
** display_setup.c  ------------------------------------------------------------
*/
char				*get_data_ptr(void *img_ptr);
int					get_xpm_data(t_mlx *mlx);
int					make_display_tuboard(t_data *data);
int					clear_image(t_mlx *mlx);

/*
** rooms_display.c  ------------------------------------------------------------
*/
int					coord_to_room(t_mlx *mlx, int x, int y);
void				print_name_room(t_data *data, t_mlx *mlx);
int					set_rooms(t_data *data, t_mlx *mlx);
int					display_room(t_mlx *mlx, int x, int y, int color);

/*
** hook.c           ------------------------------------------------------------
*/
void				parse_line(char *line, t_mlx *mlx);
int					mouse_move(int x, int y, t_mlx *mlx);
int					mouse_press(int button, int x, int y, t_mlx *param);
int					mouse_release(int button, int x, int y, t_mlx *param);
int					key_press(int keycode, t_mlx *dis);

/*
** display.c        ------------------------------------------------------------
*/
int					print_all(t_mlx *mlx);
int					get_ofsets(t_data *data, t_mlx *mlx);
double				get_angle(t_bresen *b_tab);
void				draw_tubes(t_data *data, t_mlx *mlx);
int					draw_path(t_mlx *mlx, t_bresen **b_tab);

/*
** init_display.c   ------------------------------------------------------------
*/
int					init_draw_path(t_mlx *mlx, t_bresen **b_tab, int cur_pos);
int					init_b_tab(t_mlx *mlx, int size);
int					init_mlx_struct(t_mlx *mlx, t_data *data);
int					init_display(t_data *data);

/*
** tube_display.c   ------------------------------------------------------------
*/
void				bresen_line(t_mlx *mlx, t_bresen bres);
int					bresen_path(t_bresen *bres, int *data, int color, int ret);
void				init_path_bresen(t_mlx *mlx, t_room *a, t_room *b,
					t_bresen *b_tab);
void				init_bresen(t_mlx *mlx, t_room *a, t_room *b, int color);

/*
** rotation_ant.c   ------------------------------------------------------------
*/
void				print_ant(t_mlx *mlx, char *line, int i, int k);
int					init_rotate_img(t_mlx *mlx, t_bresen *b_tab);
int					clear_rot_img(int *rot);
int					create_rotated_img(t_mlx *mlx, double angle, int *rot);
/*
** dis_free.c
*/
int					exit_display(t_mlx *mlx);
int					free_display(t_mlx *mlx);

#endif
