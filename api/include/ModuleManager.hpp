/*
** EPITECH PROJECT, 2020
** ModuleManager
** File description:
** Zia
*/

#ifndef MODULEMANAGER_HPP_
#define MODULEMANAGER_HPP_

#include <algorithm>
#include <csignal>
#include <fstream>
#include <iostream>
#include <list>
#include <map>
#include <memory>
#include <string>
#include <vector>
#include <dlfcn.h>
#include "IModule.hpp"

class ModuleManager {
    public:
        struct ModuleContainer
        {
            void *handle;
            IModule *module;
        };
    public:
        ModuleManager();
        ~ModuleManager();
        
        void SetModules(std::vector<std::string> &modules);
        IModule *getModule(const std::string &name);
        IModule *LoadModule(const std::string & );
        bool LoadModules();
        //Functions for use Hooks
        void setHook(std::shared_ptr<IHooks> &hooks);


    protected:
    private:
        //std::map<std::string, std::string> 
        std::vector<std::string> modules_;
        std::map<std::string, ModuleContainer> moduleContainers_;

};

#endif /* !MODULEMANAGER_HPP_ */
