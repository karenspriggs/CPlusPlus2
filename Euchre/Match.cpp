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
    one_player_play(player1);
    one_player_play(player2);
    one_player_play(player3);
    one_player_play(player4);
}

void Match::make_teams(){
    // Later on this will assign players to teams
}

void Match::play_game(){
    for (int i = 0; i < 5; i++){
        play_round();
    }
    end_game();
}

void Match::choose_suit(){
    trump_suit = 0;  
}

void Match::update_highest(Card c){
    if (current_highest < c.Value){
        current_highest = c.Value;
    }
}

void Match::one_player_play(Player player){
    Card playercard;
    playercard = player.choose_card(chosen_suit, trump_suit);
    update_highest(playercard);
}

void Match::end_game(){
    
}