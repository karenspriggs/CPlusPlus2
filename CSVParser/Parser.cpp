#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <cstdlib>
#include <map>
#include <algorithm>

#include "Restaurant.h";
#include "LocationData.h"

std::vector<Restaurant> restaurant_cases;
std::vector<LocationData> sorted_data;
std::string fileaddress;

void parse_csv_to_case(Restaurant restaurant, std::stringstream& row) {
    int index = 0;
    std::string lineinfo;

    while (row.good()) {
        getline(row, lineinfo, ',');
        restaurant.set_value(index, lineinfo);
        index++;
    }

    std::cout << "Case parsed";

    restaurant.print_data();

    restaurant_cases.push_back(restaurant);
}  

void parse_file( ) {
    std::ifstream sourcefile;
    std::vector<std::string> temprow;
    std::string row;
    
    sourcefile.open(fileaddress);

    if (sourcefile.is_open()) {
        while (sourcefile.good()) {
            getline(sourcefile, row);
            std::stringstream s(row);

            Restaurant r;
            parse_csv_to_case(r, s);
            row.clear();
        }

        sourcefile.close();
    }
    else {
        std::cout << "File is closed or not found";
    }
}

void sort_file() {
    std::map<int, LocationData> ZipCodeData;

    for (Restaurant& restaurantcase : restaurant_cases) {
        if (!ZipCodeData.count(restaurantcase.ZipCode)) {
            ZipCodeData.insert(std::pair<int, LocationData>(restaurantcase.ZipCode, LocationData(restaurantcase.ZipCode)));
        }

        sorted_data.at((restaurantcase.ZipCode)).AnalyzeCase(restaurantcase);
    }

    for (auto I = ZipCodeData.begin(); I != ZipCodeData.end(); I++) {
        sorted_data.push_back(I->second);
    }

    std::sort(sorted_data.begin(), sorted_data.end());
}

void print_results() {
    for (LocationData& locationdata : sorted_data){
        std::cout << "ZIP Code:";
        std::cout << locationdata.GetZip();
        std::cout << "\nFailure Count:";
        std::cout << locationdata.GetFailureCount();
        std::cout << "\nDate of Last Failure:";
        std::cout << locationdata.GetDateString();
    }
}

int main()
{
    fileaddress = "Food_Inspections.csv";

    parse_file();
    sort_file();

    print_results();
}

