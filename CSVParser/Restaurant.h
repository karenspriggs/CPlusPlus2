#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <cstdlib>

class Restaurant
{
	public:
		int InspectionID = 0;
		std::string DBAName = "";
		std::string AKAName = "";
		int LicenseNumber = 0;
		std::string FacilityType = "";
		std::string RiskLevel = "";
		std::string Address = "";
		std::string City = "";
		std::string State = "";
		int ZipCode = 0;
		std::string InspectionDate = "";
		std::string InspectionType = "";
		std::string Results = "";
		std::string Violations = "";
		double Latitude = 0;
		double Longitude = 0;
		std::string location = "";
		Restaurant();
		Restaurant(std::vector<std::string> info);
		void set_value(int index, std::string data);
		void print_data();
};

