#include <stdio.h>
#include <stdlib.h>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include "Team.h"
#include "Player.h"

using namespace Euchre;

Team::Team(){
    is_defender = false;
    played_trump = false;
    highest_played = 0;
    score = 0;
}

bool Team::check_win(int score){
    if (is_defender && score >= 2){
        return true;
    } else {
        if (!is_defender && score >= 3){
            return true;
        }
    }
    return false;
}

void Team::add_player(Player p){

}

void one_team_player_play(Player player){
    Card playercard;
    //bool aceplayed = (highest_played == 13);
    //playercard = player.choose_card(chosen_suit, trump_suit, aceplayed);
    // cant trump a partners ace: if curent team highest is 13 then they have to do a non trump
    // cant 
}