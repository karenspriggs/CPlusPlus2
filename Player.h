namespace Euchre
{
    class Player{
        public:
            Card* hand;
            int score;
            Player()
            void update_total(int value);
            int make_choice();
            int make_choice_dealer();
    };
}