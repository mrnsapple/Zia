/*
** EPITECH PROJECT, 2019
** zia
** File description:
** ApacheModuleModule.cpp
*/

#include "ApacheModule.hpp"

////////////////////////////////////////////////////////////////////////////////


////////////////////////////////////////////////////////////////////////////////

ApacheModule::ApacheModule()
{
	std::cout <<"__INSIDE Apache CONSTRUCTOR__\n";
    //defaultNotFoundHtml = "Sorry, file not found!";

	name_ = "ApacheModule";
	version_ = "1.0";
}

ApacheModule::~ApacheModule()
{

}

void ApacheModule::SetHooks(std::shared_ptr<IHooks> &hooks)  noexcept
{
	std::function<void(Request &, Response &, HTTPStatus &)> func = ApacheModule::executeModule;
	hooks->hook_apache(func);
}
void ApacheModule::executeModule(Request &request, Response &response, HTTPStatus &status)
{
	ApacheModule p;

	p.compute(request, response, status);
}


std::string fileGetContent(const std::string &path)
{
    std::ifstream ifs(path);
    std::string content((std::istreambuf_iterator<char>(ifs) ),
                    (std::istreambuf_iterator<char>()));

    return (content);
}

void ApacheModule::fileNotFound(Response &res)
{
    res.response_body = defaultNotFoundHtml;
    res.headers["Status"] = "404";
    res.headers["Content-type"] = "text/html";
    res.headers["Content-length"] = std::to_string(res.response_body.size());
}

std::string getRelativePath(const std::string &path)
{
    std::string p;
    std::string currentPath = fs::current_path();
    std::string ret = path;

    try {
        p = fs::canonical(path);
    }
    catch (...) {
        return "#";
    }
    try {
       ret.erase(p.find(currentPath), currentPath.length());
    }
    catch (...) {
       return "#";
    }
    return (ret);
}

void ApacheModule::directoryListing(const std::string &uri, Response &res)
{

    res.response_body = "<!DOCTYPE html>\n<html>\n\t<body>\n";
    for (auto &p: fs::directory_iterator(uri)) {
        res.response_body += "\t\t<a href='" + getRelativePath(p.path()) + "'>" + std::string(fs::path(p.path()).filename()) + "</a><br />\n";
    }
    res.response_body += "\t</body>\n</html>";
    res.headers["Status"] = "200";
    res.headers["Content-type"] = "text/html";
    res.headers["Content-length"] = std::to_string(res.response_body.size());
}

void ApacheModule::getContent(const std::string &uri, Response &res)
{
    fs::path p = uri;
    std::string contentType;
    std::string ext = p.extension();


    if (ext == ".html")
        contentType = "text/html";
    else
        contentType = "text/plain";
    res.response_body = fileGetContent(uri);
    res.headers["Status"] = "200";
    res.headers["Content-type"] = contentType;
    res.headers["Content-length"] = std::to_string(res.response_body.size());
}


std::string urlDecode(const std::string &path) {
    std::string ret;
    char ch;
    int i;
    int ii;

    for (i = 0; i < path.length(); i++) {
        if (int(path[i]) == 37) {
            sscanf(path.substr(i+1,2).c_str(), "%x", &ii);
            ch = static_cast<char>(ii);
            ret += ch;
            i = i+2;
        } else {
            ret += path[i];
        }
    }
    return (ret);
}

bool ApacheModule::compute(Request &req, Response &response, HTTPStatus &status)
{
    fs::path realPath;
    req.URI = urlDecode(req.URI);
    std::string uri = "." + req.URI;

    try {
        realPath = fs::canonical(uri);
    }
    catch (...) {
        fileNotFound(response);
		return false;
    }
    std::string currentPath = fs::current_path();
    std::string rp(realPath);
    if (rp.rfind(currentPath, 0) == std::string::npos) {
        fileNotFound(response);
	    return false;
    }
    if (fs::is_directory(realPath))
        directoryListing(realPath, response);
    else {
        getContent(realPath, response);
    }
	return true;
}

