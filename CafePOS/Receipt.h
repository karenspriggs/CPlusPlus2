#pragma once
#include "Item.h"
#include<list> 

using namespace std;  

namespace CafePOS{
    class Receipt {
    public:
    double current_total = 0.00;
    list<Item> itemsPurchased;
    };
}