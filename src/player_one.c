/*
** EPITECH PROJECT, 2019
** player_one
** File description:
** player_one
*/

#include "../include/navy.h"

int loop_receive_pone(glob_t *src, pid_t pid, char *input)
{
    pause();
    if (get_signal(-1) == SIGUSR1) {
        my_putstr(MSG_HIT);
        write_map(src, input, 2, 'x');
    } else {
        my_putstr(MSG_MISSED);
        write_map(src, input, 2, 'o');
    }
    usleep(5000);
    win(src, 1);
    kill(pid, SIGUSR2);
    if (src->winner == -1) {
        my_putstr(MSG_WAITING_ATT);
        if (find_in_map(recept_signal(), src))
            return (PROBLEM);
        pause();
    }
    return (SUCCESS);
}

int game_loop_pone(glob_t *src, pid_t pid)
{
    char *input = "";

    my_putstr(MSG_ATTACK);
    if ((input = get_next_line(0)) == NULL)
        return (PROBLEM);
    while (my_strlen(input) != 2 || (input[0] > 'H' || input[0] < 'A') ||
        (input[1] < '1' || input[1] > '8')) {
        my_putstr(ERR_WG_POS MSG_ATTACK);
        if ((input = get_next_line(0)) == NULL)
            return (PROBLEM);
    }
    send_signal(input, pid);
    my_putstr(my_strcat(input, ": "));
    if (loop_receive_pone(src, pid, input) == PROBLEM)
        return (PROBLEM);
    return (SUCCESS);
}

int game_player_one(glob_t *src)
{
    int end = 0;

    while (src->winner == -1) {
        print_game(src, 1);
        print_game(src, 2);
        if ((end = game_loop_pone(src, src->pid)) == PROBLEM) {
            usleep(5000);
            kill(src->pid, SIGUSR2);
            return (SUCCESS);
        }
        if ((end = src->winner) == -1)
            win(src, 1);
    }
    destruct(src);
    return (end);
}

int init_player_one(glob_t *src)
{
    struct sigaction sa;

    sa.sa_flags = SA_SIGINFO;
    sa.sa_sigaction = sig_get_enemy_pid;
    signal(SIGUSR1, signal_connection);
    signal(SIGUSR2, signal_connection);
    if (sigaction(SIGUSR1, &sa, NULL)) {
        my_printf("%m\n");
        return (1);
    }
    my_printf(MSG_PID MSG_WAITING_CO, getpid());
    pause();
    my_printf(MSG_ENEMY_CO);
    usleep(5000);
    kill(get_enemy_pid(-1), SIGUSR1);
    src->pid = get_enemy_pid(-1);
    return (0);
}

int player_one(char **map)
{
    glob_t *src = create_struct(0, map);

    if (map == NULL) {
        my_putstr(ERR_WG_MAP);
        return (FAILURE);
    }
    if (init_player_one(src))
        return (FAILURE);
    signal(SIGUSR1, signal_handler);
    signal(SIGUSR2, signal_handler);
    return (game_player_one(src));
}