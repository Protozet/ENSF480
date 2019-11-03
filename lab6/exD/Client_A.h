#include "LoginServer.h"
using namespace std;

class Client_A{
    private:
        LoginServer *instance;
    public:
        Client_A(){}
        void add(string username, string password){
            instance->add(username, password);
        }
        User* validate(string username, string password){
            return instance->validate(username, password);
        }
        Client_A& operator =(const Client_A& rhs){
            if(this == &rhs) return *this;
            instance = LoginServer::getInstance();
        }   
};

