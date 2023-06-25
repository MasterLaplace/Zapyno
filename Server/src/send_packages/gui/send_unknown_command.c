/*
** EPITECH PROJECT, 2023
** B-YEP-400-REN-4-1-zappy-tristan.bros
** File description:
** send_unknown_command
*/

#include "../../../include/send_package.h"

void send_unknown_command(t_server *server, int id)
{
    AUTO_FREE char *message = calloc(5,sizeof(char));
    if (!message)
        return;
    sprintf(message, "suc\n");
    send_to_client(server, message, id);
}
