
#include "LoginServer.h"

using namespace std;

class Client_B{
    private:
        LoginServer *instance;
    public:
        Client_B(){
            instance = LoginServer::getInstance();
        }
        void add(string username, string password){
            instance->add(username, password);
        }
        User* validate(string username, string password){
            return instance->validate(username, password);
        }
        Client_B& operator =(const Client_B& rhs){
            if(this == &rhs) return *this;
            instance = LoginServer::getInstance();
        }   
};