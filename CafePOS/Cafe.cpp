#include <stdio.h>
#include <stdlib.h>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include "Menu.h"
#include "Receipt.h"
#include "ChangeManager.h"

using namespace CafePOS;

Menu menu;
Receipt receipt;
ChangeManager changemanager;

int main()
{
    menu.order(receipt);
    //changemanager.set_change_amount(receipt.current_total);
    changemanager.set_change_amount(3.40);
}
