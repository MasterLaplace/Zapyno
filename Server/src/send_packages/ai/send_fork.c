/*
** EPITECH PROJECT, 2023
** B-YEP-400-REN-4-1-zappy-tristan.bros
** File description:
** send_fork.c
*/

#include "../../../include/send_package.h"

static int get_last_id(t_server *server)
{
    for (int i = 0; i < SOMAXCONN; i++) {
        if (i == 0 && CLIENT(i).id == -1)
            return 0;
        else if (CLIENT(i).id == -1)
            return CLIENT(i - 1).id;
    }
    return -1;
}

void send_fork(t_server *server)
{
    int id = get_last_id(server);
    for (int i = 0; i < SOMAXCONN; i++) {
        printf("%d\n", server->clients[i].id);
    }
    TEAMS[TEAM_INDEX].max_players += 1;
    TEAMS = realloc(TEAMS, sizeof(t_teams) * TEAMS[TEAM_INDEX].max_players);

    TEAMS[TEAM_INDEX].players = realloc(TEAMS[TEAM_INDEX].players, sizeof(t_client) * TEAMS[TEAM_INDEX].max_players);
    TEAMS[TEAM_INDEX].players[TEAMS[TEAM_INDEX].max_players - 1].is_an_egg = true;
    TEAMS[TEAM_INDEX].players[TEAMS[TEAM_INDEX].max_players - 1].id = id;
    TEAMS[TEAM_INDEX].players[TEAMS[TEAM_INDEX].max_players - 1].pos_x = RANDINT(0, server->params->width - 1);
    TEAMS[TEAM_INDEX].players[TEAMS[TEAM_INDEX].max_players - 1].pos_y = RANDINT(0, server->params->height - 1);
    int x = TEAMS[TEAM_INDEX].players[TEAMS[TEAM_INDEX].max_players - 1].pos_x;
    int y = TEAMS[TEAM_INDEX].players[TEAMS[TEAM_INDEX].max_players - 1].pos_y;
    CLIENT(id).is_an_egg = true;
    CLIENT(id).id = id;
    send_to_client(server, "ok\n", server->id);
    AUTO_FREE char *message = calloc(my_nblen(server->id) + 6, sizeof(char));
    sprintf(message, "pfk %d\n", server->id);
    send_to_all_gui(server, message);
    send_an_egg_was_laid_by_a_player(server, id, x, y);
}

void send_fork_to_all(t_server *server)
{
    char *message = calloc(9, sizeof(char));
    sprintf(message, "pfk %d\n", server->id);
    send_to_all_clients(server, message);
}
