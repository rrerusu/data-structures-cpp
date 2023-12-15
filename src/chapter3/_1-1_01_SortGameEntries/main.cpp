#include "Scores.h"
#include "GameEntry.h"

int main() {
    GameEntry entry1("Mike", 1105);
    GameEntry entry2("Rob", 750);
    GameEntry entry3("Paul", 720);
    GameEntry entry4("Anna", 660);
    GameEntry entry5("Rose", 590);
    GameEntry entry6("Jack", 510);

    Scores myScores(10);

    myScores.add(entry1);
    myScores.add(entry2);
    myScores.add(entry3);
    myScores.add(entry4);
    myScores.add(entry5);
    myScores.add(entry6);

    std::cout << myScores.toString() << std::endl;

    return EXIT_SUCCESS;
}