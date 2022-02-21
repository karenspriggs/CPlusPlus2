#include <stdio.h>
#include <stdlib.h>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include "Deck.h"
#include "Player.h"

using namespace Euchre;

// Deck Class Constructor
Deck::Deck(){
    allocate();
    add_cards();
    shuffle();
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

void Deck::shuffle(){

}

void Deck::fill_hand(Player player, int index){
    for (int i = 0; i < 6; i++){
        int newindex = index + i;
        Card newcard = cards[newindex];
        player.add_card(newcard, index);
    }
}

// Drawing a card from deck for us in for loop in match
Card Deck::draw_card(int index){
    return cards[index];
}