#include "../include/Hooks.hpp"

Hooks::Hooks()
{
  pre_network_client_ = nullptr;
  post_network_client_ = nullptr;
	pre_parse_ = nullptr;
	post_parse_ = nullptr;
	quick_run_ = nullptr;
	run_ = nullptr;
	post_run_ = nullptr;
	pre_send_ = nullptr;
	module_pre_config_ = nullptr;
	module_config_ = nullptr;
	module_post_config_ = nullptr;
	pre_log_request_ = nullptr;
	post_log_request_ = nullptr;
	pre_log_response_ = nullptr;
	post_log_response_ = nullptr;
  apache_ = nullptr;
}

Hooks::~Hooks()
{
}

void Hooks::hook_apache(Hooks::requestResponseClassMethod f) noexcept
{
  apache_ = f;
}

void Hooks::hook_pre_network_client(networkMethod f) noexcept
{
  pre_network_client_ = f;
}


void Hooks::hook_post_network_client(networkMethod f) noexcept
{
  post_network_client_ =f;
}

void Hooks::hook_pre_parse(requestMethod f) noexcept
{
  pre_parse_ = f;
}

void Hooks::hook_post_parse(requestMethod f) noexcept
{
  post_parse_ = f;
}

void Hooks::hook_quick_run(requestResponseMethod f) noexcept
{
  quick_run_ = f;
}

void Hooks::hook_run(requestResponseMethod f) noexcept
{
  run_ = f;
}

void Hooks::hook_post_run(requestResponseMethod f ) noexcept
{
  post_run_ = f;
}

void Hooks::hook_pre_send(responseMethod f) noexcept
{
  pre_send_ = f;
}

void Hooks::hook_module_pre_config(noMethod f) noexcept
{
  module_pre_config_ = f;
}

void Hooks::hook_module_config(confMethod f) noexcept
{
  module_config_ = f;
}

void Hooks::hook_module_post_config(noMethod f) noexcept
{
  module_post_config_ = f;
}

void Hooks::hook_pre_log_request(logRequestMethod f) noexcept
{
  pre_log_request_ = f;
}

void Hooks::hook_post_log_request(logRequestMethod f) noexcept
{
  post_log_request_ = f;
}

void Hooks::hook_pre_log_response(responseMethod f) noexcept
{
  pre_log_response_ = f;
}

void Hooks::hook_post_log_response(IHooks::logResponseMethod f) noexcept
{
  post_log_response_ =f;
}

