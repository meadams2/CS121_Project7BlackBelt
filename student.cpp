// student.cpp

#include <string>
#include <sstream>
#include <iostream>
#include "date.h"
#include "address.h"
#include "student.h"

Student::Student(){
	Student::studentString = "";
	Student::firstName = "";
	Student::lastName = "";
	birthDate = new Date();
	gradDate = new Date();
	address = new Address();
	Student::creditHours = 0;
} //end constructor

Student::~Student(){
	delete birthDate;
	delete gradDate;
	delete address;
} //end destructor

void Student::init(std::string studentString) {
	Student::studentString = studentString;

	
	std::stringstream converter;


	std::string firstName;
	std::string lastName;

	std::string sBirthDate;
	std::string sGradDate;

	std::string sStreet;
	std::string sCity;
	std::string sState;
	std::string sZip;
	std::string sCreditHours;

	Student::firstName;
	Student::lastName;
	Student::creditHours;

	converter.clear();
	converter.str(studentString);
	
	getline(converter, firstName, ',');
	getline(converter, lastName, ',');
	//getline(converter, sAddress, ',');
	getline(converter, sStreet, ',');
	getline(converter, sCity, ',');
	getline(converter, sState, ',');
	getline(converter, sZip, ',');
	getline(converter, sBirthDate, ',');
	getline(converter, sGradDate, ',');
	getline(converter, sCreditHours);

	converter.clear();
	converter.str(firstName);
	converter >> Student::firstName;

	converter.clear();
	converter.str(lastName);
	converter >> Student::lastName;

	address->init(sStreet, sCity, sState, sZip);
	
	
	converter.clear();
	converter.str(sBirthDate);
	birthDate->init(sBirthDate);

	converter.clear();
	converter.str(sGradDate);
	gradDate->init(sGradDate); 
	
	converter.clear();
	converter.str(sCreditHours);
	converter >> Student::creditHours;
} //end init

std::string Student::getFirstName(){
	return firstName;
} //end getFirstName

std::string Student::getLastName(){
	return lastName;
} //end getLastName

std::string Student::getLastFirst(){
	std::string lastFirst = lastName + "," + firstName;
	return lastFirst;
} //end getLastFirst

int Student::getCreditHours(){
	return creditHours;
} //end getCreditHours

void Student::printStudent(){
	std::cout << getFirstName() << " " << getLastName() << std::endl;
	address->printAddress(); 
//	std::cout << std::endl;
	std::cout << "DOB: ";
	birthDate->printDate();
	std::cout << "Grad: ";
       	gradDate->printDate();
	std::cout << "Credits: " << getCreditHours() << std::endl;
	std::cout << std::endl;
	//std::cout << getLastName() << "," << getFirstName() << std::endl;
} // end printStudent
