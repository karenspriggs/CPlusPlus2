#pragma once
#include "Card.h"

namespace Euchre
{
    class Player {
    public:
        Card hand[5];
        Player();
        void allocate_hand();
        void update_score();
        void add_card(int suit, int value, int index);
        int find_highest_index();
        int find_highest_suit_specific(int suit);
        int choose_suit();
        int choose_trump(int amount);
        bool check_for_trump(int trumpsuit);
        bool check_for_current(int currentsuit);
        int pick_suit_to_play(int currentsuit, int trumpsuit);
        int pick_card_to_play(int highest_current, int highest_trump);
        void remove_card_from_hand(int index);
        int find_general_highest();
        int find_highest(int suit);
        int choose_card(int currentsuit, int trumpsuit, bool partnerace);
    };
}