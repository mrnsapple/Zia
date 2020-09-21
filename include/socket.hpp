/*
** EPITECH PROJECT, 2020
** CPP_zia_2019
** File description:
** SOCKET
*/

#ifndef SOCKET_HPP_
#define SOCKET_HPP_

#define __LINUX
//#define __WINDOWS

#include <iostream>

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <functional>
#include <vector>
#include <thread>
#include <future>
#include <string>

#ifdef __WINDOWS
    #include <winsock2.h>
    typedef int socklen_t;
#endif
#ifdef __LINUX
    #include <sys/types.h>
    #include <sys/socket.h>
    #include <netinet/in.h>
    #include <arpa/inet.h>
#endif

typedef struct socket_s {
    int sockFd;
    struct sockaddr_in sockInfos;
    socklen_t sockLen;

}t_socket;

class tcp_socket {
    public:
        tcp_socket(const t_socket&);
        tcp_socket(int port = 0);
        ~tcp_socket();
        t_socket do_accept();

        int local_port();
        int local_fd();
        void async_read(const std::function<void (std::string, int)> &);
        void async_write(const std::function<void (int)> &, std::string &);

        t_socket sock;
    
    private:
        #ifdef __WINDOWS
	        WSADATA wsaData;
        #endif

        int max_size = 2096;
        void async_read_handler(const std::function<void (std::string, int)> &handler);
        void async_write_handler(const std::function<void (int)> &handler, std::string);
};

#endif /* !SOCKET_HPP_ */
