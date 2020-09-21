/*
** EPITECH PROJECT, 2020
** CPP_zia_2019
** File description:
** main_server
*/


#include "../include/socket.hpp"
#include "../include/server.hpp"
#include "../include/session.hpp"
#include <iostream>
#include <memory>

int main(int argc, char* argv[])
{
	try {
		server server_(0);

		printf("Server listening on port %d...\n", server_.socket_.local_port());
		server_.continous_listen();
	}
	catch (char const *e) {
		puts(e);
	}
}