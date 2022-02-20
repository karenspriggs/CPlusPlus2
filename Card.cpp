#include <stdio.h>
#include <stdlib.h>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include "Card.h"

using namespace Euchre;

Card::Card(int value, int suit){
    this->Value = value;
    this->Suit = suit;
}

void Card::Describe(){
    
}