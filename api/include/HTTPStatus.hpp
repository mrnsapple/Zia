/**
 * @file HTTPStatus.hpp
 * Describe the class to make a status (per method) and the enum of all code
 * @author Chétafi Alexandre
 */

#ifndef API_HTTPSTATUS_HPP
#define API_HTTPSTATUS_HPP

/**
 * Enumerator of all http code
 */

enum class HTTPStatus_enum
{
	NO_ERROR = 0,
	ALL_ERROR = 1,
	//INFORMATIONAL
	CONTINUE = 100,
	SWITCHING_PROTOCOL = 101,

	//SUCCESSFUL
	OK = 200,
	CREATED = 201,
	ACCEPTED = 202,
	NON_AUTHORITATIVE_INFORMATION = 203,
	NO_CONTENT = 204,
	RESET_CONTENT = 205,
	PARTIAL_CONTENT = 206,

	//REDIRECTION
	MULTIPLE_CHOICE = 300,
	MOVED_PERMANENTLY = 301,
	FOUND = 302,
	SEE_OTHER = 303,
	NOT_MODIFIED = 304,
	USE_PROXY = 305,
	//unused = 306
	TEMPORARY_REDIRECT = 307,


	//CLIENT_ERROR
	BAD_REQUEST = 400,
	UNAUTHORIZED = 401,
	PAYMENT_REQUIRED = 402,
	FORBIDDEN = 403,
	NOT_FOUND = 404,
	METHOD_NOT_ALLOWED = 405,
	NOT_ACCEPTABLE = 406,
	PROXY_AUTHENTICATION_REQUIRED = 407,
	REQUEST_TIMEOUT = 408,
	CONFLICT = 409,
	GONE = 410,
	LENGTH_REQUIRED = 411,
	PRECONDITION_FAILED = 412,
	REQUEST_ENTITY_TOO_LARGE = 413,
	REQUEST_URI_TOO_LARGE = 414,
	UNSUPPORTED_MEDIA_TYPE = 415,
	REQUESTED_RANGE_NOT_SATISFIABLE = 416,
	EXPECTATION_FAILED = 417,

	//SERVER_ERROR
	INTERNAL_SERVER_ERROR = 500,
	NOT_IMPLEMENTED = 501,
	BAD_GATEWAY = 502,
	SERVICE_UNAVAILABLE = 503,
	GATEWAY_TIMEOUT = 504,
	HTTP_VERSION_NOT_SUPPORTED = 505,
};

#include <string>

/**
 * The HTTPStatus class provide a way to tell the server if a normal error occurred (ones that do not warrant exception)
 *
 * @par Thread Safety
 * @e Distinct @e objects: Unsafe.@n
 * @e Shared @e objects: Unsafe.@n
 */

class HTTPStatus
{
public:

	/**
	 * Constructor
	 */

	HTTPStatus() noexcept;

	/**
	 * Set the status
	 * @param e The status
	 */

	void 	setStatus(HTTPStatus_enum e) noexcept;

	/**
	 * The name of the class
	 * @return The name of the class
	 */

	const std::string &name() const noexcept;

	/**
	 *
	 * @param ev The error code number
	 * @return A string corresponding to the error code number
	 */

	static std::string message(HTTPStatus_enum ev) noexcept;

	/**
	 * Return the recorded message
	 * @return
	 */

	std::string msg() const noexcept;

private:
	HTTPStatus_enum e_;
	const std::string name_ {"HTTPStatus"};
};

#endif //API_HTTPSTATUS_HPP
