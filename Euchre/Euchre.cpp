#include <stdio.h>
#include <stdlib.h>
#include <cstdlib>
#include <ctime>
#include <iostream>

#include "Match.h"

using namespace Euchre;

Match* match = new Match();

void play_hundred() {
    for (int i = 0; i < 100; i++) {
        match->play_game();
    }
}

int main() {
    //match->play_game();
    // Run this to feel like a nuke has gone off in the console
    play_hundred();
}