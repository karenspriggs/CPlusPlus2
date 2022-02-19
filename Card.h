#pragma once;

namespace Euchre
{
    class Card{
    public:
        int Suit;
        int Value;
        char* Describe();
        Card(int value, int suit);
    };
}