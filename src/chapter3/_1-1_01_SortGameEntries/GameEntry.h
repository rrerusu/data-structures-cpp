#include <iostream>

#pragma once

class GameEntry {
    public:
        GameEntry(const std::string & n = "", int s = 0) : name(n), score(s) {}
        std::string getName() const { return name; }
        int getScore() const { return score; }
        std::string toString() {
            return name + ": " + std::to_string(score) + "\n";
        }
    private:
        std::string name;
        int score;
};