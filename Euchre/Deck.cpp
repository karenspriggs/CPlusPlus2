#include <stdio.h>
#include <stdlib.h>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include "Deck.h"
#include "Player.h"

using namespace Euchre;

// Deck Class Constructor
Deck::Deck() {
    allocate();
    add_cards();
    shuffle();
}

// Allocating Memory
void Deck::allocate() {
    //cards = new Card[24];
}

// Adding Cards to the Deck
void Deck::add_cards() {
    // 0 is clover, 1 is hearts, 2 is clubs, 3 is diamonds for card suits
    int index = 0;
    for (int i = 0; i < 5; i++) {
        for (int j = 9; j < 14; j++) {
            cards[index].Suit = i;
            cards[index].Value = j;
            index++;  
        }
    }
}

void Deck::shuffle() {

}

void Deck::fill_hand(Player player, int index) {
    for (int i = 0; i < 5; i++) {
        // so this can be used to give players different cards in deck with same function
        int newindex = index + i;
        int suit = cards[newindex].Suit;
        int value = cards[newindex].Value;

        // Add card to players hand at index i
        player.add_card(suit, value, i);
    }
}

// Drawing a card from deck for us in for loop in match
Card Deck::draw_card(int index) {
    return cards[index];
}