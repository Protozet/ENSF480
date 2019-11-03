#ifndef LOGINSERVER
#define LOGINSERVER
#include <string.h>
#include <vector>
#include <iostream>
using namespace std;
struct User {
    public: 
        string username;
        string password;
};

class LoginServer{
    private: 
        static LoginServer* instance;
        std::vector<User> users; 

        LoginServer();
        LoginServer(const LoginServer& src);
        LoginServer& operator= (const LoginServer& rhs);

    public: 
        static LoginServer* getInstance();
        void add(string username, string password);
        User validate(string username, string password);
};
#endif