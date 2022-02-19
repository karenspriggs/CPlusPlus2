#include <stdio.h>
#include <stdlib.h>
#include <cstdlib>
#include <ctime>
#include <iostream>

#include "Match.h"
#include "Team.h"
#include "Deck.h"
#include "Player.h"

using namespace Euchre;

Team* makers = new Team();
Team* defenders = new Team();
Deck* deck = new Deck();

Player* player1 = new Player();
Player* player2 = new Player();
Player* player3 = new Player();
Player* player4 = new Player();

Match::Match(){
    defenders.is_defender = true;
    makers.is_defender = false;
}

void Match::setup(){
    fill_hands();
}

void Match::fill_hands(){
    // Fills the hands of each players using deck class
    deck.fill_hand(player1, 1);
    deck.fill_hand(player2, 2);
    deck.fill_hand(player3, 3);
    deck.fill_hand(player4, 4);
}

void Match::play_round(){

}

void Match::make_teams(){

}

void Match::play_game(){

}

void Match::choose_suit(){
    trump_suit = 0;  
}

void Match::update_highest(Card c){

}

void Match::end_game(){
    
}