/*
** EPITECH PROJECT, 2023
** B-YEP-400-REN-4-1-zappy-tristan.bros
** File description:
** recv_fork.c
*/

#include "../../../include/send_package.h"

void recv_fork(t_server *server, UNUSED char **message)
{
    printf("Recv fork\n");
    send_fork(server);
}
