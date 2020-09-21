/*
** EPITECH PROJECT, 2020
** module manager
** File description:
** zia
*/

#include "../include/ModuleManager.hpp"

ModuleManager::ModuleManager()
{
	//this->SetModules();
}

void ModuleManager::SetModules(std::vector<std::string> &modules)
{
	modules_ = modules;
    //modules_ = {"apache_module", "request_module", "SSL_Module", "php_module", "response_module"};
}

void ModuleManager::setHook(std::shared_ptr<IHooks> &hooks)
{
	IModule *module;
	for (auto it = modules_.begin(); it != modules_.end(); ++it) {
		module = getModule(*it);
		module->SetHooks(hooks);
	}
}	


IModule *ModuleManager::LoadModule(const std::string &name)
{
	std::string path = "./build/lib/lib" + name + ".so";
	std::cout <<"std::cbefore handler\n";
	  dlerror ();

	void *handler = dlopen(path.c_str(), RTLD_LAZY);
	if (!handler)
		throw std::runtime_error(std::string(dlerror()));
	std::cout <<"before dlsym\n";
	init_t *constructor = (init_t*)dlsym(handler, "getModule");
	char *e = dlerror();
	if (constructor == NULL || e)
		throw std::runtime_error("Constructor not found.\n" + std::string(e));
	IModule *mod = constructor();
	ModuleContainer c{handler, mod};
	moduleContainers_.emplace(name, c);
	return mod;

}

IModule *ModuleManager::getModule(const std::string &name)
{
	return moduleContainers_.find(name) != moduleContainers_.end() ? moduleContainers_[name].module : nullptr;
}

bool ModuleManager::LoadModules()
{
	std::vector<std::string> save_modules;
	if (modules_.size() == 0) {
		return false;
	}
	for (auto it = modules_.begin(); it != modules_.end(); ++it) {
        try {
			this->LoadModule(*it);
			std::cout << "Module '" << *it << "' loaded" << std::endl;
			save_modules.push_back(*it);
		}
		catch (std::runtime_error &e) {
			std::cout << "Failed to load module '" << *it << "': " << e.what() << std::endl;
		}
	}
	modules_ = save_modules;
	return true;
}

ModuleManager::~ModuleManager()
{
}
