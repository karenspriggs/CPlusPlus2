#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <cstdlib>
#include "Restaurant.h"

struct Date {
	int Month;
	int Day;
	int Year;

	Date() {
		Month = 0;
		Day = 0;
		Year = 0;
	}

	Date(int newmonth, int newday, int newyear) {
		Month = newmonth;
		Day = newday;
		Year = newyear;
	}

	std::string DateToString() {
		return std::to_string(Day) + "of" + std::to_string(Month) + "of" + std::to_string(Year);
	}
};


class LocationData
{
	int ZipCode;
	int FailureCount;
	Date InspectionDate;
public:
	LocationData(int Zip) {
		ZipCode = Zip;
		FailureCount = 0;
	}

	int GetZip(){return ZipCode;}
	int GetFailureCount(){return FailureCount;}
	std::string GetDateString(){return InspectionDate.DateToString();}

	void AnalyzeCase(Restaurant& restaurantcase);
	void ConvertDate(std::string dateString);
};

