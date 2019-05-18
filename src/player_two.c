/*
** EPITECH PROJECT, 2019
** player_two
** File description:
** player_two
*/

#include "../include/navy.h"

void loop_receive_ptwo(glob_t *src, pid_t pid, char *input)
{
    send_signal(input, pid);
    my_putstr(my_strcat(input, ": "));
    pause();
    if (get_signal(-1) == SIGUSR1) {
        my_putstr(MSG_HIT);
        write_map(src, input, 2, 'x');
    } else {
        my_putstr(MSG_MISSED);
        write_map(src, input, 2, 'o');
    }
    usleep(5000);
    kill(pid, SIGUSR2);
    usleep(5000);
    kill(pid, SIGUSR2);
}

int game_loop_ptwo(glob_t *src, pid_t pid)
{
    char *input = "";

    my_putstr(MSG_WAITING_ATT);
    if (find_in_map(recept_signal(), src))
        return (PROBLEM);
    win(src, 2);
    if (src->winner != -1)
        return (SUCCESS);
    pause();
    my_putstr(MSG_ATTACK);
    if ((input = get_next_line(0)) == NULL)
        return (PROBLEM);
    while (my_strlen(input) != 2 || (input[0] > 'H' || input[0] < 'A') ||
        (input[1] < '1' || input[1] > '8')) {
        my_putstr(ERR_WG_POS MSG_ATTACK);
        if ((input = get_next_line(0)) == NULL)
            return (PROBLEM);
    }
    loop_receive_ptwo(src, pid, input);
    return (SUCCESS);
}

int game_player_two(glob_t *src)
{
    int end = 0;

    while (src->winner == -1) {
        print_game(src, 1);
        print_game(src, 2);
        if ((end = game_loop_ptwo(src, src->pid)) == PROBLEM) {
            usleep(5000);
            kill(src->pid, SIGUSR2);
            return (SUCCESS);
        } else if (end == FAILURE) {
            return (FAILURE);
        }
        if ((end = src->winner) == -1)
            win(src, 2);
    }
    destruct(src);
    return (end);
}

int init_player_two(pid_t enemy_pid)
{
    signal(SIGUSR1, signal_connection);
    signal(SIGUSR2, signal_connection);
    my_printf(MSG_PID, getpid());
    usleep(5000);
    if (kill(enemy_pid, SIGUSR1)) {
        my_printf("%m\n");
        return (1);
    }
    pause();
    my_printf(MSG_SUCCESS_CO);
    return (0);
}

int player_two(int enemy_pid, char **map)
{
    glob_t *src = create_struct(enemy_pid, map);

    if (map == NULL) {
        my_putstr(ERR_WG_MAP);
        return (FAILURE);
    }
    if (init_player_two(enemy_pid))
        return (FAILURE);
    signal(SIGUSR1, signal_handler);
    signal(SIGUSR2, signal_handler);
    return (game_player_two(src));
}