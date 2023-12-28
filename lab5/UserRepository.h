#pragma once
#include "IUserRepository.h"
#include "User.h"

template<typename T>
class UserRepository : public IUserRepository<T>
{
public:
	UserRepository(std::string repoPath);
	std::vector<T> GetAll() override;
	void Add(T user) override;
	void Remove(T user) override;
	void Update(T user) override;
	User GetById(int id) override;
	User GetByLogin(std::string login) override;
private:
	std::string m_repoPath;
};

#include "UserRepository_impl.h"


