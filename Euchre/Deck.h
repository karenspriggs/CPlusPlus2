#pragma once
#include "Card.h"
#include "Player.h"
#include "Shuffler.h"

namespace Euchre
{
    class Deck {
        Card cards[24];
        Shuffler shuffler;
    public:
        void shuffle();
        void add_cards();
        void fill_hand(Player& player, int index);
        Card draw_card(int index);
        Deck();
    };
}