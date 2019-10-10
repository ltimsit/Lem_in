/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltimsit- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/07 14:44:29 by ltimsit-          #+#    #+#             */
/*   Updated: 2019/08/15 14:44:42 by ltimsit-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include <string.h>
# include <stdbool.h>

# define BUF_INPUT 4096
# define BUF_WRITE 4096
# define INTMAX 2147483647
# define INTMIN -2147483648

# define P1 data->path_1
# define P2 data->path_2
# define PMAX data->path_max

# define TUBOARD data->tuboard
# define DIS_TUBOARD data->dis_tuboard
# define ROOMS data->rooms
# define HEAD data->head
# define SIZE data->size

# define RINDEX room->index
# define DADINDEX room->dad_ptr->index
# define REDADINDEX room->dad_ptr_red->index

int					g_fd_test;

typedef struct		s_room
{
	char			*name;
	int				x;
	int				y;
	int				mlx_x;
	int				mlx_y;
	bool			start;
	bool			end;
	bool			seen;
	int				ant_num;
	int				dfs;
	int				dfs_red;
	int				index;
	struct s_room	*dad_ptr;
	struct s_room	*dad_ptr_red;
	bool			red;
	bool			dad_red;
	struct s_room	*next;
}					t_room;

typedef struct		s_path
{
	int				id;
	int				*size_path;
	int				*ant_per_path;
	int				**path_tab;
	int				nb_path;
	struct s_path	*next;
}					t_path;

typedef struct		s_data
{
	int				fd;
	int				nb_ant;
	int				round;
	int				path_max;
	t_room			*room;
	int				size;
	t_room			*head;
	t_room			*tail;
	t_room			**rooms;
	int				**tuboard;
	int				**dis_tuboard;
	int				next_start;
	int				next_end;
	t_path			*path_1;
	t_path			*path_2;
	char			*input;
	int				len_input;
	int				len_max;
	bool			list_on;
	bool			display;
	char			path[412];
	int				path_size;
}					t_data;

/*
** main.c
*/
int					get_fd(char *av0, int ac, t_data *data, char **av);
int					init_data(t_data *data);
int					print_error(int o);
int					init_display(t_data *data);

/*
** debug.c
*/
void				print_tuboard(t_data *data, int o);
void				print_path_tab(t_data *data);
void				print_path_list(t_data *data);

/*
**					**************  T O O L S  *************
*/

/*
** display_setup.c
*/
int					make_display_tuboard(t_data *data);

/*
** parsing_tools.c
*/
int					skip_sp(char *line, int i);
int					skip_nosp(char *line, int j);
int					skip_digit(char *line, int j);
int					skip_nodigit(char *line, int j);
int					check_bad_info(t_data *data);

/*
** path_tools.c
*/
int					check_nb_round(t_data *data, t_path *path, int ant);
int					init_path_12(t_data *data);
int					create_path_1_and_2(t_data *data);
int					get_max_path_nb(t_data *data);
int					stock_path(t_data *data, t_path *path, int i);

/*
** path_tools2.c
*/
int					check_for_cut(t_data *data);
int					stock_and_skip(t_data *data, t_path *p1, int i);
int					add_path(t_data *data, int *i, int j);
void				room_refresher(t_room *room);
void				enfiler(t_data *data, t_room *room, t_room *head, int o);

/*
** path_tools3.c
*/
void				subqueue(t_room *room, t_room *tail, t_room *head);
void				chain(t_data *data, t_room *room, int jump);
void				subtree(t_data *data, t_room *room, t_room *son);
void				tuboard_cut(t_data *data, t_room *room);

/*
** print_tools.c
*/
char				*resize_input(t_data *data, int *index);
char				*strcat_lemin(char *s1, char *s2, int *index, t_data *data);
void				itobuf(int n, char *str, int *ibuf);

/*
** free.c
*/
int					free_path_data(t_path *path);
int					free_path_tab(t_data *data, int i);
int					free_data(t_data *data);

/*
**					**************  G E T    I N F O  **************
*/

/*
** get_data.c
*/
int					get_line(char **line, t_data *data);
int					get_room_info(t_data *data, char **line);
int					get_nb_ant(t_data *data, char *line);
int					get_hash(char *line, t_data *data);
int					check_room(t_data *data, char *line);

/*
** get_tube.c
*/
int					add_tube(t_data *data, int s1, int s2);
int					check_name(t_data *data, char *line, int size);
int					check_tube(t_data *data, char *line);
int					get_tube(t_data *data, char *line);
int					init_get_tube(t_data *data, char *line);

/*
** make_list.c
*/
t_room				*free_list(t_room *head);
void				reset_room(t_room *newroom);
t_room				*lst_add_room(t_data *data, t_room *newroom);
t_room				*list_room_new(char *name, size_t name_size, t_data *data);

/*
** make_tuboard_and_rooms.c
*/
int					room_nbr(t_data *data);
int					make_tuboard(int size, t_data *data);
void				clean_next_and_get_index(t_data *data, int size);
int					make_rooms(int size, t_data *data);

/*
**					************** P A T H   F I N D I N G **************
*/

/*
** find_path.c
*/
int					red_bfs(t_data *data, int option);
int					do_path(t_data *data, int path_num);
void				path_finding(t_data *data);

/*
** refresh_paths.c
*/
int					update_tuboard(t_data *data);
int					refresh_rooms(t_data *data, int option);
int					cut(t_data *data, t_room *room, int son, int *cut_yes);
int					cut_edge(t_data *data);
int					refresh_tuboard(t_data *data, int *tuboard, int x);

/*
** print_result.c
*/
void				get_round(t_data *data, char *buf, int *ibuf, int path_nb);
void				result(t_data *data, t_path *path, int ant_num, int ibuf);
int					print_input(t_data *data);

#endif
