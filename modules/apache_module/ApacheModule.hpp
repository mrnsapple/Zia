/*
** EPITECH PROJECT, 2020
** zia
** File description:
** ApacheModule
*/

#ifndef APACHE_HPP_
#define APACHE_HPP_
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
#include "../../api/include/IModule.hpp"
#include "../../api/include/IHooks.hpp"
#include "../../api/include/Request.hpp"
#include "../../api/include/Response.hpp"
#include "../../api/include/HTTPStatus.hpp"


#include <string>
#include <map>
namespace fs = std::experimental::filesystem;

// 	class Response {
// 		public:
// 			Response();
// 			std::map<std::string, std::string> headers;
// 			std::string body;
// 			std::string to_string();
// 		private:
// 			std::map<std::string, std::string> statusTable;
// 	};
// }



class   ApacheModule : public IModule
{
	public:
    	Response compute(const Request &);
        std::string defaultNotFoundHtml;
        std::string basePath;
	private:
		void fileNotFound(Response &);
		void getContent(const std::string &, Response &);
		void directoryListing(const std::string &, Response &);
		bool compute(Request &,Response &, HTTPStatus &);

	public:
		ApacheModule();
		~ApacheModule();
		const std::string &getName() const noexcept { return name_;}
		const std::string &getVersion()  const noexcept { return version_;}
		void SetHooks(std::shared_ptr<IHooks> &hooks) noexcept; 
		void static executeModule(Request &,Response &, HTTPStatus &);
	private:
		 std::string name_;
		 std::string version_;
};

extern "C" IModule *getModule()
{
	return new ApacheModule();
}



#endif 
