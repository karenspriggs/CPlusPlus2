#include <stdio.h>
#include <stdlib.h>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include "Deck.h"

using namespace Euchre;

// Deck Class Constructor
Deck::Deck(){

}

// Allocating Memory
void Deck::allocate(){
    int memory_size = 24 * sizeof(Card);
    cards = (Card*)malloc(memory_size);
}

// Adding Cards to the Deck
void Deck::add_cards(){
    // 1 is clover, 2 is hearts, 3 is clubs, 4 is diamonds for card suits
    int index = 0;
    for (int i = 0; i < 5; i++){
        for (int j = 9; j < 14; j++){
            // 13 is ace
            //Card newcard = new Card(j, i);
            //cards[index] = newcard;
            index++;
        }
    }
}

// Drawing a card from deck for us in for loop in match
Card Deck::draw_card(int index){
    return cards[index];
}