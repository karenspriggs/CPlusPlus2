#pragma once
#include "Player.h"

namespace Euchre
{
    class Team{
    public:
        bool is_defender;
        bool played_trump;
        int score;
        int highest_played;
        Player player1;
        Player player2;
        Team();
        void add_player(Player player);
        bool check_win(int score);
        void one_team_player_play(Player player);
    };
}