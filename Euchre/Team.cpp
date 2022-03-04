#include <stdio.h>
#include <stdlib.h>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include "Team.h"
#include "Player.h"

using namespace Euchre;

Team::Team() {
    is_defender = false;
    played_trump = false;
    highest_played = 0;
    score = 0;
}

bool Team::check_win(int score) {
    if (is_defender && score >= 2) {
        return true;
    }
    else {
        if (!is_defender && score >= 3) {
            return true;
        }
    }
    return false;
}

void Team::add_player(Player& p, int playerID) {
    if (playerID == 1) {
        player1 = p;
    }
    else {
        player2 = p;
    }
}

int Team::team_players_play(int playerID, int chosen_suit, int trump_suit) {
    aceplayed = (highest_played == 14);
    int playercardindex;

    if (playerID == 1) {
        playercardindex = one_player_team_play(playerID, chosen_suit, trump_suit);
    }
    else {
        playercardindex = one_player_team_play(playerID, chosen_suit, trump_suit);
    }

    return playercardindex;
}

int Team::one_player_team_play(int playerID, int chosen_suit, int trump_suit) {
    Player player;

    if (playerID == 1) {
        player = player1;
    }
    else {
        player = player2;
    }
    
    int playercard_index = player.choose_card(chosen_suit, trump_suit, aceplayed);
    Card playercard = player.hand[playercard_index];
    int playervalue = playercard.Value;

    update_highest_value(playervalue);
    player.remove_card_from_hand(playercard_index);

    return playercard_index;
}

void Team::remove_card_at_index(int playerID, int index) {

    if (playerID == 1) {
        player1.remove_card_from_hand(index);
    }
    else {
        player2.remove_card_from_hand(index);
    }
}

void Team::update_highest_value(int playervalue) {
    highest_played = playervalue;
}

Card Team::return_card_at_index(int playerID, int index) {
    Card playercard;

    if (playerID == 1) {
        playercard = player1.hand[index];
    }
    else {
        playercard = player2.hand[index];
    }

    return playercard;
}