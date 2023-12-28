#pragma once
#include "User.h"

class IUserManager
{
	virtual void SignIn(User user) = 0;
	virtual void SignOut() = 0;
	virtual bool isAuthorized() = 0;
};