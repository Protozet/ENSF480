#include "LoginServer.h"
using namespace std;

LoginServer::LoginServer(){
    users = vector<User>();
}

// LoginServer::LoginServer(const LoginServer& src){
//     users = src.users;
//     this->instance = src.instance;
// }

// LoginServer* LoginServer::getInstance(){
//     if(instance == nullptr){
//         instance = new LoginServer();
//     }
//     return instance;
// }

LoginServer& LoginServer::operator=(const LoginServer& rhs){
    if(this == &rhs)
        return *this;
    
    users = rhs.users;
    instance = rhs.instance;
    return *this;
}

int main(){
    cout << "heyo" << endl;
}