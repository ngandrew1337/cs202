/*
Lab002.cpp
Andrew Ng
Jan 23, 2020
main file for testing Jumpsuit class
*/


#include <iostream>
#include <vector>
#include "Jumpsuit.h"


Jumpsuit changeColor(Jumpsuit suit)
{
	std::string newColor = suit.getColor() + "-green";
	Jumpsuit result(newColor);
	return result;
}


Jumpsuit clearColor()
{
	Jumpsuit blank;
	return blank;
}


void printColor(const Jumpsuit& j)
{
	std::cout << "Color is: " << j.getColor() << "\n";
}


int main()
{
	std::cout << "---TESTING CONSTRUCTORS---\n";
	Jumpsuit suit1;
	Jumpsuit suitCopy(suit1);
	Jumpsuit suit2("blue");
	std::cout << "\n";

	printColor(suit1);
	printColor(suitCopy);
	printColor(suit2);
	std::cout << "\n";


	std::cout << "---TESTING NRVO---\n";
	suit2 = changeColor(suit2);
	std::cout << "\n";

	printColor(suit2);
	std::cout << "\n";

	suit2 = clearColor();
	std::cout << "\n";

	printColor(suit2);
	std::cout << "\n";


	std::cout << "---TESTING VECTOR---\n";
	std::vector<Jumpsuit> suits(5);
	for (auto& j : suits) {
		j.setColor("green");
	}
	std::cout << "\n";
}