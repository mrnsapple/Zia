/*
** EPITECH PROJECT, 2020
** request manager
** File description:
** request manager
*/

#ifndef REQUESTMANAGER_HPP_
#define REQUESTMANAGER_HPP_
#include <memory>
#include <map>
#include <functional>
#include <iostream>
#include <string>
#include "Hooks.hpp"
#include "Request.hpp"
#include "Response.hpp"
#include "HTTPStatus.hpp"
#include "ModuleManager.hpp"
#include <array>
#include <regex>
#include "../../include/socket.hpp"
#include "NetworkDialog.hpp"
class RequestManager {
    public:
        RequestManager(int, int);
        ~RequestManager();
        Request getRequest();
        std::string getResponse();
        void updateResponse();

        //FUNCTION FOR MODULES
        bool moduleHandler(std::vector<std::string> &);
        //FUNCTION FOR HOOKS
        void executeHooks(std::string &);
    private:
   
        


    private:
        std::regex url_regex_;
        std::regex version_regex_;
     std::shared_ptr<IHooks> hooks_;
       
        clientDialog client_dialog_;
        std::map<std::string, std::string> config;
        ModuleManager module_manger_;

        //REQUEST MANAGEMENT
        Request request_;
        Response response_;
        HTTPStatus http_status_;
        //APACHE MANAGEMENT
       // Apache::Request apache_request_;
        //Apache::Response apache_response;
};


#endif