// main.cpp

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
std::string menu();

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

	} //end while loop

} //end main

std::string menu(){
	std::string userInput;

	std::cout << "0) Quit" << std::endl;
	std::cout << "1) Print all student names" << std::endl;
	std::cout << "2) Print all student data" << std::endl;
	std::cout << "3) Find a student" << std::endl;

	std::cout << "Please choose 0-3: ";
	std::cin >> userInput;

	return userInput;
} //end menu()

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
