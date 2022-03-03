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
using namespace std;

Team* makers = new Team();
Team* defenders = new Team();
Deck* deck = new Deck();

Player* player1 = new Player();
Player* player2 = new Player();
Player* player3 = new Player();
Player* player4 = new Player();

Match::Match() {

    defenders.is_defender = true;
    makers.is_defender = false;
}

void Match::setup() {
    fill_hands();
}

void Match::fill_hands() {
    // Fills the hands of each players using deck class
    // Hands are filling correctly
    deck.fill_hand(player1, 0);
    deck.fill_hand(player2, 6);
    deck.fill_hand(player3, 12);
    deck.fill_hand(player4, 18);
}

void Match::play_round() {
    cout << "\nPlayer one's move:\n";
    one_player_play(player1);
    
    cout << "\nPlayer two's move:\n";
    one_player_play(player2);
    
    cout << "\nPlayer three's move:\n";
    one_player_play(player3);
    
    cout << "\nPlayer four's move:\n";
    one_player_play(player4);
}

void Match::make_teams() {
    // Later on this will assign players to teams depending on if they chose trump idk
}

void Match::play_game() {
    setup();
    // Plays five rounds
    for (int i = 0; i < 5; i++) {
        play_round();
    }
    end_game();
    deck.shuffle();
}

void Match::choose_suit() {
    trump_suit = 0;
}

void Match::update_highest(Card c) {
    if (current_highest < c.Value) {
        current_highest = c.Value;
    }
}

void Match::one_player_play(Player& player) {
    int playercard_index;

    // hardcoded highest played for now to test
    playercard_index = player.choose_card(chosen_suit, trump_suit, false);
    Card playercard = player.hand[playercard_index];
    update_highest(playercard);
    player.remove_card_from_hand(playercard_index);
}

void Match::end_game() {

}