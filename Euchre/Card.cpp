#include <stdio.h>
#include <stdlib.h>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include "Card.h"

using namespace Euchre;
using namespace std;

Card::Card(int value, int suit){
    this->Value = value;
    this->Suit = suit;
}

void Card::Describe(){
    cout << "The card that was played was the ";
    cout << Value;
    cout << " of ";
    cout << Suit;
}