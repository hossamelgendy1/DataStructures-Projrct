#include "User.h"

User::User(string name, string username, string email)
{
	this->name = name;
	this->username = username;
	this->email = email;
}

string User::getName() {
	return this->name;
}

string User::getUsername() {
	return this->username;
}

string User::getEmail() {
	return this->email;
}

void User::setName(string name) {
	this->name = name;
}

void User::setEmail(string email) {
	this->email = email;
}

void User::addFriend(User* obj)
{
	friendsTreap.insert(friendsTreap.getRoot(), *new Friend(obj->username, obj));
}

void User::removeFriend(User* obj)
{
	friendsTreap.deleteNode(friendsTreap.getRoot(), *new Friend(obj->username, obj));
}

bool User::searchFriend(string username)
{
	return friendsTreap.searchByUsername(friendsTreap.getRoot(), username);
}

void User::printFriends()
{
	if (friendsTreap.getRoot() == nullptr)
		cout << "You currently have no friends.\n";
	else
		friendsTreap.print(friendsTreap.getRoot());
}

bool User::operator>(User& user) {
	return this->username > user.username;
}

bool User::operator<(User& user) {
	return this->username < user.username;
}

bool User::operator==(User& user) {
	return this->username == user.username;
}

bool User::operator>=(User& user) {
	return this->username >= user.username;
}

bool User::operator<=(User& user) {
	return this->username <= user.username;
}

ostream& operator<< (ostream& out, const User& user) {
	out << "(" << user.username << "," << user.name << "," << user.email << ")";
	return out;
}
istream& operator>> (istream& is, User& user) {
	is >> user.username >> user.name >> user.email;
	return is;
}