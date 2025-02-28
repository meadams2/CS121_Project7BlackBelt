// main.cpp

#include <algorithm>
#include <memory>
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>

#include "date.h"
#include "address.h"
#include "student.h"

void loadStudents(std::vector<std::shared_ptr<Student>>& students);
void printStudents(std::vector<std::shared_ptr<Student>>& students);
void showStudentNames(std::vector<std::shared_ptr<Student>>& students);
void findStudent(std::vector<std::shared_ptr<Student>>& students);
void delStudents(std::vector<std::shared_ptr<Student>>& students);

void sortStudents(std::vector<std::shared_ptr<Student>>& students);
bool sortByFirstName(Student& a, Student& b);
bool sortByLastName(Student& a, Student& b);
bool sortByCreditHours(Student& a, Student& b);

std::string menu();
std::string sortMenu();

int main(){
	std::vector<std::shared_ptr<Student>> students;
	loadStudents(students);
	bool keepGoing = true;

	while (keepGoing){
		std::string userInput = menu();

		if (userInput == "0"){
			delStudents(students);
			keepGoing = false;
		} //End quit condition
		
		else if (userInput == "1"){
			showStudentNames(students);
		} //End studentNames condition

		else if (userInput == "2"){
			printStudents(students);
		} //End print students condition

		else if (userInput == "3"){
			findStudent(students);
		} //End find student condition
		
		else if (userInput == "4"){
			sortStudents(students);
		} //End sortStudent condition
	} //end while loop

} //end main

std::string menu(){
	std::string userInput;

	std::cout << "0) Quit" << std::endl;
	std::cout << "1) Print all student names" << std::endl;
	std::cout << "2) Print all student data" << std::endl;
	std::cout << "3) Find a student" << std::endl;
	std::cout << "4) Sort students" << std::endl;
	std::cout << "Please choose 0-4: ";
	std::cin >> userInput;

	return userInput;
} //end menu()

std::string sortMenu(){
	std::string sortChoice;
	std::cout << "How would you like to sort?" << std::endl;
	std::cout << "0) First name" << std::endl;
	std::cout << "1) Last name" << std::endl;
	std::cout << "2) Credit Hours" << std::endl;
	std::cout << "Please choose 0-2: ";

	std::cin >> sortChoice;
	return sortChoice;
} //end sortMenu()

void loadStudents(std::vector<std::shared_ptr<Student>>& students){
	std::ifstream inFile;
	std::stringstream converter;
	std::string studentString;

	inFile.open("students.csv");
	while (getline(inFile, studentString)){
		converter.clear();
		converter.str(studentString);

		auto student = std::make_shared<Student>();
		student->init(studentString);
		students.push_back(student);
	} //end while loop
} //end loadStudents

void delStudents(std::vector<std::shared_ptr<Student>>& students){
	bool keepGoing = true;
	while (keepGoing){
		if (students.empty()){
			keepGoing = false;
		} //end if
		else {
			students.clear();
		} //end else
	} //end while loop
} //end delStudents

void showStudentNames(std::vector<std::shared_ptr<Student>>& students){
	for (auto& item: students){
		std::cout << item->getLastFirst() << std::endl;
	} //end for loop
	std::cout << std::endl;
} //end showStudentNames

void printStudents(std::vector<std::shared_ptr<Student>>& students){
	for (auto& item: students){
		item->printStudent();
	} //end for loop
} //end printStudents()

void findStudent(std::vector<std::shared_ptr<Student>>& students){
	std::string lastNameChoice;
	std::cout << "Last Name of Student: ";
	std::cin >> lastNameChoice;
	for (auto& item: students){
		std::string studentsName = item->getLastName();
		std::size_t studentFound = studentsName.find(lastNameChoice);
		if (studentFound != std::string::npos){
			item->printStudent();
		} //end if
		std::cout << std::endl;
	} //end for loop
} // end findStudent()

void sortStudents(std::vector<std::shared_ptr<Student>>& students){
	std::string sortChoice = sortMenu();
	if (sortChoice == "0"){
		std::sort(students, sortByFirstName);
	} //end firstName sort condition

	else if (sortChoice == "1"){
		std::sort(students, sortByLastName);
	} //end lastName sort condition

	else if (sortChoice == "2"){
		std::sort(students, sortByCreditHours);
	} //end creditHours sort condition

	printStudents(students);
} //end sortStudents()

bool sortByFirstName(Student& a, Student& b){
	return (a.getFirstName() < b.getFirstName());
} //end sortByFirstName

bool sortByLastName(Student& a, Student& b){
	return (a.getLastName() < b.getLastName());
} //end sortByLastName

bool sortByCreditHours(Student& a, Student& b){
	return (a.getCreditHours() < b.getCreditHours());
} //end sortByCreditHours
