/*
** EPITECH PROJECT, 2020
** Project
** File description:
** SSLModule
*/


#ifndef CPP_ZIA_2019_SSL_MODULE_HPP
#define CPP_ZIA_2019_SSL_MODULE_HPP

#include <iostream>
#include <string>
#include <openssl/ssl.h>
#include <openssl/bio.h>
#include <openssl/err.h>
#include <memory>
#include "../../api/include/IModule.hpp"
#include "../../api/include/IHooks.hpp"
#include "../../api/include/NetworkDialog.hpp"

class SSLModule : public IModule {
public:
    SSLModule();
    ~SSLModule();

    const std::string &getName() const noexcept { return _name; }
    const std::string &getVersion()  const noexcept { return _version; }
    void SetHooks(std::shared_ptr<IHooks> &hooks) noexcept;

    // SSL methods
    void loadCertificate();
    void static createConnection(clientDialog &client);
    void static openConnection(clientDialog &client);
//    static BIO *_bio;
private:
    std::string _name;
    std::string _version;
//    static BIO *_bio;

};

extern "C" IModule *getModule()
{
    return new SSLModule();
}

#endif //CPP_ZIA_2019_SSL_MODULE_HPP
