# CS121 Project 7 - Blackbelt

This project is a continuation of Project 7 and adds a sort functionality. Adding sort to the menu. 

## Sort Function

Addition of <algorithm> include statement. Sort will provide a menu with option to sort by first name, sort by last name, and sort by credit hours. Sort will take userMenuChoice and take the according actions. Sort will then call printStudents() from main.cpp. Expected output:

```
Sort Menu:
0) Sort by First Name
1) Sort by Last Name
2) Sort by Credit Hours

Please choose 0-2: 0

Will print all students in alphabetical order from A-Z by First Name.
```
### Sort by First Name

Output is boolean. Takes reference to two students. Get student first name from student.cpp. Return (studentA first name < studentB first name). 

### Sort by Last Name

Output is boolean. Takes reference to two students. Get student first name from student.cpp. Return (studentA last name < studentB last name). 

### Sort by Credit Hours

Output is boolean. Takes reference to two students. Get student credit hours from student.cpp. Return (studentA credit hours < student B credit hours). 

