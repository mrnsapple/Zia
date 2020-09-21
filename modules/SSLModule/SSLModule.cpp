/*
** EPITECH PROJECT, 2020
** Project
** File description:
** SSLModule
*/


#include "SSLModule.hpp"

SSLModule::SSLModule() : _name("ssl_module"), _version("1.0.0")
{
    SSL_load_error_strings();
    ERR_load_BIO_strings();
    OpenSSL_add_ssl_algorithms();
}

SSLModule::~SSLModule()
{

}

void SSLModule::SetHooks(std::shared_ptr <IHooks> &hooks) noexcept
{
    std::cout << "SSL HOOKS SETUP TIME" << std::endl;
    hooks->hook_pre_network_client(SSLModule::createConnection);
    hooks->hook_post_network_client(SSLModule::openConnection);
}

void SSLModule::loadCertificate()
{
//    if (!SSL_CTX_load_verify_locations(_ctx, "cert.pem", NULL)) {
//        std::cerr << "loading failed" << std::endl;
//        return -1;
//    }
//    return 0;
}

void SSLModule::createConnection(clientDialog &client)
{
    std::cout << "BIO new connection" << std::endl;
    std::string str = "127.0.0.1:" + client.port;
    std::cout << str << std::endl;
    BIO *_bio = BIO_new_connect(str.c_str());
    if (_bio == NULL) {
        std::cout << "failed" << std::endl;
        client.status = NetworkStatus::FAILED;
    }
    client.status = NetworkStatus::AGAIN;
}

void SSLModule::openConnection(clientDialog &client)
{
    if (client.status == NetworkStatus::AGAIN) {
        std::cout << "hey you" << std::endl;
        std::string str = "127.0.0.1:" + client.port;
        std::cout << str << std::endl;
        BIO *_bio = BIO_new_connect(str.c_str());
        if (BIO_do_connect(_bio) <= 0) {
            std::cout << "failed connect" << std::endl;
            client.status = NetworkStatus::FAILED;
        } else {
            std::cout << "connect success" << std::endl;
            client.status = NetworkStatus::OK;
        }
    } else {
        std::cout << "why " << std::endl;
    }
//     if (BIO_do_connect(_bio) <= 0) {
//         std::cerr << "failed connect" << std::endl;
//         client.status = NetworkStatus::FAILED;
//     }
//     client.status = NetworkStatus::OK;
}