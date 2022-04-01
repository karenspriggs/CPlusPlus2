#pragma once
#include "Item.h"
#include "Receipt.h"

namespace CafePOS{
    class Menu {
        int selected_item = 0;
        void setup();
    public:
        Item MenuList[8];
        Menu();
        void print_menu();
        void add_item(Receipt& r, Item i);
        void order(Receipt& r);
    };
}