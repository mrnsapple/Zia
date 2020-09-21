/*
** EPITECH PROJECT, 2020
** CPP_zia_2019
** File description:
** sock
*/

#include "../include/socket.hpp"

void closesock(int sock) { close(sock); }
#ifdef __WINDOWS
    static bool firstSocket = 1;
#endif


tcp_socket::tcp_socket(const t_socket &sock_) {
    sock.sockFd = sock_.sockFd;
    sock.sockInfos = sock_.sockInfos;
    sock.sockLen = sock_.sockLen;
}

#ifdef __WINDOWS
void clean_up()
{
    WSACleanup();
}
#endif

tcp_socket::tcp_socket(int port)
{
    #ifdef __WINDOWS
        if (firstSocket) {
	        WSAStartup(0x0202, &wsaData);
            std::atexit(clean_up);
            firstSocket = 0;
        }
    #endif
    sock.sockInfos.sin_family = AF_INET;
    sock.sockFd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP); 
    sock.sockInfos.sin_addr.s_addr = INADDR_ANY;
	sock.sockInfos.sin_port = htons (port);
    if (sock.sockFd < 0) {
        if (sock.sockFd)
            closesock(sock.sockFd);
        throw "Creation sock failed.";
    }
    sock.sockLen = sizeof(sock.sockInfos);
	if (bind(sock.sockFd, (struct sockaddr *)&sock.sockInfos, sock.sockLen) < 0) {
        if (sock.sockFd)
            closesock(sock.sockFd);
		throw "Binding sock FAILED!";
	}
    sock.sockLen = sizeof(sock.sockInfos);
	if (getsockname(sock.sockFd, (struct sockaddr *)&sock.sockInfos, &sock.sockLen) < 0) {
	}
    if (listen(sock.sockFd, 5) < 0){
        if (sock.sockFd)
            closesock(sock.sockFd);
	    throw "Listening on sock FAILED!";
	}
}

tcp_socket::~tcp_socket()
{
    if (sock.sockFd) {
        closesock(sock.sockFd);
        sock.sockFd = 0;
    }
}

t_socket tcp_socket::do_accept()
{
    t_socket remotesock;

    remotesock.sockLen = sizeof(remotesock.sockInfos);
	remotesock.sockFd = accept(sock.sockFd, (struct sockaddr *)&remotesock.sockInfos, (socklen_t *) &remotesock.sockLen);
	if (remotesock.sockFd < 0)
	{
		throw "sock Connection FAILED!";
	}
	return (remotesock);
}

int tcp_socket::local_port()
{
    return (ntohs(sock.sockInfos.sin_port));
}

int tcp_socket::local_fd() {
    return (sock.sockFd);
}

void tcp_socket::async_read_handler(const std::function<void (std::string, int)> &handler)
{
    char buffer[max_size] = {0};
    std::string b;
    int err = 0;

    if (recv(sock.sockFd, buffer, max_size - 1, 0) < 0)
        err = -1;
    else if (buffer[0] == -1 || buffer[0] == 0)
        err = 1;
    b = buffer;
    std::async(handler, b, err);
}

void tcp_socket::async_write_handler(const std::function<void (int)> &handler, std::string message) {
    int err = 0;

    if (send(sock.sockFd, message.c_str(), message.size() , 0) < 0)
        err = 1;
    std::async(handler, err);
}

void tcp_socket::async_read(const std::function<void (std::string, int)> &handler) {
    std::async(&tcp_socket::async_read_handler, this, handler);
}

void tcp_socket::async_write(const std::function<void (int)> &handler, std::string &message) {
    std::async(&tcp_socket::async_write_handler, this, handler, message);
}