#ifndef LOGINSERVER_H
#define LOGINSERVER_H

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
        LoginServer(const LoginServer& src){
            instance = src.getInstance();
        }
        LoginServer& operator= (const LoginServer& rhs){
            instance = rhs.getInstance();
        }

    public: 
        static LoginServer *getInstance(){
            if(instance == NULL){
                instance = new LoginServer();
            }
            return instance;
        }
        void add(string username, string password);
        User validate(string username, string password);
};
#endif
