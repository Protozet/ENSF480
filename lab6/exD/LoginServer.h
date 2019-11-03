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
        User(){};
};

class LoginServer{
    private: 
        static LoginServer* instance;
        std::vector<User> users; 

        LoginServer(){};
        
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
        void add(string name, string pass){
            User n;
            n.password = pass;
            n.username = name;
            users.push_back(n);
        }
        User* validate(string name, string pass){
            for(int i = 0; i < users.size(); i++){
                if(users.at(i).username == name && users.at(i).password == pass){
                    return &users.at(i);
                }
            }
            return nullptr;
        }
};
LoginServer* LoginServer:: instance = nullptr;
#endif
