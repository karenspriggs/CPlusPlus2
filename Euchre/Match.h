#include "Team.h"
#include "Deck.h"
#include "Player.h"

namespace Euchre
{
    class Match {
        Team makers;
        Team defenders;
        Player player1;
        Player player2;
        Player player3;
        Player player4;
        Deck deck;
    public:
        int chosen_suit = 1;
        int trump_suit = 0;
        int current_highest = 0;
        int current_highest_suit = 5;
        int player_highest = 0;
        int current_player_id = 0;
        bool defenders_won = false;
        Match();
        void setup();
        void fill_hands();
        void determine_trump();
        void add_member_to_team(Player player, Team team);
        void play_round();
        void choose_suit();
        void one_player_play(Player& player);
        void update_highest_value(int value, int suit);
        bool overwrite_highest_value_suit(int suit1, int suit2);
        void play_game();
        void show_results();
        void end_game();
    };
}
