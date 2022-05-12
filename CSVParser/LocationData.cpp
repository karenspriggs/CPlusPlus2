#include "LocationData.h"

void LocationData::AnalyzeCase(Restaurant& restaurantcase) {
	if (restaurantcase.Results == "Fail") {
		FailureCount++;

		if (restaurantcase.InspectionDate == "#") {
			return;
		}

		ConvertDate(restaurantcase.InspectionDate);
	}
}

void LocationData::ConvertDate(std::string dateString) {
	std::string Data;
	auto thischar = --dateString.end();

	while (*thischar != '/') {
		Data += *thischar;
		thischar--;
	}

	std::reverse(Data.begin(), Data.end());
	int NewYear = std::stoi(Data);

	if (NewYear < InspectionDate.Year) {
		return;
	}

	Data.clear();

	thischar = --dateString.begin();

	while (*thischar != '/') {
		Data += *thischar;
		thischar++;
	}

	int NewMonth = std::stoi(Data);

	if (NewMonth < InspectionDate.Month) {
		return;
	}

	Data.clear();

	while (*thischar != '/') {
		Data += *thischar;
		thischar++;
	}
	
	int NewDay = std::stoi(Data);

	if (NewDay < InspectionDate.Day) {
		return;
	}

	InspectionDate = Date(NewMonth, NewDay, NewYear);
 }