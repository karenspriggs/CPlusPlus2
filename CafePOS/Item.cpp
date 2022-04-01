#include <stdio.h>
#include <stdlib.h>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include "Item.h"
#pragma once

using namespace std;
using namespace CafePOS;

Item::Item() {

}

Item::Item(string name, double price) {
    Name = name;
    Price = price;
}

void Item::Describe() {
    cout << Name;
    cout << ": $";
    cout << Price;
}