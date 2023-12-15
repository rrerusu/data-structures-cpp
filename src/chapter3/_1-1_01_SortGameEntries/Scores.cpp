#include "Scores.h"

Scores::Scores(int maxEnt = 10) : maxEntries(maxEnt), numEntries(0) {
    entries = new GameEntry[maxEntries];
}

Scores::~Scores() {
    delete[] entries;
}

void Scores::add(const GameEntry & e) {
    int newScore = e.getScore();
    if(numEntries == maxEntries && newScore <= entries[numEntries - 1].getScore())
        return ;
    else
        numEntries++;
    
    int i = numEntries - 2;
    while(i >= 0 && newScore > entries[i].getScore()) {
        entries[i + 1] = entries[i];
        i--;
    }
    entries[i + 1] = e;
}

GameEntry Scores::remove(int i) {
    if((i < 0) || (i >= numEntries))
        throw IndexOutOfBounds("Invalid index");
    GameEntry e = entries[i];
    for(int j = i + 1; j < numEntries; j++)
        entries[j - 1] = entries[j];
    numEntries--;
    return e;
    
}

std::string Scores::toString() {
    std::string output = "Entries\n";
    for(int i = 0; i < numEntries; i++)
        output += entries[i].toString();
    return output;
}