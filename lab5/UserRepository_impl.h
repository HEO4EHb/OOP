#pragma once

#include <iostream>
#include <fstream>
#include <iterator>
#include "UserRepository.h"


template<typename T>
inline UserRepository<T>::UserRepository(std::string repoPath)
	:m_repoPath(repoPath)
{
}

template<typename T>
inline std::vector<T> UserRepository<T>::GetAll()
{
	std::vector<T> users;
	std::ifstream inpF(m_repoPath, std::ios::in);
	if (inpF.is_open())
	{
		std::string userStr;
		int index = 0;
		while (std::getline(inpF, userStr))
		{
			short firstSeparatorPos = userStr.find(' ');
			short secondSeparatorPos = userStr.find(' ', firstSeparatorPos + 1);
			if (firstSeparatorPos != std::string::npos && secondSeparatorPos != std::string::npos)
			{
				std::string login = userStr.substr(0, firstSeparatorPos);
				std::string password = userStr.substr(firstSeparatorPos + 1, secondSeparatorPos - firstSeparatorPos - 1);
				std::string name = userStr.substr(secondSeparatorPos + 1, userStr.length() - secondSeparatorPos - 1);
				users.push_back(User(login, password, name, index++));
			}
		}
		inpF.close();
	}
	return users;
}

template<typename T>
inline void UserRepository<T>::Add(T user)
{
	std::ofstream outF(m_repoPath, std::ios::out | std::ios::app);
	if (outF.is_open())
	{
		outF << user.getLogin() << " " << user.getPassword() << " " << user.getName() << std::endl;
		outF.close();
	}
}

template<typename T>
inline void UserRepository<T>::Remove(T user)
{
	std::fstream inpF(m_repoPath, std::ios::in);
	if (inpF.is_open())
	{
		int userId = user.getId();
		int currentIndex = 0;
		std::vector<std::string> usersData;
		std::string userStr;
		while (std::getline(inpF, userStr))
		{
			if (userId != currentIndex++)
			{
				usersData.push_back(userStr);
			}
		}
		inpF.close();

		std::ofstream outF(m_repoPath, std::ios::out | std::ios::trunc);
		if (outF.is_open())
		{
			std::copy(usersData.begin(), usersData.end(),
				std::ostream_iterator<std::string>(outF, "\n"));
			outF.close();
		}
	}
}

template<typename T>
inline void UserRepository<T>::Update(T user)
{
	std::fstream inpF(m_repoPath, std::ios::in);
	if (inpF.is_open())
	{
		int userId = user.getId();
		int currentIndex = 0;
		std::vector<std::string> usersData;
		std::string userStr;
		while (std::getline(inpF, userStr))
		{
			if (currentIndex++ != userId)
			{
				usersData.push_back(userStr);
			}
			else
			{
				usersData.push_back(user.getLogin() + " " + user.getPassword() + " " + user.getName());
			}
		}
		inpF.close();

		std::ofstream outF(m_repoPath, std::ios::out | std::ios::trunc);
		if (outF.is_open())
		{
			std::copy(usersData.begin(), usersData.end(),
				std::ostream_iterator<std::string>(outF, "\n"));
			outF.close();
		}
	}
}

template<typename T>
inline User UserRepository<T>::GetById(int id)
{
	User result = User();
	std::fstream inpF(m_repoPath, std::ios::in);
	if (inpF.is_open())
	{
		int currentIndex = 0;
		std::string userStr;
		while (std::getline(inpF, userStr))
		{
			if (currentIndex++ == id)
			{
				result = User(userStr, id);
				break;
			}
		}
		inpF.close();
	}
	return result;
}

template<typename T>
inline User UserRepository<T>::GetByLogin(std::string login)
{
	User result = User();
	std::fstream inpF(m_repoPath, std::ios::in);
	if (inpF.is_open())
	{
		int currentIndex = 0;
		std::string userStr;
		int loginLength = login.length();
		while (std::getline(inpF, userStr))
		{
			if (userStr.length() > loginLength)
			{
				bool isEqual = true;
				for (int i = 0; i < loginLength; i++)
					if (userStr[i] != login[i])
					{
						isEqual = false;
						break;
					}
				if (isEqual)
				{
					result = User(userStr, currentIndex);
				}
			}
			currentIndex++;
		}
		inpF.close();
	}
	return result;
}
