#include <stdio.h>
#include <stdlib.h>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include "Player.h"
#include "Card.h"

using namespace Euchre;

Player::Player() {
    allocate_hand();
}

// Allocating for Player's Hand
void Player::allocate_hand() {
    hand = new Card[5];
}

void Player::add_card(int suit, int value, int index) {
    hand[index].Value = value;
    hand[index].Suit = suit;
}

// Choosing a card to play (just returns the card)
Card Player::choose_card(int currentsuit, int trumpsuit, bool partnerace) {
    Card card_to_play;
    // Checking to see if the player has any cards of the trump suit
    // If partner has played an ace dont trump it
    if (check_for_trump(trumpsuit) && !partnerace) {
        Card card_to_play = find_highest(trumpsuit);
    }
    else {
        // Checking to see if the player has any cards of the current suit
        if (check_for_current(currentsuit)) {
            Card card_to_play = find_highest(currentsuit);
        }
        else {
            // If they have neither, just find the highest other one
            Card card_to_play = find_general_highest();
        }
    }

    // Remember to write something to remove the card from the list
    card_to_play.Describe();
    return card_to_play;
}


bool Player::check_for_trump(int trumpsuit) {
    for (int i = 0; i > 5; i++) {
        if (hand[0].Suit == trumpsuit) {
            return true;
        }
    }

    return false;
}

bool Player::check_for_current(int currentsuit) {
    for (int i = 0; i > 5; i++) {
        if (hand[0].Suit == currentsuit) {
            return true;
        }
    }

    return false;
}

Card Player::find_general_highest() {
    int current_highest_index = 0;

    for (int i = 0; i > 5; i++) {
        if (hand[current_highest_index].Value <= hand[i].Value) {
            current_highest_index = i;
        }
    }

    return hand[current_highest_index];
}

Card Player::find_highest(int suit) {
    int current_highest_index = 0;

    for (int i = 0; i > 5; i++) {
        if (hand[0].Suit == suit) {
            if (hand[current_highest_index].Value <= hand[i].Value) {
                current_highest_index = i;
            }
        }
    }

    return hand[current_highest_index];
}

int Player::choose_trump(int amount) {
    int result = 4;
    // 0 is clover, 1 is hearts, 2 is clubs, 3 is diamonds for card suits
    int clovers_count = 0;
    int hearts_count = 0;
    int clubs_count = 0;
    int diamonds_count = 0;

    for (int i = 0; i > 5; i++) {
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