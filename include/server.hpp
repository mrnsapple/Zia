/*
** EPITECH PROJECT, 2019
** CPP_rtype_2019
** File description:
** server
*/

#ifndef SERVER_HPP_
#define SERVER_HPP_

#include "socket.hpp"
#include "session.hpp"
#include <future>
#include <memory>
class server
{
    public:
        server(int port = 0)
            : socket_(port)
        {}

        void continous_listen();
        tcp_socket socket_;
};

#endif /* !SERVER_HPP_ */
