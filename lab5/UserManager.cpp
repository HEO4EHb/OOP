#include "UserManager.h"
#include <iterator>
UserManager::UserManager(UserRepository<User> & uRepo)
	:m_uRepo(uRepo), m_authorizedUser(nullptr)
{
}

UserManager::~UserManager()
{
	if (m_authorizedUser != nullptr)
		delete m_authorizedUser;
}

void UserManager::SignIn(User user)
{
	std::ifstream inpF("autoauth.txt", std::ios::in);
	if (inpF.is_open())
	{
		std::string login;
		if (getline(inpF, login) && login == user.getLogin())
		{
			m_authorizedUser = new User();
			*m_authorizedUser = user;
			return;
		}
		inpF.close();
	}
	std::string password;
	std::cout << "Enter password for user " << user.getLogin() << std::endl;
	std::cin >> password;
	if(password == user.getPassword())
	{
		m_authorizedUser = new User();
		*m_authorizedUser = m_uRepo.GetById(user.getId());
		std::cout << "Signed in: " << user.getLogin() << std::endl;

		std::ofstream outF("autoauth.txt", std::ios::out | std::ios::trunc);
		if (outF.is_open())
		{
			outF << user.getLogin() << std::endl;
			outF.close();
		}
	}
}

void UserManager::SignOut()
{
	std::cout << "Signed out: " << m_authorizedUser->getLogin() << std::endl;
    //If you simply open the file for writing with the truncate-option, you'll delete the content.
    std::ofstream ofs;
    ofs.open("autoauth.txt", std::ofstream::out | std::ofstream::trunc);
    ofs.close();
	delete m_authorizedUser;
	m_authorizedUser = nullptr;
}

bool UserManager::isAuthorized()
{
	return (m_authorizedUser != nullptr);
}
