#pragma once
#include "IRepository.h"
#include <string>

template<typename User>
class IUserRepository : IRepository<User>
{
	virtual User GetById(int id) = 0;
	virtual User GetByLogin(std::string login) = 0;
};