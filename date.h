// date.h

#ifndef DATE_H_EXISTS
#define DATE_H_EXISTS

#include <string>

class Date {
	protected:
		std::string dateString;
		int month;
		int day;
		int year;
	public:
		Date();
		void init(std::string dateString);
		void printDate();
}; //end class def

#endif
