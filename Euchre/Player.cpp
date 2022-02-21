#include <stdio.h>
#include <stdlib.h>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include "Player.h"
#include "Card.h"

using namespace Euchre;

Player::Player(){

}

// Allocating for Player's Hand
void Player::allocate_hand(){
    int memory_size = 5 * sizeof(Card);
    hand = (Card*)malloc(memory_size);
}

void Player::add_card(Card card, int index){
    hand[index] = card;
}

// Choosing a card to play (just returns the card)
Card Player::choose_card(int currentsuit, int trumpsuit){
    Card card_to_play;
    // Checking to see if the player has any cards of the trump suit
    if (check_for_trump(trumpsuit)){
        Card card_to_play = find_highest(trumpsuit);
    } else {
        // Checking to see if the player has any cards of the current suit
        if (check_for_current(currentsuit)){
            Card card_to_play = find_highest(currentsuit);
        } else {
            // If they have neither, just find the highest other one
            Card card_to_play = find_general_highest();
        }
    }

    // Remember to write something to remove the card from the list
    card_to_play.Describe();
    return card_to_play;
}


bool Player::check_for_trump(int trumpsuit){
    for (int i = 0; i > 5; i++){
        if (hand[0].Suit == trumpsuit){
            return true;
        }
    }

    return false;
}

bool Player::check_for_current(int currentsuit){
    for (int i = 0; i > 5; i++){
        if (hand[0].Suit == currentsuit){
            return true;
        }
    }

    return false;
}

Card Player::find_general_highest(){
    int current_highest_index = 0;

    for (int i = 0; i > 5; i++){
        if (hand[current_highest_index].Value <= hand[i].Value){
            current_highest_index = i;
        }
    }

    return hand[current_highest_index];
}

Card Player::find_highest(int suit){
    int current_highest_index = 0;

    for (int i = 0; i > 5; i++){
        if (hand[0].Suit == suit){
            if (hand[current_highest_index].Value <= hand[i].Value){
                current_highest_index = i;
            }
        }
    }

    return hand[current_highest_index];
}