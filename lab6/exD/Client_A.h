#include "LoginServer.h"
using namespace std;

class Client_A{
    private:
        LoginServer *instance;
    public:
        Client_A();
        void add(string username, string password);
        User* validate(string username, string password);
        Client_A& operator =(const Client_A& rhs){
            if(this == &rhs) return *this;
            instance = LoginServer::getInstance();
        }   
};

