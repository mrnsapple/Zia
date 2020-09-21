#include "../include/RequestManager.hpp"


RequestManager::RequestManager(int remote_port, int server_port)
{
    request_.port = std::to_string(server_port);
    request_.remote_port = std::to_string(remote_port);
    hooks_ = std::make_shared<Hooks>();
    client_dialog_.port = std::to_string(server_port);
    //request_ = std::make_shared<Request>();
    //response_ = std::make_shared<Response>();
    //http_status_ = std::make_shared<HTTPStatus>();
}

RequestManager::~RequestManager()
{

}

bool RequestManager::moduleHandler(std::vector<std::string> &modules)
{
    module_manger_.SetModules(modules);
    module_manger_.LoadModules();
    module_manger_.setHook(hooks_);
}

/*
* Best implementation of use Chetafy api
*/
void RequestManager::executeHooks(std::string &data)
{
    //USED BY SSL MODULE
    if(hooks_->pre_network_client_ != nullptr) hooks_->pre_network_client_(client_dialog_);
    //USED BY SSL MODULE
    if (hooks_->post_network_client_ != nullptr) hooks_->post_network_client_(client_dialog_);
	//NOT USED
    if (hooks_->pre_parse_ != nullptr) hooks_->pre_parse_(request_,http_status_);
	//NOT USED
    if (hooks_->post_parse_ != nullptr) hooks_->post_parse_(request_, http_status_);
	//USED BY REQUEST MODULE FOR HANDLE REQUEST
    if (hooks_->quick_run_ != nullptr) hooks_->quick_run_(request_, data, http_status_);
    //USED BY RESPONSE MODULE TO INIT RESPONSE
    if (hooks_->pre_log_response_ != nullptr) hooks_->pre_log_response_(response_);

    //USED BY APACHE MODULE
    if (hooks_->apache_ != nullptr) hooks_->apache_(request_,response_, http_status_);
    //USED BY PHP MODULE
    if (hooks_->run_ != nullptr) hooks_->run_(request_, response_.response_body, http_status_);
    //NOT USED
    if (hooks_->post_run_ != nullptr) hooks_->post_run_(request_, response_.response_body, http_status_);
	//USED BY PARSE MODULE FOR HANDLE RESPONSE
    if (hooks_->pre_send_ != nullptr) hooks_->pre_send_(response_);
	//NOT USED
    if (hooks_->module_pre_config_ != nullptr) hooks_->module_pre_config_();
	if (hooks_->module_config_ != nullptr) hooks_->module_post_config_();
	if (hooks_->module_post_config_ != nullptr) hooks_->module_post_config_();
	if (hooks_->pre_log_request_ != nullptr) hooks_->pre_log_request_(request_);
	if (hooks_->post_log_request_ != nullptr) hooks_->post_log_request_(request_);
	if (hooks_->post_log_response_ != nullptr) hooks_->post_log_response_(response_);
	
}

void RequestManager::updateResponse()
{
    response_.version = request_.version;
}

Request RequestManager::getRequest()
{
    return request_;
}

std::string RequestManager::getResponse()
{
    return response_.resp;
}
