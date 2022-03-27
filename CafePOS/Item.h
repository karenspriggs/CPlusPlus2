namespace CafePOS{
    class Item{
        public:
        char Name[10];
        double Price;
        Item();
        Item(char name[], double price);
        void Describe();
    };
}