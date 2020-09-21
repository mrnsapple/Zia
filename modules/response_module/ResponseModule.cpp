/*
** EPITECH PROJECT, 2019
** zia
** File description:
** PhpModuleModule.cpp
*/

#include "ResponseModule.hpp"

////////////////////////////////////////////////////////////////////////////////


////////////////////////////////////////////////////////////////////////////////

ResponseModule::ResponseModule()
{
	std::cout <<"__INSIDE ResponseModule CONSTRUCTOR__\n";

	name_ = "ResponseModule";
	version_ = "1.0";

	url_regex_ = std::regex("^(?:(http(?:s)?):\\/\\/)?(?:([\\w\\.-]+)+(?:\\:([\\d]+))?)?(\\/[^\\?]*)(?:\\?(.*))?$");
    version_regex_ = std::regex("^HTTP\\/([\\d]+)\\.([\\d]+)$");

}

ResponseModule::~ResponseModule()
{

}

void ResponseModule::SetHooks(std::shared_ptr<IHooks> &hooks)  noexcept
{
	std::function<void(Response &)> prepare_res = ResponseModule::PrepareResponse;
	std::function<void(Response &)> init_Response = ResponseModule::initResponse;
	hooks->hook_pre_send(prepare_res);
	hooks->hook_pre_log_response(init_Response);
}

void  ResponseModule::PrepareResponse(Response &res)
{
	// std::stringstream ss;
	// ResponseModule p;
	// std::cout <<"\n__ENTER IN PREPARE RESPONSE__\n";
	// res.status_code = "200";
	// res.reason_phrase = "OK";
	// res.version = "HTTP/1.1";
	// if (res.response_body.size() == 0) {
	// 	res.status_code = "404";
	// 	res.reason_phrase = "NOT_FOUND";
	// }
	// ss << res.version << " " << res.status_code << " " << res.reason_phrase;
	// ss << "\nContent-Length:" << res.response_body.length();
	// ss << "\nContent-Type: text/html\nDate: ";
	// p.getDateString(ss);
	// ss << "\n\n" << res.response_body;
	// res.resp = ss.str();


	std::string ret;
    
	res.headers["Content-length"] = std::to_string(res.response_body.size());
	if (res.response_body.size() != 0) {
		res.headers["Status"] = "200";
		res.reason_phrase = "OK";
	}
    ret = "HTTP/1.1 " + res.headers["Status"] + " " + res.reason_phrase + "\n";
    for (std::pair<std::string, std::string> element : res.headers) {
        if (element.first != "Status") {
            ret += element.first + ": " + element.second + "\n";
        }
    }
    ret += "\r\n";
    ret += res.response_body;
    ret += "\r\n\r\n";
	res.resp = ret;
}

void ResponseModule::getDateString(std::stringstream &oss)
{
	std::time_t t = std::time(nullptr);
	std::tm tm = *std::localtime(&t);

	oss << std::put_time(&tm, "%c");
}

void  ResponseModule::initResponse(Response &res)
{
    std::time_t t = std::time(nullptr);
    char mbstr[100] = {0};
	
    if (!std::strftime(mbstr, sizeof(mbstr), "%a, %d %b %Y %H:%M:%S %Z", std::localtime(&t))) {
        mbstr[0] = 0;
    }
    res.headers["Content-length"] = "0";
    res.headers["Content-type"] = "text/plain";
    res.headers["Date"] = mbstr;
    res.headers["Server"] = "superCustomServer, stop asking questions";
    res.headers["Status"] = "404";
    res.headers["Connection"] = "keep-alive";
    res.headers["Cache-Control"] = "no-cache, no-store, must-revalidate";
    res.response_body = "";
}