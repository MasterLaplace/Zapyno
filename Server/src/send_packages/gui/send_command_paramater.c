/*
** EPITECH PROJECT, 2023
** B-YEP-400-REN-4-1-zappy-tristan.bros
** File description:
** send_unknown_command
*/

#include "../../../include/send_package.h"

void send_command_paramater(t_server *server)
{
    AUTO_FREE char *message = calloc(5,sizeof(char));
    sprintf(message, "sbp\n");
    send_to_gui(server, message, server->id);
}

void send_command_paramater_to_all(t_server *server)
{
    AUTO_FREE char *message = calloc(6,sizeof(char));
    sprintf(message, "sbp %s\n", message);
    send_to_all_gui(server, message);
}
