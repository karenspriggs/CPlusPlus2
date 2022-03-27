#include <stdio.h>
#include <stdlib.h>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include "Item.h"

using namespace CafePOS;
using namespace std;

Item::Item(){

}

Item::Item(char name[], double price){
    //Name = name;
    Price = price;
}

void Item::Describe(){
    cout << Name;
    cout << ": $";
    cout << Price;
}