/**
 * @file IHooks.hpp
 * Describe the Response structure
 * @author Chétafi Alexandre
 */

#ifndef API_RESPONSE_HPP
#define API_RESPONSE_HPP

#include <string>
#include <list>

/**
 * A way to send custom information that may not be text.
 * The data pointer is own by the module and will never deleted by the server
 */

struct binaryCustom
{
	void const *data; /**< A pointer to an array of bytes. Must always be valid */
	std::size_t size; /**< The size of the array */
};

typedef struct Response
{
	std::string resp; /**< Full response */
	std::string version; /**< Version of the protocol used */
	std::string status_code; /**< Status code to work on */
	std::string reason_phrase; /** Reason phrase linked to the status code */
	std::string response_body; /** A custom response body */
	std::string mimeType; /** < RFC 2616 19.4.1 (Compatibility with RFC 2045) */
	std::map<std::string, std::string> headers; /**< Headers of the response */
	std::string custom; /**< html custom to be sent */
	std::list<struct binaryCustom> binaryCustom; /** custom answer that may be binary or text */
} Response;

#endif //API_RESPONSE_HPP
