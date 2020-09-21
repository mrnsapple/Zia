/*
** EPITECH PROJECT, 2020
** zia
** File description:
** phpmodule
*/

#ifndef PHP_MODULE_HPP
#define PHP_MODULE_HPP

#include "../../api/include/IModule.hpp"
#include "../../api/include/IHooks.hpp"

#include <cstdlib>
#include <cstdio>
#include <unistd.h>
#include <sys/time.h>
#include <sys/wait.h>
#include <algorithm>
#include <chrono>
#include <fstream>
#include <experimental/filesystem>
#include <string>
#include <iostream>
#include <regex>

#include "../../api/include/Request.hpp"
#include "../../api/include/HTTPStatus.hpp"
#include "../../include/configuration.hpp"

namespace fs = std::experimental::filesystem;
namespace Net {
	class TcpSocket;
}

class   PhpModule : public IModule
{
	public:
		PhpModule();
		~PhpModule();
		const std::string &getName() const noexcept { return name_;}
		const std::string &getVersion()  const noexcept { return version_;}
		void SetHooks(std::shared_ptr<IHooks> &hooks) noexcept; 
		void static executeModule(Request &, std::string &, HTTPStatus &);
		void parseFields(std::istream &is);
		char **buildEnvironment(Request &, HTTPStatus &);
		bool callBinary(Request &, std::string &, HTTPStatus &);
		void child_process(Request &,  HTTPStatus &, int *pipes);
		bool father_process(pid_t, Request &,  std::string &string, int *pipes);
		char **transformMapToChar(std::map<std::string, std::string> );
		//IModule *getModule() { return new PhpModule(); }
	private:
		std::string name_;
		std::string version_;
		configuration *conf_;
};

extern "C" IModule *getModule()
{
	return new PhpModule();
}



#endif 
