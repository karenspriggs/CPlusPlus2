#include <stdio.h>
#include <stdlib.h>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include "ChangeManager.h"

using namespace CafePOS;
using namespace std;

ChangeManager::ChangeManager() {
    
}

void ChangeManager::set_change_amount(double amount) {   
    uncalculated_total = amount;
    determine_change();
    
}

void ChangeManager::determine_change() {
    // Can a dollar be subtracted from the amount?
    if (uncalculated_total >= 1.0) {
        dollar_count++;
        uncalculated_total -= 1;
        check_if_done();
    }
    else {
        // Can a quarter be subtracted from the amount?
        if (uncalculated_total >= 0.25) {
            quarter_count++;
            uncalculated_total -= 0.25;
            check_if_done();
        }
        else {
            // Can a dime be subtracted from the amount?
            if (uncalculated_total >= 0.1) {
                dime_count++;
                uncalculated_total -= 0.1;
                check_if_done();
            }
            else {
                // Can a nickel be subtracted from the amount?
                if (uncalculated_total >= 0.05) {
                    nickel_count++;
                    uncalculated_total -= 0.05;
                    check_if_done();
                }
                else {
                    // Can a penny be subtracted from the amount?
                    if (uncalculated_total >= 0.01) {
                        penny_count++;
                        uncalculated_total -= 0.01;
                        check_if_done();
                    }
                }
            }
        }
    }
}

void ChangeManager::check_if_done() {
    if (uncalculated_total == 0.00) {
        print_change_amount();
    }
    else {
        determine_change();
    }
}

void ChangeManager::print_change_amount() {
    cout << "Your change is: \n";
    cout << dollar_count;
    cout << " dollars,\n";
    cout << quarter_count;
    cout << " quarters, \n";
    cout << dime_count;
    cout << " dimes, \n";
    cout << nickel_count;
    cout << " nickles, \nand";
    cout << penny_count;
    cout << " pennies, \n";
}