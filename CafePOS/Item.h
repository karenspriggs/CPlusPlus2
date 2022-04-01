#pragma once
using namespace std;

namespace CafePOS{
    class Item {
    public:
        string Name;
        double Price;
        Item();
        Item(string name, double price);
        void Describe();
    };
}