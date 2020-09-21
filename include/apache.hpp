/*
** EPITECH PROJECT, 2020
** CPP_zia_2019
** File description:
** apache
*/

#ifndef APACHE_HPP_
#define APACHE_HPP_

#include "response.hpp"
#include <string>
#include <map>

typedef struct Request
{
    std::map<std::string, std::string> headers;

    std::string req;
    std::string method;
    std::string URI;
    std::string version;
    int min_version;
    int max_version;
    std::string host;
    std::string port;

    std::string query;
    std::string full_url;

    std::string agent;
    std::string ip;
} Request;

class apacheModule {
    public:
        apacheModule();
        Response compute(const Request &);
        std::string defaultNotFoundHtml;
        std::string basePath;
    private:
        Response fileNotFound();
        Response getContent(const std::string &);
        Response directoryListing(const std::string &);
};

#endif /* !APACHE_HPP_ */
