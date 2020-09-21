/**
 * @file Request.hpp
 * Describe the Request structure
 * @author Chétafi Alexandre
 */

#ifndef API_REQUEST_HPP
#define API_REQUEST_HPP

#include <string>
#include <map>

/**
 * Provide with a marker for the algorithm type of authentication
 */

enum class AuthenticationType
{
	CLEAR = 0, /**< Plain text */
	MD5 = 1, /**< MD5 digest start with $md5$*/
};

typedef struct Request
{
	std::map<std::string, std::string> headers; /**< Headers of the request */

	std::string req; /**< The full request */
	std::string method; /** < The different methods : GET, POST, PUT, DELETE, .... */
	std::string URI; /**< The full URI index.html, index.php */
	std::string version; /**< version of the protocol used */
	int min_version;
	int max_version;
	std::string host; /**< Host used */
	std::string port; /** Server PORT */
	std::string remote_port; /** CLIENT PORT**/
	
	std::string query;
	std::string full_url;

	std::string agent; /** < The useragent */
	std::string ip; /**< The remote ipv4 address */
	bool 		authentication = false; /**< Is basic authentication used ? (.htaccess, ...) */
	std::string user; /**< username if authentication */
	std::string pass; /**< password if authentication */
	AuthenticationType	authentication_type {AuthenticationType::CLEAR}; /**< which type of authentication ? */
	virtual void clear();
} Request;

#endif //API_REQUEST_HPP
