/*
** EPITECH PROJECT, 2023
** B-YEP-400-REN-4-1-zappy-tristan.bros
** File description:
** map_commands.c
*/

#include "../../../include/send_package.h"

void recv_check_to_add_gui(t_server *server, char **message)
{
    (void)message;
    printf("A gui joined the server\n");
    server->clients[server->id].is_connected = true;
    server->clients[server->id].is_gui = true;
<<<<<<< Updated upstream
    send_to_client(server, "WELCOME GUI\n", server->id);
=======
    send_to_client(server, "WELCOME GUI");
>>>>>>> Stashed changes
}
