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
Card Player::choose_card(){
    // Checking to see if the player has any cards of the trump suit
    // Play highest card of trump suit
    // Checking to see if the player has any cards of the preferred suit
    // Play highest card of preferred suit
    // Otherwise play highest card of any suit
}