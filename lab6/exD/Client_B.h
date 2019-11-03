
#include "LoginServer.h"

using namespace std;

class Client_B{
    private:
        LoginServer *instance;
    public:
        Client_B();
        void add(string username, string password);
        User* validate(string username, string password);
        Client_B& operator =(const Client_B& rhs){
            if(this == &rhs) return *this;
            instance = LoginServer::getInstance();
        }   
};