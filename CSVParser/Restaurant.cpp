#include "Restaurant.h"

Restaurant::Restaurant() {

}

Restaurant::~Restaurant() {

}

Restaurant::Restaurant(std::vector<std::string> info) {

}

void Restaurant::set_value(int index, std::string data) {
    switch (index) {
    case(0):
        this->InspectionID = stoi(data);
        break;
    case(1):
        this->DBAName = data;
        break;
    case(2):
        this->AKAName = data;
        break;
    case(3):
        this->LicenseNumber = stoi(data);
        break;
    case(4):
        this->FacilityType = data;
        break;
    case(5):
        this->RiskLevel = data;
        break;
    case(6):
        this->Address = data;
        break;
    case(7):
        this->City = data;
        break;
    case(8):
        this->State = data;
        break;
    case(9):
        this->ZipCode = stoi(data);
        break;
    case(10):
        this->InspectionDate = data;
        break;
    case(11):
        this->InspectionType = data;
        break;
    case(12):
        this->Results = data;
        break;
    case(13):
        this->Violations = data;
        break;
    case(14):
        this->Latitude = atof(data.c_str());
        break;
    case(15):
        this->Longitude = atof(data.c_str());
        break;
    case(16):
        this->location = data;
        break;
    }
}

void Restaurant::print_data() {

}