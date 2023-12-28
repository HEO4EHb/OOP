#pragma once

#include "IUserManager.h"
#include "UserRepository.h"

class UserManager : public IUserManager
{
public:
	UserManager(UserRepository<User> & uRepo);
	~UserManager();
	void SignIn(User user) override;
	void SignOut() override;
	bool isAuthorized() override;
private:
	UserRepository<User> & m_uRepo;
	User * m_authorizedUser;
};

