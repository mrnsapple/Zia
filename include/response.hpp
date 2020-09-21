/*
** EPITECH PROJECT, 2020
** CPP_zia_2019
** File description:
** response
*/

#ifndef RESPONSE_HPP_
#define RESPONSE_HPP_

#include <string>
#include <map>

class Response {
    public:
        Response();
        std::map<std::string, std::string> headers;
        std::string body;
        std::string to_string();
    private:
        std::map<std::string, std::string> statusTable;
};

#endif /* !RESPONSE_HPP_ */
