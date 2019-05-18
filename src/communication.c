/*
** EPITECH PROJECT, 2019
** communication
** File description:
** for navy
*/

#include "../include/navy.h"

char *recept_signal(void)
{
    char *res = my_strdup("@0");

    pause();
    if (get_signal(-1) == SIGUSR2)
        return (NULL);
    while (get_signal(-1) == SIGUSR1) {
        res[0]++;
        pause();
    }
    pause();
    while (get_signal(-1) == SIGUSR1){
        res[1]++;
        pause();
    }
    return (res);
}

void send_signal(char *str, pid_t pid)
{
    int count = str[0] - 64;

    usleep(5000);
    while (count) {
        usleep(5000);
        kill(pid, SIGUSR1);
        count--;
    }
    usleep(5000);
    kill(pid, SIGUSR2);
    count = str[1] - 48;
    while (count) {
        usleep(5000);
        kill(pid, SIGUSR1);
        count--;
    }
    usleep(5000);
    kill(pid, SIGUSR2);
    usleep(5000);
}

int pid_msg(void)
{
    my_puterror(ERR_WG_PID);
    return (FAILURE);
}