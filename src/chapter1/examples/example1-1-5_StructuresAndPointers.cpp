#include <cstdlib>
#include <iostream>

enum MealType {NO_PREF, REGULAR, LOW_FAT, VEGETARIAN};

struct Passenger {
    std::string      name;                      // passenger name
    MealType         mealPref;                  // meal preference
    bool             isFreqFlyer;               // in the frequent flyer program?
    std::string      freqFlyerNo;               // the passenger's freq. flyer number
};

int main() {
    Passenger pass = {"John Smith", VEGETARIAN, true, "293145"};
    pass.name = "Pocahontas";
    pass.mealPref = REGULAR;

    Passenger *p;
    p = new Passenger;
    p->name = "Pocahontas";
    p->mealPref = REGULAR;
    p->isFreqFlyer = false;
    p->freqFlyerNo = "NONE";

    delete p;

    return EXIT_SUCCESS;
}