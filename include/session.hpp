/*
** EPITECH PROJECT, 2019
** CPP_rtype_2019
** File description:
** session
*/

#ifndef SESSION_HPP_
#define SESSION_HPP_


#include "socket.hpp"
#include <iostream>
#include <string>
#include <memory>
#include "configuration.hpp"
class session
{
    public:
        session(t_socket socket, int server_port)
            : socket_(socket), server_port_(server_port)
        {
            std::cout << "Session started from socket port : " << socket_.local_port() << std::endl;
            conf_ = new configuration("./confFiles/");
        }

        void do_read();
        void do_write(std::string &);

        tcp_socket socket_;
        int server_port_;
        configuration *conf_;
};

#endif /* !SESSION_HPP_ */
