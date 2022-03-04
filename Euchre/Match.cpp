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

    show_results();
}

void Match::add_member_to_team(Player player, Team team) {
    // Later on this will assign players to teams depending on if they chose trump idk
}

void Match::determine_trump() {
    // Each player takes turns running choose trump with 3 as an argument if any of them return anything other than 4 add them to the makers
    // Then do the same with 2 as an argument first to not do 4 is on the makers too, rest go to defenders
}

void Match::play_game() {
    setup();
    // Plays five rounds
    for (int i = 0; i < 5; i++) {
        play_round();
        current_player_id = 0;
        current_highest = 0;
    }
    end_game();
    deck.shuffle();
}

void Match::choose_suit() {
    trump_suit = 0;
}

void Match::update_highest_value(int value, int suit) {
    current_player_id++;

    if (current_highest < value && (overwrite_highest_value_suit(current_highest_suit, suit))) {
        current_highest = value;
        player_highest = current_player_id;
    }
}

bool Match::overwrite_highest_value_suit(int suit1, int suit2) {
    // In the case where two cards have the same value, this will 
    // determine which one wins (does card 2 win over card 1?)

    // Existing highest card is trump and new one isnt, return false
    if (suit1 == trump_suit && suit2 != trump_suit) {
        return false;
    }
    else {
        // Old one is a chosen suit and the new one isnt a trump, return false
        if (suit1 == chosen_suit && suit2 != trump_suit) {
            return false;
        }
    }

    // Otherwise the new one beats the old one
    return true;
}

void Match::one_player_play(Player& player) {
    int playercard_index = player.choose_card(chosen_suit, trump_suit, false);
    Card playercard = player.hand[playercard_index];
    int playervalue = playercard.Value;
    int playersuit = playercard.Suit;

    update_highest_value(playervalue, playersuit);
    player.remove_card_from_hand(playercard_index);
}

void Match::show_results() {
    cout << "\nPlayer ";
    cout << player_highest;
    cout << " won the hand!\n";
}

void Match::end_game() {

}