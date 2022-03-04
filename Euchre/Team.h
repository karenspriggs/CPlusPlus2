#pragma once
#include "Player.h"

namespace Euchre
{
    class Team {
        Player player1;
        Player player2;
    public:
        bool is_defender;
        bool played_trump;
        bool aceplayed = false;
        int score = 0;
        int highest_played = 0;
        
        Team();
        Card return_card_at_index(int playerID, int index);
        void add_player(Player& player, int playerID);
        bool check_win(int score);
        int one_player_team_play(int playerID, int chosen_suit, int trump_suit);
        int team_players_play(int playerID, int chosen_suit, int trump_suit);
        void remove_card_at_index(int playerID, int index);
        void update_highest_value(int playervalue);
    };
}