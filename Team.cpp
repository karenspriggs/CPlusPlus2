#include <stdio.h>
#include <stdlib.h>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include "Team.h"
#include "Player.h"

using namespace Euchre;



Team::Team(){

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