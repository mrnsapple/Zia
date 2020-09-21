/*
** EPITECH PROJECT, 2019
** CPP_rtype_2019
** File description:
** session
*/

#include "../include/session.hpp"
#include "../api/include/RequestManager.hpp"

void session::do_read()
{
    socket_.async_read([this](std::string lol, int error) {
            if (!error) {
                std::cout << "__DATA___\n\n:" << lol<<"\n";
                RequestManager requestmanager_((socket_.local_port()), server_port_);
                std::vector<std::string> modules = conf_->getVectorAt("mainConf", "modules");
                requestmanager_.moduleHandler(modules);
                requestmanager_.executeHooks(lol);
                std::string result = "HTTP/1.1 200 Ok\nContent-Length: 230\nContent-Type: text/html; charset=iso-8859-1\nDate: Fri Feb 28 05:45:08 2020\n\n<!DOCTYPE html>\n<html>\n<head>\n   <title>400 Bad Request</title>\n</head>\n<body>\n   <h1>Bad Request</h1>\n   <p>Your browser sent a request that this server could not understand.</p>\n   <p>The request line contained invalid characters following the protocol string.</p>\n</body>\n</html>";
                result = requestmanager_.getResponse();
                do_write(result);
            }
		});
}

void session::do_write(std::string &message)
{
    std::cout <<" SENDING:\n" <<  message;

    socket_.async_write([this](int error) {
            if (!error) {
				do_read();
            }
		}, message);
}