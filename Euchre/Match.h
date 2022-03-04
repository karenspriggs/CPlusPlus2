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
        int trump_suit = 4;
        int makersplayercount = 0;
        int current_highest = 0;
        int current_highest_suit = 5;
        int player_highest = 0;
        int current_player_id = 0;
        bool defenders_won = false;
        bool player_one_chosen = false;
        bool player_two_chosen = false;
        bool player_three_chosen = false;
        bool player_four_chosen = false;
        Match();
        void setup();
        void fill_hands();
        void determine_teams();
        Player find_first_maker();
        Player find_second_maker();
        void make_defenders();
        void play_round();
        void choose_suit();
        void one_player_play(Player& player);
        void one_player_on_team_play(int playerID, int teamID);
        Card get_card_from_team(int teamID, int playerID, int index);
        void update_highest_value(int value, int suit);
        bool overwrite_highest_value_suit(int suit1, int suit2);
        void play_game();
        void show_results();
        void end_game();
    };
}
