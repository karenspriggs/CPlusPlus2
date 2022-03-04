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
    defenders.add_player(player1, 1);
    defenders.add_player(player2, 2);
    makers.add_player(player3, 1);
    makers.add_player(player4, 2);
}

void Match::setup() {
    fill_hands();
    determine_teams();
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
    
    //one_player_play(player1);
    one_player_on_team_play(1, 1);

    cout << "\nPlayer two's move:\n";
    //one_player_play(player2);
    one_player_on_team_play(1, 2);

    cout << "\nPlayer three's move:\n";
    //one_player_play(player3);
    one_player_on_team_play(2, 1);

    cout << "\nPlayer four's move:\n";
    //one_player_play(player4);
    one_player_on_team_play(2, 2);

    show_results();
}

void Match::determine_teams() {
    // Each player takes turns running choose trump with 3 as an argument if any of them return anything other than 4 add them to the makers
    // Then do the same with 2 as an argument first to not do 4 is on the makers too, rest go to defenders
    Player firstmaker = find_first_maker();
    makers.add_player(firstmaker, 1);
    Player secondmaker = find_second_maker();
    makers.add_player(secondmaker, 2);
    
    make_defenders();
}

Player Match::find_first_maker() {
    int player1trumpcount = player1.choose_trump(3);
    int player2trumpcount = player2.choose_trump(3);
    int player3trumpcount = player3.choose_trump(3);
    int player4trumpcount = player4.choose_trump(3);
    Player player_to_add;

    if (player1trumpcount != 4) {
        // If trump suit is unset 
        if (trump_suit == 4) {
            trump_suit = player1trumpcount;
        }

        player_one_chosen = true;

        return player1;
    }

    if (player2trumpcount != 4) {

        if (trump_suit == 4) {
            trump_suit = player2trumpcount;
        }

        player_two_chosen = true;

        return player2;
    }

    if (player3trumpcount != 4) {
        if (trump_suit == 4) {
            trump_suit = player3trumpcount;
        }

        player_three_chosen = true;

        return player3;
    }

    if (player4trumpcount != 4) {
        if (trump_suit == 4) {
            trump_suit = player4trumpcount;
        }

        player_four_chosen = true;

        return player4;
    }

    return player_to_add;
}

Player Match::find_second_maker() {
    int player1trumpcount = player1.choose_trump(2);
    int player2trumpcount = player2.choose_trump(2);
    int player3trumpcount = player3.choose_trump(2);
    int player4trumpcount = player4.choose_trump(2);

    if (player1trumpcount == trump_suit && !player_one_chosen)
    {
        return player1;
    }

    if (player2trumpcount == trump_suit && !player_two_chosen)
    {
        return player2;
    }

    if (player3trumpcount == trump_suit && !player_three_chosen)
    {
        return player3;
    }

    if (player4trumpcount == trump_suit && !player_four_chosen)
    {
        return player4;
    }

}

void Match::make_defenders() {
    int currentID = 1;

    if (!player_one_chosen) {
        defenders.add_player(player1, currentID);
        currentID = 2;
    }

    if (!player_two_chosen) {
        defenders.add_player(player2, currentID);
        currentID = 2;
    }

    if (!player_three_chosen) {
        defenders.add_player(player3, currentID);
        currentID = 2;
    }

    if (!player_four_chosen) {
        defenders.add_player(player4, currentID);
        currentID = 2;
    }
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

void Match::one_player_on_team_play(int playerID, int teamID) {
    int playercardindex;

    if (teamID == 1) {
        playercardindex = defenders.one_player_team_play(playerID, chosen_suit, trump_suit);
    }
    else {
        playercardindex = makers.one_player_team_play(playerID, chosen_suit, trump_suit);
    }

    Card playercard = get_card_from_team(teamID, playerID, playercardindex);

    int playervalue = playercard.Value;
    int playersuit = playercard.Suit;

    update_highest_value(playervalue, playersuit);
    
    if (teamID == 1) {
        cout << "\nI tried to remove a card from the makers\n";
        makers.remove_card_at_index(playerID, playercardindex);
    }
    else {
        cout << "\nI tried to remove a card from the defenders\n";
        defenders.remove_card_at_index(playerID, playercardindex);
    }
}

Card Match::get_card_from_team(int teamID, int playerID, int index) {
    Card playercard;

    if (teamID == 1) {
        playercard = makers.return_card_at_index(playerID, index);
    }
    else {
        playercard = makers.return_card_at_index(playerID, index);
    }

    return playercard;
}

void Match::show_results() {
    cout << "\nPlayer ";
    cout << player_highest;
    cout << " won the hand!\n";
}

void Match::end_game() {

}