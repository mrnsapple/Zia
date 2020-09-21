/*
** EPITECH PROJECT, 2019
** zia
** File description:
** PhpModuleModule.cpp
*/

#include "RequestModule.hpp"

////////////////////////////////////////////////////////////////////////////////


////////////////////////////////////////////////////////////////////////////////

RequestModule::RequestModule()
{
	std::cout <<"__INSIDE RequestModule CONSTRUCTOR__\n";

	name_ = "RequestModule";
	version_ = "1.0";

	url_regex_ = std::regex("^(?:(http(?:s)?):\\/\\/)?(?:([\\w\\.-]+)+(?:\\:([\\d]+))?)?(\\/[^\\?]*)(?:\\?(.*))?$");
    version_regex_ = std::regex("^HTTP\\/([\\d]+)\\.([\\d]+)$");

}

RequestModule::~RequestModule()
{

}

void RequestModule::SetHooks(std::shared_ptr<IHooks> &hooks)  noexcept
{
	std::function<void(Request &, std::string &, HTTPStatus &)> prepare_req = RequestModule::PrepareRequest;

	hooks->hook_quick_run(prepare_req);
}

void RequestModule::PrepareRequest(Request &request, std::string &data, HTTPStatus &status)
{
	std::cout << "\n\n___EXECUTING PARSER MODULE____\n\n";

	RequestModule p;
	if (p.ParseRequest(request, data, status))
		std::cout << "Error parsing Request\n" << std::flush;
}

bool RequestModule::ParseRequest(Request &request, std::string &data, HTTPStatus &status)
{
	std::istringstream iss(data);
    request.req = data;
    iss >> request.method;
    iss >> request.full_url;
	iss >> request.version;
    if ( !checkMethod(request) || !checkUri(request) || !checkVersion(request))
        return false;
    iss.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	parseFields(iss, request);
    return true;
}

bool RequestModule::checkMethod(Request &request)
{
     std::vector<std::string>  methods = { "OPTIONS", "GET", "HEAD", "POST", "PUT", "DELETE", "TRACE", "CONNECT"};
	if (std::find(methods.begin(), methods.end(), request.method) == methods.end()) {
		std::cout << "Request::parseRequest(): Invalid HTTP method'" << request.method << "'" << std::endl;
		return false;
	}
    return true;
}

bool RequestModule::checkUri(Request &request)
{
    std::smatch match;
	if (!std::regex_search(request.full_url, match, url_regex_)) {
		std::cout << "Request::parseRequest(): Failed to match URI '" << request.full_url << "'" << std::endl;
		return false;
	}
    request.host = match[2];
    //request.port = match[3];
    request.URI = match[4];
    request.query = match[5];
    return true;
}

bool RequestModule::checkVersion(Request &request)
{
	std::smatch match;
	if (!std::regex_search(request.version, match, version_regex_)) {
		std::cout << "Request::parseRequest(): Failed to match HTTP version" << std::endl;
		return false;
	}
	request.max_version = std::stoi(match[1]);
	request.min_version = std::stoi(match[2]);
    return  true;
}

void RequestModule::setFields(std::smatch match, Request &request)
{
    //std::cout << match[1] << "," << match[2] <<"\n";
    if (match[1] == "Host")
        request.host = match[2];
}

void RequestModule::parseFields(std::istream &is, Request &request)
{
    std::regex parser("^([A-Za-z\\-]+)\\s*:\\s*(.*)\\r$");
	std::string line;
	while (std::getline(is, line)) {
        //std::cout << "line:" << line << "\n";
		std::smatch match;
		if (!std::regex_search(line, match, parser))
			break;
		if (match.size() == 3)
            setFields(match, request);
	}
}

