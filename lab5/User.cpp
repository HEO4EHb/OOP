#include "User.h"
#include <iterator>

User::User()
	:m_login(""), m_password(""), m_name(""), m_id(0)
{
}

User::User(std::string login, std::string password, std::string name, int id)
	:m_login(login), m_password(password), m_name(name), m_id(id)
{
}

User::User(std::string userData, int id)
	:m_login(""), m_password(""), m_name(""), m_id(id)
{
	short firstSeparatorPos = userData.find(' ');
	short secondSeparatorPos = userData.find(' ', firstSeparatorPos + 1);
	if (firstSeparatorPos != std::string::npos && secondSeparatorPos != std::string::npos)
	{
		m_login = userData.substr(0, firstSeparatorPos);
		m_password = userData.substr(firstSeparatorPos + 1, secondSeparatorPos - firstSeparatorPos - 1);
		m_name = userData.substr(secondSeparatorPos + 1, userData.length() - secondSeparatorPos - 1);
	}
}
