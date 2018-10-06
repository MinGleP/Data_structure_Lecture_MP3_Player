#include "User.h"
using namespace std;
User::User() {

}
User::User(string id, string password) {
	this->id = id;
	this->password = password;
	length = 1;
	
}

void User::setPassword(string password) {
	this->password = password;
}
string User::getId() {
	return id;
}