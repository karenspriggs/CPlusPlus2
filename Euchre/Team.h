#pragma once
#include "Player.h"

namespace Euchre
{
    class Team {
    public:
        bool is_defender;
        bool played_trump;
        int score = 0;
        int highest_played = 0;
        Player player1;
        Player player2;
        Team();
        void add_player(Player player, int playerID);
        bool check_win(int score);
        Card one_player_team_play(Player& player, int playerID, int chosen_suit, int trump_suit);
        Card team_players_play(int playerID, int chosen_suit, int trump_suit);
        void update_highest_value(int playervalue);
    };
}