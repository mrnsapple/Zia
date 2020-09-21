//
// Created by phill on 21/01/2020.
//

#ifndef API_HTTPSTATUS_CPP
#define API_HTTPSTATUS_CPP

#include "../include/HTTPStatus.hpp"

HTTPStatus::HTTPStatus() noexcept : e_(HTTPStatus_enum::NO_ERROR)
{}

void HTTPStatus::setStatus(HTTPStatus_enum e) noexcept
{
	this->e_ = e;
}

const std::string &HTTPStatus::name() const noexcept
{
	return this->name_;
}

std::string HTTPStatus::message(HTTPStatus_enum ev) noexcept
{
	auto e = static_cast<HTTPStatus_enum>(ev);
	switch (e)
	{
		case HTTPStatus_enum::NO_ERROR:
			return "";
		case HTTPStatus_enum::ALL_ERROR:
			return "Unknown Error";
		case HTTPStatus_enum::CONTINUE:
			return "Continue";
		case HTTPStatus_enum::SWITCHING_PROTOCOL:
			return "Switching";
		case HTTPStatus_enum::OK:
			return "OK";
		case HTTPStatus_enum::CREATED:
			return "Created";
		case HTTPStatus_enum::ACCEPTED:
			return "Accepted";
		case HTTPStatus_enum::NON_AUTHORITATIVE_INFORMATION:
			return "Non-Authoritative Information";
		case HTTPStatus_enum::NO_CONTENT:
			return "No Content";
		case HTTPStatus_enum::RESET_CONTENT:
			return "Reset Content";
		case HTTPStatus_enum::PARTIAL_CONTENT:
			return "Partial Content";
		case HTTPStatus_enum::MULTIPLE_CHOICE:
			return "Multiple Choices";
		case HTTPStatus_enum::MOVED_PERMANENTLY:
			return "Moved Permanently";
		case HTTPStatus_enum::FOUND:
			return "Found";
		case HTTPStatus_enum::SEE_OTHER:
			return "See Other";
		case HTTPStatus_enum::NOT_MODIFIED:
			return "Not Modified";
		case HTTPStatus_enum::USE_PROXY:
			return "Use Proxy";
		case HTTPStatus_enum::TEMPORARY_REDIRECT:
			return "Temporary Redirect";
		case HTTPStatus_enum::BAD_REQUEST:
			return "Bad Request";
		case HTTPStatus_enum::UNAUTHORIZED:
			return "Unauthorized";
		case HTTPStatus_enum::PAYMENT_REQUIRED:
			return "Payment Required";
		case HTTPStatus_enum::FORBIDDEN:
			return "Forbidden";
		case HTTPStatus_enum::NOT_FOUND:
			return "Not Found";
		case HTTPStatus_enum::METHOD_NOT_ALLOWED:
			return "Method Not Allowed";
		case HTTPStatus_enum::NOT_ACCEPTABLE:
			return "Not Acceptable";
		case HTTPStatus_enum::PROXY_AUTHENTICATION_REQUIRED:
			return "Proxy Authentication Required";
		case HTTPStatus_enum::REQUEST_TIMEOUT:
			return "Request Timeout";
		case HTTPStatus_enum::CONFLICT:
			return "Conflict";
		case HTTPStatus_enum::GONE:
			return "Gone";
		case HTTPStatus_enum::LENGTH_REQUIRED:
			return "Length Required";
		case HTTPStatus_enum::PRECONDITION_FAILED:
			return "Precondition Failed";
		case HTTPStatus_enum::REQUEST_ENTITY_TOO_LARGE:
			return "Request Entity Too Large";
		case HTTPStatus_enum::REQUEST_URI_TOO_LARGE:
			return "Request-URI Too Long";
		case HTTPStatus_enum::UNSUPPORTED_MEDIA_TYPE:
			return "Unsupported Media Type";
		case HTTPStatus_enum::REQUESTED_RANGE_NOT_SATISFIABLE:
			return "Requested Range Not Satisfiable";
		case HTTPStatus_enum::EXPECTATION_FAILED:
			return "Expectation Failed";
		case HTTPStatus_enum::INTERNAL_SERVER_ERROR:
			return "Internal Server Error";
		case HTTPStatus_enum::NOT_IMPLEMENTED:
			return "Not Implemented";
		case HTTPStatus_enum::BAD_GATEWAY:
			return "Bad Gateway";
		case HTTPStatus_enum::SERVICE_UNAVAILABLE:
			return "Service Unavailable";
		case HTTPStatus_enum::GATEWAY_TIMEOUT:
			return "Gateway Timeout";
		case HTTPStatus_enum::HTTP_VERSION_NOT_SUPPORTED:
			return "HTTP Version Not Supported";
	}
	return "Unknown Error";
}

std::string HTTPStatus::msg() const noexcept
{
	return HTTPStatus::message(this->e_);
}

#endif //API_HTTPSTATUS_CPP
