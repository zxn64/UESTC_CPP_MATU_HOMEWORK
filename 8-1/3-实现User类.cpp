#include <iostream>
#include <string>
#include <map>

class User {
    std::map <std::string, std::string> users;

public:
    User(const std::string &name, const std::string &pass) {
        users[name] = pass;
    }

    void AddUser(const std::string &name, const std::string &pass) {
        users[name] = pass;
    }

    int login(const std::string &name, const std::string &pass) {
        if (users.find(name) == users.end() || users[name] != pass) return -1;
        else return 0;
    }
};

int main() {
    using namespace std;
    string name, name1, pass, pass1;
    cin >> name >> pass >> name1 >> pass1;
    User user("LiWei", "liwei101");
    user.AddUser(name, pass);
    if (user.login(name1, pass1) >= 0) {
        cout << "Success Login!" << endl;
    } else {
        cout << "Login failed!" << endl;
    }
    return 0;
}