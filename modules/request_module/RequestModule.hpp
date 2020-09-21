/*
** EPITECH PROJECT, 2020
** zia
** File description:
** phpmodule
*/

#ifndef REQUEST_MODULE_HPP
#define REQUEST_MODULE_HPP


#include <cstdlib>
#include <cstdio>
#include <unistd.h>
#include <sys/time.h>
#include <sys/wait.h>
#include <iomanip>
#include <ctime>
#include <chrono>
#include <fstream>
#include <experimental/filesystem>
#include <string>
#include <iostream>
#include <sstream>
#include <regex>

#include "../../api/include/IModule.hpp"
#include "../../api/include/IHooks.hpp"
#include "../../api/include/Response.hpp"
#include "../../api/include/Request.hpp"
#include "../../api/include/HTTPStatus.hpp"

class   RequestModule : public IModule
{
	public:
		RequestModule();
		~RequestModule();
		const std::string &getName() const noexcept { return name_;}
		const std::string &getVersion()  const noexcept { return version_;}
		void SetHooks(std::shared_ptr<IHooks> &hooks) noexcept; 

		void  static PrepareRequest(Request &, std::string &, HTTPStatus &);
		void  parseFields(std::istream &is, Request &request);
		void  setFields(std::smatch match, Request &request);
		bool  checkVersion(Request &request);
		bool  checkUri(Request &request);
		bool	checkMethod(Request &request);
		bool ParseRequest(Request &, std::string &, HTTPStatus &);

	private:
		std::string name_;
		std::string version_;
		std::regex url_regex_;
        std::regex version_regex_;

        
};

extern "C" IModule *getModule()
{
	return new RequestModule();
}



#endif 
