#include <fstream>
#include "UserLinkedList.h"

// this function takes a user and prints "people you may know" for that user.
void peopleYouMayKnow(UserLinkedList users, User* u)
{
	int count = 0;
	for (int i = 0; i < users.len() && count < 5; i++)
	{
		if (!u->searchFriend(users.get(i)->getUsername()) && users.get(i)->getUsername() != u->getUsername())
		{
			cout << users.get(i)->getUsername() << ',' << users.get(i)->getName() << endl;
			count++;
		}
	}
	cout << endl;

}

//linked list to carry the system's users
//declared globally to be seen by all functions.
UserLinkedList users;

//functions declarations
void readData();
void application();

int main()
{
	readData();
	application();
}

void readData() {
	srand(time(nullptr));

	//constructing the system and reading the files data begins here

	ifstream system_users;
	system_users.open("all-users.in", ios::in);
	//loop to read the file line by line and fill the user and friends linked lists
	while (!system_users.eof()) {
		string text;
		getline(system_users, text);
		//holder variables
		string username;
		string name;
		string email;
		//to check if we finished one variable
		int checker = 0;
		//loop to split the line and fetch data into 3 variables username, name and email.
		for (string::iterator i = text.begin(); i != text.end(); i++) {
			if (*i == ',' && *(i + 1) == ' ') {
				i++;
				checker++;
			}
			else if (checker == 1) {
				name = name + *i;
			}
			else if (checker == 2) {
				email = email + *i;
			}
			else {
				username = username + *i;
			}
		}
		//creating every user and inserting it into the linked list
		User* u = new User(name, username, email);
		users.Insertback(*u);
	}

	ifstream relations;
	relations.open("all-users-relations.in", ios::in);
	//reading the relations file line by line
	while (!relations.eof()) {
		string text;
		getline(relations, text);
		//holder variables
		string username1;
		string username2;
		//to check if we finished one variable
		int checker = 0;
		//loop to split the line and fetch data into 2 variables (the usernames of the 2 friends)
		for (string::iterator i = text.begin(); i != text.end(); i++) {
			if (*i == ',' && *(i + 1) == ' ') {
				i++;
				checker++;
			}
			else if (checker == 1) {
				username2 = username2 + *i;
			}
			else {
				username1 = username1 + *i;
			}
		}

		// in the following code I try to fill the users BST using the variables I got from the file
		// from the username I find the user and then I access the BST to insert in it
		// friend who carries the second username.
		User* user2 = users.get(username2);
		User* user1 = users.get(username1);
		user1->addFriend(user2);
		user2->addFriend(user1);
	}
}

void application()
{
	//Main menu
	int mainMinuChoice = 0;
	while (mainMinuChoice != 2)
	{
		cout << "WELCOME TO SOCIAL APP..\n"
			<< "---------------------------\n"
			<< "1- Login\n"
			<< "2- Exit\n";
		cin >> mainMinuChoice;
		switch (mainMinuChoice)
		{
		//MainMenu -> Login
		case 1:
		{
			string username;
			cout << "Enter your username: ";
			cin >> username;
			User* loggedUser = users.get(username);
			if (loggedUser == nullptr)
			{
				cout << "Wrong username!\n\n";
				break;
			}

			// now the user is logged in
			cout << "Logged in successfully. Welcome back to your account :)\n\n";

			//User Menu
			int userMenuChoice = 0;
			while (userMenuChoice != 6)
			{
				cout << "<-- User Menu -->\n"
					<< "---------------------\n"
					<< "1- List all friends\n"
					<< "2- Search for a friend\n"
					<< "3- Add friend\n"
					<< "4- Remove friend\n"
					<< "5- People you may know\n"
					<< "6- Logout\n";
				cin >> userMenuChoice;
				switch (userMenuChoice)
				{
				//UserMenu -> List all friends
				case 1:
					loggedUser->printFriends();
					cout << endl;
					break;
				//UserMenu -> Search for a friend
				case 2:
				{
					string username;
					cout << "Enter username of friend: ";
					cin >> username;
					if (loggedUser->searchFriend(username))
						cout << "User found: " << *users.get(username) << endl << endl;
					else
						cout << "User not found!\n\n";
					break;
				}
				//UserMenu -> Add friend
				case 3:
				{
					string username;
					cout << "Enter username of friend to add: ";
					cin >> username;
					if (loggedUser->searchFriend(username))
						cout << "You are already friends\n\n";
					else
					{
						User* friendUser = users.get(username);
						if (friendUser == nullptr)
						{
							cout << "No account was found with this username!\n\n";
							break;
						}
						loggedUser->addFriend(friendUser);
						friendUser->addFriend(loggedUser);
						cout << "You are now friends\n\n";
					}
					break;
				}
				//UserMenu -> Remove friend
				case 4:
				{
					string username;
					cout << "Enter username of friend to remove: ";
					cin >> username;
					if (loggedUser->searchFriend(username))
					{
						User* friendUser = users.get(username);
						loggedUser->removeFriend(friendUser);
						friendUser->removeFriend(loggedUser);
						cout << "Done\n\n";
					}
					break;
				}
				//UserMenu -> People you may know
				case 5:
					peopleYouMayKnow(users, loggedUser);
					break;
				//UserMenu -> Logout
				case 6:
					break;
				//UserMenu -> "invalid input"
				default:
					cout << "Invalid choice!\n\n";
					break;
				}
			}

			break;
		}
		//MainMenu -> Exit
		case 2:
			break;
		//MainMenu -> "invalid input"
		default:
			cout << "Invalid choice!\n\n";
			break;
		}
	}
}