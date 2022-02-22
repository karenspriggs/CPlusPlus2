#pragma once

namespace Euchre
{
    class Card{
    public:
        Card();
        Card(int value, int suit);
        int Suit;
        int Value;
        void Describe();
    };
}