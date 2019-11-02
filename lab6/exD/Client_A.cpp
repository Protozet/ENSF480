#include "LoginServer.h"
using namespace std;

class Client_A{
    private:
        LoginServer instance;
    public:
        void add(string username, string password);
        User validate(string username, string password);
};

