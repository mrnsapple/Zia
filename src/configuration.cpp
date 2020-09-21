/*
** EPITECH PROJECT, 2020
** CPP_zia_2019
** File description:
** configuration
*/

#include "../include/configuration.hpp"
#include <iostream>
#include <algorithm>

configuration::configuration(const std::string &path)
{
    try {
        basePath = fs::canonical(path);
    }
    catch (...) {
        basePath = fs::canonical("./confFiles/");
    }
    updateConf();
}

std::vector<std::string> getVector(const std::string &value)
{
    std::string delimiter = ",";
    std::string bufVal = value;
    size_t pos = 0;
    std::string token;
    std::vector<std::string> ret;

    bufVal.erase(0, 1);
    bufVal.erase(bufVal.length() - 1, bufVal.length() - 1);
    while ((pos = bufVal.find(delimiter)) != std::string::npos) {
        token = bufVal.substr(0, pos);
        ret.push_back(token);
        bufVal.erase(0, pos + delimiter.length());
    }
    ret.push_back(bufVal);
    return (ret);
}

std::any configuration::getValue(const std::string &value)
{
    std::any ret;

    if (value[0] == '[' && value[value.length() - 1] == ']')
        ret = getVector(value);
    else
        ret = value;
    return (ret);
}

std::map<std::string, std::any> configuration::getIni(const fs::path &pathName)
{
    std::map<std::string, std::any> ret;
    std::ifstream ifs(pathName);
    std::string line;
    size_t pos = 0;
    std::string key;
    std::any value;
    std::string delimiter = ":";

    while (std::getline(ifs, line)) {
        line.erase(std::remove(line.begin(), line.end(), ' '), line.end());
        line.erase(std::remove(line.begin(), line.end(), '\t'), line.end());
        pos = 0;
        key = "";
        value = "";
        if ((pos = line.find(delimiter)) != std::string::npos) {
            key = line.substr(0, pos);
            line.erase(0, pos + delimiter.length());
        }
        value = getValue(line);
        ret[key] = value;
    }
    return (ret);
}

void configuration::updateConf()
{
    std::map<std::string, std::map<std::string, std::any>> conf;
    fs::path file;

    if (!fs::is_directory(basePath))
        return;
    for (auto &p: fs::directory_iterator(basePath)) {
        file = p.path();
        if (file.extension() == ".ini")
            conf[file.replace_extension("").filename()] = getIni(file.replace_extension(".ini"));
    }
    conf_ = conf;
}

std::string configuration::getStringAt(const std::string &module, const std::string &key)
{
    std::string ret;

    try {
        ret = std::any_cast<std::string>(conf_[module][key]);
    }
    catch (...) {
        return "";
    }
    return (ret);
}

std::vector<std::string> configuration::getVectorAt(const std::string &module, const std::string &key)
{
    std::vector<std::string> ret;

    try {
        ret = std::any_cast<std::vector<std::string>>(conf_[module][key]);
    }
    catch (...) {
        return ret;
    }
    return (ret);
}

// int main()
// {
//     configuration conf("../includeModules");

//     std::cout << conf.getStringAt("test", "lol") << std::endl;
//     std::cout << conf.getVectorAt("test", "lul")[1] << std::endl;
// }