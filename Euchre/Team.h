#pragma once
#include "Player.h"

namespace Euchre
{
    class Team{
    public:
        bool is_defender;
        int score;
        Player player1;
        Player player2;
        Team();
        void add_player(Player player);
        bool check_win(int score);
    };
}