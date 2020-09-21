/*
** EPITECH PROJECT, 2020
** CPP_zia_2019
** File description:
** configuration
*/

#ifndef CONFIGURATION_HPP_
#define CONFIGURATION_HPP_

#include <map>
#include <string>
#include <fstream>
#include <vector>
#include <any>
#include <experimental/filesystem>

namespace fs = std::experimental::filesystem;

class configuration {
    public:
        configuration(const std::string &path);
        void updateConf();
        std::string getStringAt(const std::string &module, const std::string &key);
        std::vector<std::string> getVectorAt(const std::string &module, const std::string &key);

    private:
        fs::path basePath;
        std::map<std::string, std::map<std::string, std::any>> conf_;

        std::map<std::string, std::any> getIni(const fs::path &pathName);
        std::any getValue(const std::string &value);
};

#endif /* !CONFIGURATION_HPP_ */