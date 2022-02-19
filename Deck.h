#include "Card.h"

namespace Euchre
{
    class Deck{
    Card* cards;
    public:
        void allocate();
        void add_cards();
        Card draw_card(int index);
        Deck();
    };
}