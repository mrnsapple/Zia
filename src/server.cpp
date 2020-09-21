/*
** EPITECH PROJECT, 2020
** CPP_zia_2019
** File description:
** server
*/

#include "../include/server.hpp"

void create_session(t_socket client, int server_port)
{
    session s(client, server_port);
    s.do_read();
}

void server::continous_listen()
{
    t_socket client;

    while (1) {
        client = socket_.do_accept();
        std::thread(&create_session, client, socket_.local_port()).detach();
    }
}