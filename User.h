#pragma once

#include "Treap.h"


class User
{
	string name, username, email;
	Treap friendsTreap;
public:
	User(string name = "unknown", string username = "unknown", string email = "unknown");
	
	string getName();
	string getUsername();
	string getEmail();

	void setName(string name);
	void setEmail(string email);

	void addFriend(User* obj);
	void removeFriend(User* obj);
	bool searchFriend(string username);
	void printFriends();

	bool operator>(User& user);
	bool operator<(User& user);
	bool operator==(User& user);
	bool operator>=(User& user);
	bool operator<=(User& user);

	friend ostream& operator<< (ostream& out, const User& user);
	friend istream& operator>> (istream& is, User& user);
};

