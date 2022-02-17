#include "Team.h"
#include "Deck.h"

namespace Euchre
{
    class Match{
    public:
        Team team1;
        Team team2;
        Deck deck;
        void play_round();
        void play_game();
    };
}
