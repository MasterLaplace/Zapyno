/*
** EPITECH PROJECT, 2023
** B-YEP-400-REN-4-1-zappy-tristan.bros
** File description:
** recv_eject.c
*/

#include "../../../include/send_package.h"

void recv_eject(t_server *server, UNUSED char **message, int id)
{
    printf("[ai@recv] eject\n");
    send_eject(server, id);
}
