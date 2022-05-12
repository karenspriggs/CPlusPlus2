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
	auto currentchar = --dateString.end();

	while (*currentchar != '/') {
		Data += *currentchar;
		currentchar--;
	}

	std::reverse(Data.begin(), Data.end());
	int NewYear = std::stoi(Data);

	if (NewYear < InspectionDate.Year) {
		return;
	}

	Data.clear();

	currentchar = --dateString.begin();

	while (*currentchar != '/') {
		Data += *currentchar;
		currentchar++;
	}

	int NewMonth = std::stoi(Data);

	if (NewMonth < InspectionDate.Month) {
		return;
	}

	Data.clear();

	while (*currentchar != '/') {
		Data += *currentchar;
		currentchar++;
	}
	
	int NewDay = std::stoi(Data);

	if (NewDay < InspectionDate.Day) {
		return;
	}

	InspectionDate = Date(NewMonth, NewDay, NewYear);
 }