/*
** EPITECH PROJECT, 2019
** comp
** File description:
** navy
*/

#ifndef NAVY_H_
#define NAVY_H_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <sys/signal.h>
#include <signal.h>
#include <string.h>
#include <wait.h>
#include <time.h>
#include <assert.h>
#include <errno.h>
#include "my.h"
#include "add_lib.h"

#ifndef MACRO
#define MACRO

#define SUCCESS 0
#define FAILURE 84
#define PROBLEM -1

#define ERR_BADARGS "Wrong number of arguments\n"
#define ERR_WG_POS "wrong position\n"
#define ERR_WG_FILE "Wrong file\n"
#define ERR_ERR_FILE "Error in file\n"
#define ERR_WG_PID "Wrong PID\n"
#define ERR_WG_MAP "Wrong map\n"

#define MSG_PID "my_pid: %d\n"
#define MSG_WAITING_CO "waiting for enemy connection...\n\n"
#define MSG_WAITING_ATT "waiting for enemy's attack...\n"
#define MSG_ENEMY_CO "enemy connected\n\n"
#define MSG_SUCCESS_CO "successfully connected\n\n"

#define MSG_WIN "I won\n"
#define MSG_LOSE "Enemy won\n"

#define MSG_HIT "hit\n\n"
#define MSG_MISSED "missed\n\n"

#define MSG_ATTACK "attack: "
#define MSG_MY_POS "my positions:\n"
#define MSG_ENEMY_POS "enemy's positions:\n"

#define LINE_GAME_POS " |A B C D E F G H\n-+---------------\n"

#define CMD_HELP "-h"
#define MSG_HELP "USAGE\n\t./navy [first_player_pid] navy_positions\n\
DESCRIPTION\n\tfirst_player_pid: only for the 2nd player. pid of the first \
player.\n\tnavy_positions: file representing the positions of the ships.\n"

#endif /* !MACRO */

#ifndef STRUCT
#define STRUCT

struct map
{
    char **map;
    char **enn;
};

typedef struct global
{
    struct map *map;
    int winner;
    int pid;
} glob_t;

#endif /* !STRUCT */

#ifndef INC
#define INC

/* communication.c */
void send_signal(char *str, pid_t pid);
char *recept_signal(void);
int pid_msg(void);

/* create_map.c */
int scan_file(char **tab, int i);
char **tab_map_next(char **tab, int i, int y, char **rules);
char **tab_map(char **tab, int i, char **rules);
char **create_map(char **tab, char *buff);
char **get_map(char *path);

/* error.c */
int verif_size(char *line);
int verif_pattern(char **tab);
int verif_file(char *path);
int fic_msg(void);
int help_msg(void);

/* game.c */
int line_without_nb(char *line);
int count_x(char **enn);
void win(glob_t *src, int player);
void print_game(glob_t *src, int player);

/* player_one.c */
int loop_receive_pone(glob_t *src, pid_t pid, char *input);
int game_loop_pone(glob_t *src, pid_t pid);
int init_player_one(glob_t *src);
int player_one(char **map);

/* player_two.c */
void loop_receive_ptwo(glob_t *src, pid_t pid, char *input);
int game_loop_ptwo(glob_t *src, pid_t pid);
int game_player_two(glob_t *src);
int game_player_one(glob_t *src);
int init_player_two(pid_t enemy_pid);
int player_two(int enemy_pid, char **map);

/* signal.c */
int get_signal(int sig);
void signal_handler(int sig);
void signal_connection(int sig);
int get_enemy_pid(int enemy_pid);
void sig_get_enemy_pid(int sig, siginfo_t *info, void *context);

/* struct.c */
glob_t *create_struct(int enemy_pid, char **map);
void destroy_array(char **tab);
void destruct(glob_t *src);

/* use_map.c */
char *modif_line(char *line, int j, char c);
void write_map(glob_t *src, char *input, int choice, char let);
int test_char_map(char c, char *list);
int find_in_map(char *input, glob_t *src);

#endif /* !INC */

#endif /* !NAVY_H_ */
