/*
** EPITECH PROJECT, 2020
** zia
** File description:
** phpmodule
*/

#ifndef RESPONSE_MODULE_HPP
#define RESPONSE_MODULE_HPP


#include <cstdlib>
#include <cstdio>
#include <unistd.h>
#include <sys/time.h>
#include <sys/wait.h>
//#include <algorithm>
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

class   ResponseModule : public IModule
{
	public:
		ResponseModule();
		~ResponseModule();
		const std::string &getName() const noexcept { return name_;}
		const std::string &getVersion()  const noexcept { return version_;}
		void SetHooks(std::shared_ptr<IHooks> &hooks) noexcept; 
		void  static PrepareResponse(Response &);
		void  static initResponse(Response &res);

		void getDateString(std::stringstream &);

	private:
		std::string name_;
		std::string version_;
		std::regex url_regex_;
        std::regex version_regex_;

        
};

extern "C" IModule *getModule()
{
	return new ResponseModule();
}



#endif 
