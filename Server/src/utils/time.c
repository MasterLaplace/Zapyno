/*
** EPITECH PROJECT, 2023
** B-YEP-400-REN-4-1-zappy-tristan.bros
** File description:
** stwa.c
*/

#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/time.h>
#include <stdbool.h>
#include <time.h>

#define TIMEOUT 5

struct timeval timestamp;

bool has_timed_out(clock_t delay) {
    clock_t curr_time = clock();
    double time_taken = ((double)curr_time - delay) / CLOCKS_PER_SEC;
    printf("time_taken: %f\n", time_taken);
    return time_taken >= 3.0;
}