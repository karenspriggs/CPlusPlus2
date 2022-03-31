#pragma once
class ChangeManager {
    int penny_count = 0;
    int nickel_count = 0;
    int dime_count = 0;
    int quarter_count = 0;
    int dollar_count = 0;
    double uncalculated_total = 0;
public:
    void set_change_amount(double amount);
    void determine_change();
    void check_if_done();
    void print_change_amount();
    ChangeManager();
};