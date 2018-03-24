#include <iostream>
#include "Date.h"

void test(Date date, int max, int step = 1) {
	int errors = 0;

	for (int i = step; i < max; i += step) {
		Date d1 = date + i;
		Date d2 = d1 - i;

		if (d2 != date) {
			std::cout << "d1 = date + " << i << ": " << d1 << ", d2 = d1 - " << i << ": " << d2 << std::endl;
			errors++;
		}
	}

	for (int i = 0; i < 10000; i++) {
		int dt = rand() % 100000;

		Date d1 = date + dt;
		Date d2 = d1 - dt;

		if (d2 != date) {
			std::cout << "d1 = date + " << dt << ": " << d1 << ", d2 = d1 - " << dt << ": " << d2 << std::endl;
			errors++;
		}
	}

	if (!errors)
		std::cout << "\tTest is passed!" << std::endl;
}

int main() {
	Date date;
	int days;
	
	try {
		std::cout << "Enter date: ";
		std::cin >> date;
		std::cout << "Date for next testing is " << date << std::endl;
		std::cout << "\tDay of week: " << date.toStringWeekDay() << std::endl;
		std::cout << "\tDay of year: " << date.getDayOfYear() << std::endl;
		std::cout << "\tDays in month: " << date.getDaysInMonth() << std::endl;
		std::cout << "\tIs year leap: " << date.isYearLeap() << std::endl;
		std::cout << "\tDays from start: " << date.toDays() << std::endl;

		std::cout << std::endl << "Add/sub testing:" << std::endl;
		test(date, 50000, 1);

		std::cout << std::endl;
		std::cout << "Enter days to add: ";
		std::cin >> days;

		Date d1 = date + days;
		std::cout << date << " + " << days << " days: " << d1 << " (" << d1.toStringWeekDay() << ")" << std::endl;

		std::cout << "Enter days to sub: ";
		std::cin >> days;

		Date d2 = date - days;
		std::cout << date << " - " << days << " days: " << d2 << " (" << d2.toStringWeekDay() << ")" << std::endl;

		std::cout << std::endl << "Difference testing:" << std::endl;

		std::cout << "\tBetween " << d2 << " and " << d1 << ": " << (d2 - d1) << std::endl;
		std::cout << "\tBetween " << d1 << " and " << d2 << ": " << (d1 - d2) << std::endl;

		std::cout << std::endl << "Compare testing:" << std::endl;
		std::cout << "\t" << d1 << " < " << d2 << ": " << (d1 < d2) << std::endl;
		std::cout << "\t" << d1 << " <= " << d2 << ": " << (d1 <= d2) << std::endl;
		std::cout << "\t" << d1 << " > " << d2 << ": " << (d1 > d2) << std::endl;
		std::cout << "\t" << d1 << " >= " << d2 << ": " << (d1 >= d2) << std::endl;
		std::cout << "\t" << d1 << " == " << d2 << ": " << (d1 == d2) << std::endl;
		std::cout << "\t" << d1 << " != " << d2 << ": " << (d1 != d2) << std::endl;
	} catch (std::string s) {
		std::cout << "Exception! Message: " << s << std::endl;
	}
}
