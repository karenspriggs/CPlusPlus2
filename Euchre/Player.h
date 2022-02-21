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
        bool check_for_trump(int trumpsuit);
        bool check_for_current(int currentsuit);
        int pick_suit_to_play(int currentsuit, int trumpsuit);
        int pick_card_to_play(int highest_current, int highest_trump);
        Card find_general_highest();
        Card find_highest(int suit);
        Card choose_card(int currentsuit, int trumpsuit);
    };
}