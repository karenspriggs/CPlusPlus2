namespace Euchre
{
    class Deck{
    Card* cards;
    public:
        void allocate();
        void add_cards();
        Card get_card();
        Deck();
    };
}