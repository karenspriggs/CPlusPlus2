#include <stdio.h>
#include <stdlib.h>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include "Menu.h"

using namespace CafePOS;

Menu::Menu() {
    setup();
    print_menu();
}

void Menu::setup() {
    MenuList[0].Name = "Latte";
    MenuList[0].Price = 4.65;
    MenuList[1].Name = "Cappuccino";
    MenuList[1].Price = 5.43;
    MenuList[2].Name = "Hot Chocolate";
    MenuList[2].Price = 3.75;
    MenuList[3].Name = "Matcha Latte";
    MenuList[3].Price = 4.89;
    MenuList[4].Name = "Strawberry Lemonade";
    MenuList[4].Price = 5.39;
    MenuList[5].Name = "Caramel Macciato";
    MenuList[5].Price = 4.92;
    MenuList[6].Name = "Caffe Mocha";
    MenuList[6].Price = 3.53;
    MenuList[7].Name = "Peach Tea";
    MenuList[7].Price = 4.27;
}

void Menu::print_menu() {
    cout << "Menu: \n";

    for (int i = 0; i < 8; i++) {
        cout << i+1;
        cout << ": ";
        cout << MenuList[i].Name;
        cout << " $";
        cout << MenuList[i].Price;
        cout << "\n";
    }
}

void Menu::add_item(Receipt& r, Item i) {
    r.itemsPurchased.push_back(i);
}

void Menu::order(Receipt& r) {
    bool still_ordering = true;
    int index = 0;
    int amount = 0;

    while (still_ordering) {
        cout << "Enter the number for the item you want to add to your order:\n";
        cout << "Enter 0 when you want to stop ordering.\n";
        cin >> selected_item;
        index = selected_item;

        if (index != 0) {
            cout << "Now enter the quantity you would like: ";
            cin >> amount;

            for (int i = 0; i < amount; i++) {
                add_item(r, MenuList[index]);
                r.current_total += MenuList[index].Price;
            }

            cout << "You selected ";
            cout << amount;
            cout << " ";
            cout << MenuList[index].Name;
            cout << "\n";

            //cout << r.current_total;
        }
        else {
            still_ordering = false;
        }
    }
    
}