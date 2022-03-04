#include <stdio.h>
#include <stdlib.h>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include "Player.h"
#include "Card.h"

using namespace Euchre;
using namespace std;

Player::Player() {
    
}

void Player::add_card(int suit, int value, int index) {
    hand[index].Suit = suit;
    hand[index].Value = value;
    cout << "Index: ";
    cout << index;
    cout << "\nSuit: ";
    cout << hand[index].Suit;
    cout << "\nValue: ";
    cout << hand[index].Value;
    cout << "\n";
}

// Choosing a card to play (just returns the card)
int Player::choose_card(int currentsuit, int trumpsuit, bool partnerace) {
    Card card_to_play;
    int ChosenSuit;
    int ChosenValue;
    int index;

    // Checking to see if the player has any cards of the trump suit
    // If partner has played an ace dont trump it
    if (check_for_trump(trumpsuit) && !partnerace) {
        cout << "I played a card of the trump suit\n";
        index = find_highest_suit_specific(trumpsuit);
    } else {
        // Checking to see if the player has any cards of the current suit
        if (check_for_current(currentsuit)) {
            cout << "I played a card of the chosen suit\n";
            index = find_highest_suit_specific(currentsuit);
        }
        else {
            // If they have neither, just find the highest other one
            cout << "\nI played a card of some other suit\n";
            index = find_highest_index();
        }
    }

    ChosenValue = hand[index].Value;
    ChosenSuit = hand[index].Suit;

    // Remember to write something to remove the card from the list
    cout << "The card that was played was the ";
    cout << ChosenValue;
    cout << " of ";
    cout << ChosenSuit;
    cout << "\n";
    //card_to_play.Describe();
    return index;
}


bool Player::check_for_trump(int trumpsuit) {
    // Checks to see if the player has a card from the trump suit
    for (int i = 0; i < 5; i++) {
        if (hand[i].Suit == trumpsuit && hand[i].Value != 1) {
            cout << "\nI found a card of the trump suit\n";
            return true;
        }
    }

    return false;
}

bool Player::check_for_current(int currentsuit) {
    // Check to see if the player has a card from the current chosen suit
    for (int i = 0; i < 5; i++) {
        if (hand[i].Suit == currentsuit && hand[i].Value != 1) {
            cout << "\nI found a card of the chosen suit\n";
            return true;
        }
    }

    return false;
}

int Player::find_highest_index() {
    int current_highest_index = 0;

    for (int i = 0; i < 5; i++) {
        if (hand[current_highest_index].Value <= hand[i].Value) {
            current_highest_index = i;
        }
    }

    return current_highest_index;
}

int Player::find_highest_suit_specific(int suit) {
    int current_highest_index = 0;

    for (int i = 0; i < 5; i++) {
        if (hand[i].Suit == suit) {
            if (hand[current_highest_index].Value <= hand[i].Value) {
                current_highest_index = i;
            }
        }
    }

    return current_highest_index;
}

int Player::choose_trump(int amount) {
    // Takes in a parameter because I want to see if anyone has 3 of something first and if nobody does
    // I check for 2 etc
    // The 4 is to check for something like this, since if it returns 4 when I'm checking for 3 of the 
    // same card it means I have to check for 2 instead
    // Also for checking for the other maker team member
    // I assume players with a lot of cards with the same suit would want the trump to be that suit


    int result = 4;
    // 0 is clover, 1 is hearts, 2 is clubs, 3 is diamonds for card suits
    int clovers_count = 0;
    int hearts_count = 0;
    int clubs_count = 0;
    int diamonds_count = 0;

    for (int i = 0; i < 5; i++) {
        switch (hand[i].Suit) {
        case(0):
            clovers_count++;
            break;
        case(1):
            hearts_count++;
            break;
        case(2):
            clubs_count++;
            break;
        case(3):
            diamonds_count++;
            break;
        }
    }

    if (clovers_count >= amount) {
        result = 0;
    }

    if (hearts_count >= amount) {
        result = 1;
    }

    if (clubs_count >= amount) {
        result = 2;
    }

    if (diamonds_count >= amount) {
        result = 3;
    }

    return result;
}

void Player::remove_card_from_hand(int index) {
    // Basically make the value so low that it will never be chosen again
    hand[index].Value = 1;
}