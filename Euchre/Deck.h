#pragma once
#include "Card.h"
#include "Player.h"

namespace Euchre
{
    class Deck {
        Card cards[24];
    public:
        void shuffle();
        void allocate();
        void add_cards();
        void fill_hand(Player player, int index);
        Card draw_card(int index);
        Deck();
    };
}