#include <iostream>
#include <string>
#include <ctime>
#include <random>
using namespace std;

class User;
class Friend
{
private:
	string username;
	User* user;
public:
	Friend(string username = "unknown", User* u = nullptr);
	Friend(const Friend& f);

	string getUsername();
	User* getUser();

	bool operator>(Friend& f);
	bool operator<(Friend& f);
	bool operator==(Friend& f);
	bool operator>=(Friend& f);
	bool operator<=(Friend& f);

	friend ostream& operator<< (ostream& out, const Friend& f);
};


