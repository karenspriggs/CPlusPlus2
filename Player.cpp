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

// Choosing a card to play (just returns the card)
Card Player::choose_card(){

}

// Update players score based on tricks won
void Player::update_score(){
    this->score++;
}