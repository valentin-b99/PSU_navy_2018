/*
** EPITECH PROJECT, 2019
** signal
** File description:
** for navy
*/

#include "../include/navy.h"

int get_signal(int sig)
{
    static int last_sig = -1;

    if (sig != -1)
        last_sig = sig;
    return (last_sig);
}

void signal_handler(int sig)
{
    get_signal(sig);
}

void signal_connection(int sig)
{
    return;
}

int get_enemy_pid(int enemy_pid)
{
    static int last_pid = -1;

    if (enemy_pid != -1)
        last_pid = enemy_pid;
    return (last_pid);

}

void sig_get_enemy_pid(int sig, siginfo_t *info, void *context)
{
    get_enemy_pid(info->si_pid);
}