#include <stdio.h>
#include <stdlib.h>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include "Deck.h"
#include "Player.h"

using namespace Euchre;
using namespace std;

// Deck Class Constructor
Deck::Deck() {
    add_cards();
    shuffle();
}

// Adding Cards to the Deck
void Deck::add_cards() {
    // 0 is clover, 1 is hearts, 2 is clubs, 3 is diamonds for card suits
    int index = 0;
    for (int i = 0; i < 4; i++) {
        for (int j = 9; j < 15; j++) {
            // 14 is ace
            // 9 
            // 10
            // jack - 11
            // queen - 12
            // king - 13
            // ace - 14
            cards[index].Suit = i;
            cards[index].Value = j;

            index++;
        }
    }
    //cout << "Added cards to deck: \n";
}

void Deck::shuffle() {
    // For loop so it goes through "every" element in the deck shh
    // Generate new random index and then save the values of the card at the new one
    // Replace values of second card with first card
    // Repeat
    int newSuit = 0;
    int newValue = 0;

    int oldSuit = 0;
    int oldValue = 0;
    int index = 23;
    
    for (int i = 0; i < 24; i++) {
        oldSuit = cards[i].Suit;
        oldValue = cards[i].Value;

        // Can't use random like this or else you get copies of cards
        // Figure out a better way
        //int index = rand() % 24;
        int newSuit = cards[index].Suit;
        int newValue = cards[index].Value;

        cards[i].Suit = newSuit;
        cards[i].Value = newValue;
        index--;
    }

    //cout << index;
    //cout << indexNew;
}

void Deck::fill_hand(Player& player, int index) {
    for (int i = 0; i < 6; i++) {
        // so this can be used to give players different cards in deck with same function
        int newindex = index + i;
        Card newcard = cards[newindex];

        // Add card to players hand at index i
        player.add_card(newcard.Suit, newcard.Value, i);
    }
}

// Drawing a card from deck for us in for loop in match
Card Deck::draw_card(int index) {
    return cards[index];
}