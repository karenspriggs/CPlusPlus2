#pragma once;
#include "Card.h"
#include "Deck.h"

namespace Euchre
{
    class Player{
    public:
        Card* hand;
        Player(){

        }
        void allocate_hand();
        void update_score();
        void add_card(Card card, int index);
        int choose_suit();
        Card choose_card();
    };
}