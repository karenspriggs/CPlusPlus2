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
        int player_highest = 0;
        bool defenders_won = false;
        Match();
        void setup();
        void fill_hands();
        void make_teams();
        void play_round();
        void choose_suit();
        void one_player_play(Player& player);
        void update_highest(Card card);
        void play_game();
        void end_game();
    };
}
