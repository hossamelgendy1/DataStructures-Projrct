#include "user.h"

Friend::Friend(string username, User* u)
{
	user = u;
	this->username = username;
}

Friend::Friend(const Friend& f) {
	this->username = f.username;
	this->user = f.user;
}

string Friend::getUsername() {
	return this->username;
}

User* Friend::getUser()
{
	return user;
}

bool Friend::operator>(Friend& f) {
	return this->username > f.username;
}

bool Friend::operator<(Friend& f) {
	return this->username < f.username;
}

bool Friend::operator==(Friend& f) {
	return this->username == f.username;
}

bool Friend::operator>=(Friend& f) {
	return this->username >= f.username;
}

bool Friend::operator<=(Friend& f) {
	return this->username <= f.username;
}

ostream& operator<< (ostream& out, const Friend& f) {
	out << f.username << "," << f.user->getName();
	return out;
}