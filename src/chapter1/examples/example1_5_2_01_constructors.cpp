#include <cstdlib>
#include <iostream>

enum MealType {NO_PREF, REGULAR, LOW_FAT, VEGETARIAN};

class Passenger {
    private:
        std::string name;
        MealType mealPref;
        bool isFreqFlyer;
        std::string freqFlyerNo;
    public:
        Passenger();
        Passenger(const std::string& nm, MealType mp, const std::string& ffn = "NONE");
        Passenger(const Passenger& pass);       // copy constructor
        void display();
};

Passenger::Passenger() {
    name = "--NO NAME--";
    mealPref = NO_PREF;
    isFreqFlyer = false;
    freqFlyerNo = "NONE";
}

Passenger::Passenger(const std::string& nm, MealType mp, const std::string& ffn) {
    name = nm;
    mealPref = mp;
    isFreqFlyer = {ffn != "NONE"};
    freqFlyerNo = ffn;
}

Passenger::Passenger(const Passenger& pass) {
    name = pass.name;
    mealPref = pass.mealPref;
    isFreqFlyer = pass.isFreqFlyer;
    freqFlyerNo = pass.freqFlyerNo;
}

void Passenger::display() {
    std::cout << "Name: " << this->name << "\nMealPref: " << this->mealPref << "\nIsFreqFlyer" << this->isFreqFlyer << "\nFreqFlyerNo: " << this->freqFlyerNo << std::endl << std::endl;
}

int main() {
    Passenger p1;
    Passenger p2("John Smith", VEGETARIAN, "293145");
    Passenger p3("Pocahontas", REGULAR);
    Passenger p4(p3);
    Passenger p5 = p2;
    Passenger* pp1 = new Passenger;
    Passenger* pp2 = new Passenger("John Blow", NO_PREF);
    Passenger pa[20];

    p1.display();
    p2.display();
    p3.display();
    p4.display();
    p5.display();
    pp1->display();
    pp2->display();

    std::cout << "\nEntering loop:" << std::endl;
    for(int i = 0; i < 20; i++) {
        pa[i].display();
    }

    return EXIT_SUCCESS;
}