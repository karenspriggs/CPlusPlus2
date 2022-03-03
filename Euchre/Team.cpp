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

void Team::add_player(Player p) {
    // Add player to team by copying over all their shit? idk
    // Doesn't work like C#
}

void one_team_player_play(Player player) {
    Card playercard;
    // Have to get the player one working 100% for this one to get started
    // 
    //  This checks to see if the other team member played an ace
    // bool aceplayed = (highest_played == 14);
    // playercard = player.choose_card(chosen_suit, trump_suit, aceplayed);
    // 
    // cant trump a partners ace: if curent team highest is 13 then they have to do a non trump
    // Check if highest played is 0, if so then set it equal to the played card value
}