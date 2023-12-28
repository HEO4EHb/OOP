#include "UserManager.h"

int main() 
{
    UserRepository<User> repo("file.txt");
    User u1("login", "password", "name", 0);
    repo.Add(u1);
    User u2("abc", "abc", "abc", 1);
    repo.Add(u2);
    User u3("hi", "why", "die", 2);
    repo.Add(u3);
    //repo.Remove(u2);
    u3 = User("no", "man", "sky", 2);
    //repo.Update(u3);

    UserManager um(repo);
    um.SignIn(u1);
    std::cout << std::boolalpha << "Somebody's authorized: " << um.isAuthorized() << std::endl;
    um.SignOut();
    std::cout << std::boolalpha << "Somebody's authorized: " << um.isAuthorized() << std::endl;
    um.SignIn(u1);
    std::cout << std::boolalpha << "Somebody's authorized: " << um.isAuthorized() << std::endl;
    return 0;
}