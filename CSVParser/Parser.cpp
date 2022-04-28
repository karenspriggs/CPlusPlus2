#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <cstdlib>
#include "Restaurant.h";

std::vector<Restaurant> restaurant_cases;
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

int main()
{
    fileaddress = "Food_Inspections.csv";
    parse_file();
}

