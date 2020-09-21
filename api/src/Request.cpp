//
// Created by phill on 14/01/2020.
//

#include "../include/Request.hpp"

void Request::clear()
{
	this->req.clear();
	this->host.clear();
	this->method.clear();
	this->URI.clear();
	this->version.clear();
	this->agent.clear();
	this->ip.clear();
	this->authentication = false;
	this->user.clear();
	this->authentication_type = AuthenticationType::CLEAR;
}