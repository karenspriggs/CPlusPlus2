#include "Team.h"
#include "Deck.h"

namespace Euchre
{
    class Match{
    public:
        int chosen_suit;
        bool defenders_won;
        Team team1;
        Team team2;
        Deck deck;
        Match();
        void setup();
        void fill_hands();
        void play_round();
        void choose_suit();
        void play_game();
        void end_game();
    };
}
