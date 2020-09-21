#ifndef API_HOOKS_HPP
#define API_HOOKS_HPP

#include "IHooks.hpp"
#include <map>

class Hooks : public IHooks
{
	using logResponseMethod = std::function<void(Response const &)>;

public:
	/// All methods signatures
public:

public:
	Hooks();
	~Hooks();

	/**
	 * A hook to initiate a dialog as soon as a client is connected
	 */

	void hook_pre_network_client(networkMethod) noexcept override; // dès la création

	/**
	 * A hook to continue a dialog after being ask by hook_pre_network_client (flag AGAIN) (until the flag is at OK or FAILURE)
	 */

	void hook_post_network_client(networkMethod) noexcept; // dialogue

public:

	/**
	 * A hook to capture the request before parsing
	 */

	void hook_pre_parse(requestMethod) noexcept;

	/**
	 * A hook to capture the request after parsing
	 */

	void hook_post_parse(requestMethod) noexcept;

	/**
	 * A hook to call a method before everyone else
	 */

	void hook_quick_run(requestResponseMethod) noexcept;

	/**
	 * A hook to build a response on a request
	 */

	void hook_run(requestResponseMethod) noexcept;

	/**
	 * A hook to capture a request and response after treatment
	 */

	void hook_post_run(requestResponseMethod) noexcept;

	/**
	 * A hook to capture the response before being sent away
	 */

	void hook_pre_send(responseMethod) noexcept;

public:
	void hook_apache(requestResponseClassMethod) noexcept;

	//void hook_authentication_access(requestMethod &&) ;
	//void hook_authentication_user_check(requestMethod &&) ; // check base authentication
	//void hook_authentication(requestMethod &&) ; // authorization phase

public:
	/**
	 * A hook that will call a specific method before configuration
	 */

	void hook_module_pre_config(noMethod) noexcept;

	/**
	 * A hook that will be called to configure the module with the configuration
	 */

	void hook_module_config(confMethod) noexcept;

	/**
	 * A hook that will be called after the configuration
	 */

	void hook_module_post_config(noMethod) noexcept;

public:
	/**
	 * A hook that will be called before the logging of the request
	 */

	void hook_pre_log_request(logRequestMethod) noexcept;

	/**
	 * A hook that will be called after the logging of the request
	 */

	void hook_post_log_request(logRequestMethod) noexcept;

	/**
	 * A hook that will be called before the logging of the answer
	 */

	void hook_pre_log_response(responseMethod) noexcept;

	/**
	 * A hook that will be called after the logging of the answer
	 */

	void hook_post_log_response(logResponseMethod) noexcept;
};

#endif //API_IHOOKS_HPP
