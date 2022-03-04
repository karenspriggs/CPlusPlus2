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

void Team::add_player(Player p, int playerID) {
    if (playerID == 1) {
        player1 = p;
    }
    else {
        player2 = p;
    }
}

Card Team::team_players_play(int playerID, int chosen_suit, int trump_suit) {
    bool aceplayed = (highest_played == 14);
    Card playercard;

    if (playerID == 1) {
        Card playercard = one_player_team_play(player1, chosen_suit, trump_suit, aceplayed);
    }
    else {
        Card playercard = one_player_team_play(player2, chosen_suit, trump_suit, aceplayed);
    }
}

Card Team::one_player_team_play(Player& player, int playerID, int chosen_suit, int trump_suit) {
    int playercard_index = player.choose_card(chosen_suit, trump_suit, false);
    Card playercard = player.hand[playercard_index];
    int playervalue = playercard.Value;

    update_highest_value(playervalue);
    player.remove_card_from_hand(playercard_index);
}

void Team::update_highest_value(int playervalue) {
    highest_played = playervalue;
}