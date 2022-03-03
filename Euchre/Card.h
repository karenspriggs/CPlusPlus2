#pragma once

namespace Euchre
{
    class Card {
    public:
        Card();
        Card(int value, int suit);
        int Suit = 0;
        int Value = 0;
        void Describe();
    };
}