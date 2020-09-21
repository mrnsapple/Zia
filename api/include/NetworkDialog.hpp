/**
 * @file NetworkDialog.hpp
 * Describe the way to make a conversation with a client
 * @author Chétafi Alexandre
 */

#ifndef API_NETWORKDIALOG_HPP
#define API_NETWORKDIALOG_HPP


/**
 * This is a enum to notify a state to the server
 */

enum class NetworkStatus
{
	FAILED, /**< The dialog failed, the server should interrupt the connection */
	AGAIN, /**< The module ask for the client an answer, the server continue to support the dialog */
	OK /**< The module notify to the server that the dialog was a success */
};

/**
 * This structure provide the necessary tool to make a communication between client and server
 */

struct clientDialog
{
    std::string port;
	NetworkStatus 	status; /**< Status of the dialog */
	std::string 	dialog; /**< Content of the dialog */
};

#endif //API_NETWORKDIALOG_HPP
