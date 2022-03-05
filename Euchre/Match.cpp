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
    one_player_on_team_play(1, 1);

    cout << "\nPlayer two's move:\n";
    one_player_on_team_play(1, 2);

    cout << "\nPlayer three's move:\n";
    one_player_on_team_play(2, 1);

    cout << "\nPlayer four's move:\n";
    one_player_on_team_play(2, 2);

    show_results();
    update_results();
    current_player_id = 0;
    player_highest = 0;
    current_highest = 0;
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

void Match::determine_teams() {
    // First maker is whoever bids a trump by having 3 of the same suit cards in their hand 
    Player firstmaker = find_first_maker();
    makers.add_player(firstmaker, 1);

    // Second maker is whoever bids a trump by having 2 of the same suit cards in their hand 
    Player secondmaker = find_second_maker();
    makers.add_player(secondmaker, 2);
    
    // Make the other team
    make_defenders();
}

Player Match::find_first_maker() {
    int player1trumpcount = player1.choose_trump(3);
    int player2trumpcount = player2.choose_trump(3);
    int player3trumpcount = player3.choose_trump(3);
    int player4trumpcount = player4.choose_trump(3);
    Player player_to_add;

    // Goes on a first checked first set basis I guess

    if (player1trumpcount != 4) {
        // If trump suit is unset 
        if (trump_suit == 4) {
            trump_suit = player1trumpcount;
        }

        cout << "\nThe trump that was chosen was: ";
        cout << trump_suit;

        player_one_chosen = true;

        return player1;
    }

    if (player2trumpcount != 4) {

        if (trump_suit == 4) {
            trump_suit = player2trumpcount;
        }

        cout << "\nThe trump that was chosen was: ";
        cout << trump_suit;

        player_two_chosen = true;

        return player2;
    }

    if (player3trumpcount != 4) {
        if (trump_suit == 4) {
            trump_suit = player3trumpcount;
        }

        cout << "\nThe trump that was chosen was: ";
        cout << trump_suit;

        player_three_chosen = true;

        return player3;
    }

    if (player4trumpcount != 4) {
        if (trump_suit == 4) {
            trump_suit = player4trumpcount;
        }

        cout << "\nThe trump that was chosen was: ";
        cout << trump_suit;

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
    // This is from when players played independently and not on teams 
    // Dont want to get rid of it im feeling a little sentimental

    int playercard_index = player.choose_card(chosen_suit, trump_suit, false);
    Card playercard = player.hand[playercard_index];
    int playervalue = playercard.Value;
    int playersuit = playercard.Suit;

    update_highest_value(playervalue, playersuit);
    player.remove_card_from_hand(playercard_index);
}

void Match::one_player_on_team_play(int playerID, int teamID) {
    // Player on a specific team makes their move
    // We are using indexes instead of card instances since I need the index
    // anyways to remove the card from the player's hand

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
    // How to get a card from a team player from just an index 
    
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
    // Testing
    cout << "\nPlayer ";
    cout << player_highest;
    cout << " won the hand!\n";
}

void Match::update_results() {
    // Defenders have even number IDs, makers have odd
    if (player_highest % 2 == 0) {
        defenders_won = true;
    }

    if (defenders_won) {
        cout << "\n The defenders won the round!";
        defenders.score++;
    }
    else {
        makers.score++;
    }
}

void Match::end_game() {
    if (defenders.score >= 3) {
        cout << "\nThe defenders won the game!";
    }
    else {
        cout << "\nThe makers won the game!";
    }

    makers.score = 0;
    defenders.score = 0;
}