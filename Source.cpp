#pragma once
//#include "Form.h"
#include "MainForm.h"
#include <iostream>
#include <map>
#include <SDL_iostream.h>
#include <stdio.h>
#include <string>



using namespace std;

class AppConfig {
private:
	map<string, string> applicationState;

	AppConfig()
	{
		cout << "AppConfig constructor called" << endl;
	}

	static AppConfig* instance;

public:
	static AppConfig* getInstance()
	{
		if (instance == nullptr) {
			instance = new AppConfig();
		}
		return instance;
	}

	void set(std::string key, std::string value)
	{
		applicationState[key] = value;
	}
	string get(string key)
	{
		return applicationState[key];
	}
};

AppConfig* AppConfig::instance = nullptr;







int main(void** appstate, int argc, char* argv[]) 
{
	AppConfig* config = AppConfig::getInstance();
	config->set("appTitle", "AlienWar");

	AppConfig* config2 = AppConfig::getInstance();
	config->set("appVersion", "0.0.1");

	std::cout << "Welcome to " << config2->get("appTitle")
		<< " Version " << config->get("appVersion") << ")" << std::endl;
	
	
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	Application::Run(gcnew MainForm());
	return 0;
};

