#pragma once;

namespace Euchre
{
    class Player{
    public:
        Card* hand;
        Player(){

        }
        void allocate_hand();
        void update_score();
        int choose_suit();
        Card choose_card();
    };
}