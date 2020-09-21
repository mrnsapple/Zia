/*
** EPITECH PROJECT, 2019
** zia
** File description:
** PhpModuleModule.cpp
*/

#include "PhpModule.hpp"

////////////////////////////////////////////////////////////////////////////////


////////////////////////////////////////////////////////////////////////////////

PhpModule::PhpModule()
{
	std::cout <<"__INSIDE PHP CONSTRUCTOR__\n";

	name_ = "PhpModule";
	version_ = "1.0";
	conf_ = new configuration("./confFiles/");

}

PhpModule::~PhpModule()
{

}

void PhpModule::SetHooks(std::shared_ptr<IHooks> &hooks)  noexcept
{
	std::function<void(Request &, std::string &, HTTPStatus &)> func = PhpModule::executeModule;
	hooks->hook_run(func);
}

void PhpModule::parseFields(std::istream &is)
{
    std::regex parser("^([A-Za-z\\-]+)\\s*:\\s*(.*)\\r$");
	std::string line;
	while (std::getline(is, line)) {
        std::cout << "line:" << line << "\n";
		std::smatch match;
		if (!std::regex_search(line, match, parser))
			break;
		//if (match.size() == 3)
        //    setFields(match);
	}
}

void PhpModule::child_process(Request &request,  HTTPStatus &status, int *pipes)
{
	const char *bin = "/usr/bin/php-cgi";
	const char *argv[] = {bin, NULL};
	char **env = buildEnvironment(request, status);
	close(pipes[0]);
	dup2(pipes[1], 1);
	int rc = execve(
		bin,
		const_cast<char * const *>(argv),
		const_cast<char * const *>(env)
	);
	for (size_t i = 0; env[i] != NULL; ++i)
		delete env[i];
	delete env;
	exit(rc);
}

bool PhpModule::father_process(pid_t pid, Request &request,  std::string &string, int *pipes)
{
		int exitCode = 0;
		
		close(pipes[1]);
		waitpid(pid, &exitCode, 0);
		if (exitCode != 0) {
			std::cout << "PhpModule::onContentGen(): got exit code " << exitCode << std::endl;
			return false;
		}
		int r = -1;
		char buff[128];
		std::string content;
		while ((r = read(pipes[0], buff, 128)) != -1 && r > 0)
			content.append(buff, r);
		close(pipes[0]);
		if (r == -1) {
			std::cout << "PhpModule::onContentGen(): read() failed" << std::endl;
			return false;
		}
		if (content.size() != 0) {
			std::cout << "\n\nPHP UPDATE REQUEST BODY\n";
			string = content;
		} else {
			std::cout << "\n\nPHP DOESN'T UPDATE REQUEST BODY\n";

		}
}

bool PhpModule::callBinary(Request &request, std::string &string, HTTPStatus &status)
{
	int pipes[2];
	pipe(pipes);

	pid_t pid = fork();
	if (pid < 0) {
		std::cout << "PhpModule::onContentGen(): fork() failed" << std::endl;
		close(pipes[0]);
		close(pipes[1]);
		return false;
	}
	else if (pid == 0)
		child_process(request, status, pipes);
	else
		father_process(pid, request, string, pipes);
	return true;
}

void PhpModule::executeModule(Request &request, std::string &string, HTTPStatus &status)
{
	std::cout << "\n\n___EXECUTING PHP MODULE____\n\n";
	PhpModule p;

	p.callBinary(request,string,status);

}

char **PhpModule::buildEnvironment(Request &req, HTTPStatus &status)
{
	std::map<std::string, std::string> env;

	env["DOCUMENT_ROOT"] = conf_->getStringAt("phpConf", "DOCUMENT_ROOT");//"www/a";
	env["GATEWAY_INTERFACE"] = "CGI/1.1";
	env["HTTP_ACCEPT"]="text/html,application/xhtml+xml,application/xml;q=0.9,image/webp,image/apng,*/*;q=0.8,application/signed-exchange;v=b3";
	env["HTTP_ACCEPT_ENCODING"]="gzip, deflate, br";
	env["HTTP_ACCEPT_LANGUAGE"]="en,es;q=0.9,ca;q=0.8,fr;q=0.7";
	env["HTTP_CONNECTION"]="keep-alive";
	env["HTTP_HOST"]=req.host;
	env["HTTP_SEC_FETCH_MODE"]="navigate";
	env["HTTP_SEC_FETCH_SITE"]="none";
	env["HTTP_SEC_FETCH_USER"]="?1";
	env["HTTP_UPGRADE_INSECURE_REQUESTS"]="1";
	env["HTTP_USER_AGENT"]="Mozilla/5.0 (X11; Linux x86_64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/78.0.3904.108 Safari/537.36";
	env["PATH"] = std::getenv("PATH");
	env["PATHEXT"] = ".COM;.EXE;.BAT;.CMD;.VBS;.VBE;.JS;.JSE;.WSF;.WSH;.MSC";
	env["PATH_INFO"] = req.URI;
	if (env["DOCUMENT_ROOT"].back() == '/' && env["PATH_INFO"].front() == '/')
		env["SCRIPT_NAME"] = env["DOCUMENT_ROOT"] +env["PATH_INFO"].substr(1);
	else
		env["SCRIPT_NAME"] = env["DOCUMENT_ROOT"] +env["PATH_INFO"];

	env["PATH_TRANSLATED"] = fs::system_complete(env["SCRIPT_NAME"]);
	env["QUERY_STRING"] = req.query;
	env["REDIRECT_STATUS"] = "true";
	env["REMOTE_ADDR"] = "127.0.0.1";
	env["REMOTE_PORT"] = req.remote_port;
	env["REQUEST_METHOD"] = req.method;
	env["REQUEST_URI"] = req.full_url;
	// if (!req.query().empty())
	// 	env["REQUEST_URI"] += "?" + req.query();
	env["SCRIPT_FILENAME"] = env["PATH_TRANSLATED"];
	env["SERVER_ADDR"] = "127.0.0.1";
	env["SERVER_ADMIN"] = "contact@a.zia";
	env["SERVER_NAME"] = "localhost";
	env["SERVER_PORT"] = req.port;
	env["SERVER_PROTOCOL"] = req.version;
	env["SERVER_SIGNATURE"] = "<address>Zia/0.1 Server at " + env["SERVER_NAME"] + " at Port " + env["SERVER_PORT"] + "</address>\n";
	env["SERVER_SOFTWARE"] = "Zia/0.1";
	env["SYSTEMROOT"] = fs::current_path().root_name();

	struct timeval tp;
	gettimeofday(&tp, NULL);
	env["REQUEST_TIME"] = std::to_string(tp.tv_sec);
	env["REQUEST_TIME_FLOAT"] = std::to_string(tp.tv_sec * 1000 + tp.tv_usec / 1000);
	return (transformMapToChar(env));
}

char **PhpModule::transformMapToChar(std::map<std::string, std::string> env)
{
	size_t i = 0;
	char **envir = new  char *[env.size() + 1];
	for (auto it = env.begin(); it != env.end(); ++it) {
		std::string s = it->first + "=" + it->second;
		int size = s.size();
		char *buff = new char[size + 1];
		s.copy(buff, size);
		buff[size] = '\0';
		envir[i++] = buff;
	}
	envir[i] = NULL;
	for (int i = 0; envir[i] != NULL; i++)
		std::cout << envir[i] << "\n";
	return envir;
}

