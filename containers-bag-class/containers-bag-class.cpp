
// FILE: containers-bag-class
// Demonstration of container class type bag

#include "stdafx.h"
#include <iostream>
#include <cstdlib>

using namespace std;

// PROTOTYPES
void get_ages(bag& ages);
/* Postcondition:
The user has been prompted to type in the ages of family members. 
These ages have been read and placed in the ages bag, stopping 
when the bag is full or when the user types a negative number.
*/

void check_ages(bag& ages);
/* Postcondition:
The user has been prompted to type in the ages of family members
again. Each age is removed from the ages bag when it is typed, stopping
when the bag is empty.
*/

class bag
{
public:
	// TYPEDEFS and MEMBER CONSTANTS
	typedef int value_type;
	typedef std::size_t size_type;
	static const size_type CAPACITY = 30;
private:
	value_type data[CAPACITY]; // create an array of type integer that stores items
	size_type used; // 
};

int main()
{
	bag ages;

	get_ages(ages);
	check_ages(ages);
	cout << "May your family live long and prosper." << endl;
    return EXIT_SUCCESS;
}

void get_ages(bag& ages)
{
	int user_input;

	cout << "Type the ages in your family." << endl;
	cout << "Type a negative number when you are done: " << endl;

	cin >> user_input;
	while (user_input >= 0)
	{
		if (ages.size() < ages.CAPACITY)
			ages.insert(user_input);
		else
			cout << "I have run out of room and can't add that age." << endl;
		cin >> user_input;
	}
}

void check_ages(bag& ages)
{
	int user_input;

	cout << "Type those ages again. Press return after each age:" << endl;
	while (ages.size() > 0)
	{
		cin >> user_input;
		if (ages.erase_one(user_input))
			cout << "Yes, I've found that age and removed it." << endl;
		else
			cout << "No, that age does not occur!" << endl;
	}
}