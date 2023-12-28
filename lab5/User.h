#pragma once
#include <string>

class User
{
public:
	User();
	User(std::string login, std::string password, std::string name, int id);
	User(std::string userData, int id);
	std::string getLogin() { return m_login; }
	std::string getPassword() { return m_password; }
	std::string getName() { return m_name; }
	int getId() { return m_id; }
private:
	int m_id;
	std::string m_login;
	std::string m_password;
	std::string m_name;
};

